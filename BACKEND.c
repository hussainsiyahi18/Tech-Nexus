#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include <ctype.h>

struct Laptop {
    int id;
    char name[50];
    int price;
    int brand;
    int usage;   // THE LOGIC FILTER: 1=Gaming, 2=Student, 3=Coding
    int ram;     // FOR DISPLAY
    int storage; // FOR DISPLAY
};

struct Phone {
    int id;
    char name[50];
    int price;
    int brand;
    int os;
    int usage;   // THE LOGIC FILTER: 1=Camera, 2=Battery, 3=Performance
    int ram;     // FOR DISPLAY
    int storage; // FOR DISPLAY
    int camera;  // FOR DISPLAY
    int battery; // FOR DISPLAY
};

struct Result {
    struct Device dev;
    int score;
};

void lst_of_all(int type, int budget, char* usage_csv, char* brand_csv, char* hw_filter, char* storage_filter);
void recommendLaptop(struct Laptop db[]);
void recommendPhone(struct Phone db[]);
void printLaptopRow(struct Laptop l);
void printPhoneRow(struct Phone p);


void to_low(char* dest, char* src) {
    int i;
    for(i = 0; src[i]; i++) dest[i] = tolower(src[i]);
    dest[i] = '\0';
}

// Logic: Checks if ANY of the user's selected brands match the device
int matches_checklist(char* device_val, char* filter_csv) {
    if (strcmp(filter_csv, "0") == 0 || strlen(filter_csv) == 0) return 1;

    char d_low[500], f_low[500];
    to_low(d_low, device_val);
    to_low(f_low, filter_csv);

    // Split "asus,hp" into "asus" and "hp" and check individually
    char *token = strtok(f_low, ",");
    while (token != NULL) {
        if (strstr(d_low, token) != NULL) return 1; 
        token = strtok(NULL, ",");
    }
    return 0; 
}

void lst_of_all(int type, int budget, char* usage_csv, char* brand_csv, char* hw_filter, char* storage_filter) {
    struct Result results[10];
    int found = 0;
    int limit = (type == 1) ? LAPTOP_COUNT : MOBILE_COUNT;

    for (int i = 0; i < limit && found < 10; i++) {
        struct Device current = (type == 1) ? laptops_db[i] : mobiles_db[i];

        if (current.price > 0 && (current.price <= budget || budget == 0)) {
            char brand_temp[500], usage_temp[500];
            strcpy(brand_temp, brand_csv);
            strcpy(usage_temp, usage_csv);

            int brand_match = matches_checklist(current.name, brand_temp);

            char* usage_name = (type == 1) ?
                (current.category == 1 ? "gaming" : current.category == 3 ? "coding" : "office") :
                (current.category == 1 ? "camera" : current.category == 2 ? "battery" : "speed");
            int usage_match = matches_checklist(usage_name, usage_temp);

            int hw_match = (strcmp(hw_filter, "0") == 0 || strstr(current.specs, hw_filter));
            int storage_match = (strcmp(storage_filter, "0") == 0 || strstr(current.specs, storage_filter));

            if (brand_match && usage_match && hw_match && storage_match) {
                int score = 0;

                // Value for money
                if (budget > 0)
                    score += (int)((float)(budget - current.price) / budget * 10);

                // Usage match bonus
                if (strcmp(usage_csv, "0") != 0 && usage_match)
                    score += 3;

                // Spec bonuses
                if (strstr(current.specs, "32GB") || strstr(current.specs, "16GB")) score += 2;
                if (strstr(current.specs, "1TB") || strstr(current.specs, "512GB")) score += 1;

                results[found].dev = current;
                results[found].score = score;
                found++;
            }
        }
    }

    // Sort by score (highest first)
    for (int i = 0; i < found - 1; i++) {
        for (int j = 0; j < found - i - 1; j++) {
            if (results[j].score < results[j+1].score) {
                struct Result temp = results[j];
                results[j] = results[j+1];
                results[j+1] = temp;
            }
        }
    }

    // Print sorted results
    for (int i = 0; i < found; i++) {
        printf("1. Model Name - %s\n2. Price - %d\n3. Specs - %s\n----------------\n",
               results[i].dev.name, results[i].dev.price, results[i].dev.specs);
    }

    if (found == 0)
        printf("No results found. Try adjusting your filters.\n");
}


int main(int argc, char *argv[]) {
    if (argc >= 7) {
        // Correctly handling mixed int and string arguments
        int type = atoi(argv[1]);
        int budget = atoi(argv[2]);
        char* usage_filter = argv[3];
        char* brand_filter = argv[4];
        char* hw_filter = argv[5];
        char* storage_filter = argv[6];
        
        lst_of_all(type, budget, usage_filter, brand_filter, hw_filter, storage_filter);
    } 
    return 0;
}

void recommendLaptop(struct Laptop db[]) {
    int i, l_budget, l_usage, count = 0, brand_prefference;
        printf("\nWhat's the budget for your laptop? (In rupees): ");
        scanf("%d", &l_budget);
        printf("\nChoose your primary usage: 1. Gaming, 2. Student/office work/daily life, 3. Programming, Enter choice (0 for All): ");
        scanf("%d", &l_usage);
        printf("\nDo you have any brand preference? \n1. Asus \n2. HP \n3. Lenovo \n4. Dell \n5. Acer \n6. Samsung \n7. MSI \nEnter choice (0 for All): ");
        scanf("%d", &brand_prefference);
            for (i = 0; i <= 14; i++) {
                if (db[i].id == 0) {
                    continue; // it was giving weird output, so I added this to avoid the empty structs in the array
                }
                if (db[i].price <= l_budget && (db[i].usage == l_usage || l_usage == 0) && (db[i].brand == brand_prefference || brand_prefference == 0)) {
                    printLaptopRow(db[i]);
                    count++;
                }
                }
            if (count == 0) {
                printf("Sorry, we coudn't find your desired laptop. Change the filters and try again :)");
            }
                    
}

void printLaptopRow(struct Laptop l) {
    printf("\n1. Model Name - %s \n2. Price - %d \n3. RAM - %d \n4. Storage - %d \n \n", l.name, l.price, l.ram, l.storage);

}


void recommendPhone(struct Phone db[]) {
    int i, p_budget, p_usage, os_choice, p_prefference, count = 0;
        printf("\nWhat's the budget for your phone? (In rupees): ");
        scanf("%d", &p_budget);
        printf("\nWhat is your top priority? \n1. Best Camera Quality \n2. Longest Battery Life \n3. High Performance / Gaming \nEnter choice (0 for All): ");
        scanf("%d", &p_usage);
        printf("\nDo you want an \n1. Andriod \n2. Ios \nEnter choice (0 for All): ");
        scanf("%d", &os_choice);
        printf("\nDo you have any brand preference? \n1. Poco \n2. Realme \n3. Redmi \n4. Oppo \n5. Motorola \n6. Samsung \n7. Apple \n8. OnePlus \n9. Xiaomi \nEnter choice (0 for All): ");
        scanf("%d", &p_prefference);
            for (i = 0; i <= 14; i++) {
                if (db[i].id == 0) {
                    continue; // it was giving weird output, so I added this to avoid the empty structs in the array
                }
                if (db[i].price <= p_budget && (db[i].usage == p_usage || p_usage == 0) && (db[i].os == os_choice || os_choice == 0) && (db[i].brand == p_prefference || p_prefference == 0)) {
                    printPhoneRow(db[i]);
                    count++;
                }
                }
            if (count == 0) {
                printf("Sorry, we coudn't find your desired Phone. Change the filters and try again :)");
            }
                    
}

void printPhoneRow(struct Phone p){
    printf("\n1. Model Name - %s \n2. Price - %d \n3. RAM - %d \n4. Storage - %d \n5. Camera - %d \n6. Battery - %d \n \n", p.name, p.price, p.ram, p.storage, p.camera, p.battery);

}
