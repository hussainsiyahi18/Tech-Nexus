#include <stdio.h>
#include <string.h>

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

void lst_of_all(struct Laptop l[], struct Phone p[]);
void recommendLaptop(struct Laptop db[]);
void recommendPhone(struct Phone db[]);
void printLaptopRow(struct Laptop l);
void printPhoneRow(struct Phone p);

int main() {
    struct Laptop laptopDB[15]; 
    struct Phone phoneDB[15];
    int ch; 

    lst_of_all(laptopDB, phoneDB);
    do {
    printf("\n--- MAIN MENU ---\n");
    printf("1. Find a Laptop");
    printf("\n2. Find a Phone");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    
    scanf("%d", &ch);

    switch(ch) {
        case 1: 
            recommendLaptop(laptopDB); 
            break;
        
        case 2: 
            recommendPhone(phoneDB); 
            break;
        
        case 3: 
            printf("\nExiting"); 
            break;

        default: 
            printf("\nInvalid choice! Try again");
    }

} while (ch != 3);

    return 0;
}

void lst_of_all(struct Laptop l[], struct Phone p[]) {
    
    // ===== BUDGET LAPTOPS =====
    l[0].id = 1;
    strcpy(l[0].name, "ASUS Vivobook Go 15");
    l[0].price = 38000;
    l[0].brand = 1;   // ASUS = 1
    l[0].usage = 2;   // 
    l[0].ram = 8;
    l[0].storage = 512;

    l[1].id = 2;
    strcpy(l[1].name, "HP 15s");
    l[1].price = 48000;
    l[1].brand = 2;   // HP = 2
    l[1].usage = 2;
    l[1].ram = 8;
    l[1].storage = 512;

    l[2].id = 3;
    strcpy(l[2].name, "Lenovo IdeaPad Slim 3");
    l[2].price = 42000;
    l[2].brand = 3;    // LENOVO = 3
    l[2].usage = 2;
    l[2].ram = 8;
    l[2].storage = 512;

    l[3].id = 4;
    strcpy(l[3].name, "Dell Inspiron 15 3505");
    l[3].price = 33000;
    l[3].brand = 4;   // DELL = 4
    l[3].usage = 2;
    l[3].ram = 8;
    l[3].storage = 512;

    l[4].id = 5;
    strcpy(l[4].name, "Acer Aspire 3");
    l[4].price = 38000;
    l[4].brand = 5;   // ACER = 5
    l[4].usage = 2;
    l[4].ram = 8;
    l[4].storage = 512;


    // ===== MID RANGE =====

    l[5].id = 6;
    strcpy(l[5].name, "Samsung Galaxy Book4");
    l[5].price = 54000;
    l[5].brand = 6;  // SAMSUNG = 6
    l[5].usage = 3;  // 3 = programming
    l[5].ram = 16;
    l[5].storage = 512;

    l[6].id = 7;
    strcpy(l[6].name, "Acer Swift Go 14");
    l[6].price = 79000;
    l[6].brand = 5; // ACER = 5
    l[6].usage = 3; // 3 = programming
    l[6].ram = 16;
    l[6].storage = 1000;

    l[7].id = 8;
    strcpy(l[7].name, "Lenovo ThinkPad E14");
    l[7].price = 60000;
    l[7].brand = 3; // LENOVO = 3
    l[7].usage = 3; // 3 = programming
    l[7].ram = 16;
    l[7].storage = 512;

    l[8].id = 9;
    strcpy(l[8].name, "HP Pavilion 14");
    l[8].price = 60000;
    l[8].brand = 2; // HP = 2
    l[8].usage = 3; // 3 = programming
    l[8].ram = 16;
    l[8].storage = 512;

    l[9].id = 10;
    strcpy(l[9].name, "ASUS Vivobook S");
    l[9].price = 56000;
    l[9].brand = 1; // ASUS = 1
    l[9].usage = 3; // 3 = programming
    l[9].ram = 16;
    l[9].storage = 512;


    // ===== GAMING / HIGH END =====

    l[10].id = 11;
    strcpy(l[10].name, "Lenovo LOQ 15");
    l[10].price = 85000;
    l[10].brand = 3; // LENOVO = 3
    l[10].usage = 1; // 1 = gaming
    l[10].ram = 16;
    l[10].storage = 512;

    l[11].id = 12;
    strcpy(l[11].name, "ASUS TUF F16");
    l[11].price = 97000;
    l[11].brand = 1;   // ASUS = 1
    l[11].usage = 1;  // 1 = gaming
    l[11].ram = 16;
    l[11].storage = 512;

    l[12].id = 13;
    strcpy(l[12].name, "MSI Katana A15");
    l[12].price = 97000;
    l[12].brand = 7;   // MSI = 7
    l[12].usage = 1; // 1 = gaming
    l[12].ram = 16;
    l[12].storage = 512;

    l[13].id = 14;
    strcpy(l[13].name, "Acer Nitro 16");
    l[13].price = 80000;
    l[13].brand = 5; // ACER = 5
    l[13].usage = 1; // 1 = gaming
    l[13].ram = 16;
    l[13].storage = 512;

    l[14].id = 15;
    strcpy(l[14].name, "Acer Predator Helios Neo 16");
    l[14].price = 155000;
    l[14].brand = 5; // ACER = 5
    l[14].usage = 1; // 1 = gaming
    l[14].ram = 32;
    l[14].storage = 1000;

// ===== BUDGET PHONES (UNDER 20K) =====

    p[0].id = 1;
    strcpy(p[0].name, "Poco M7 Pro 5G");
    p[0].price = 13499;
    p[0].brand = 1;      // 1=Poco
    p[0].os = 1;        // 1=Android
    p[0].ram = 6;
    p[0].camera = 50;
    p[0].storage = 128;
    p[0].battery = 5110;
    p[0].usage = 1;

    p[1].id = 2;
    strcpy(p[1].name, "Realme Narzo 80 Lite 5G");
    p[1].price = 11249;
    p[1].brand = 2;      // 2=Realme
    p[1].os = 1;         // 1=Android
    p[1].ram = 6;
    p[1].camera = 50;
    p[1].storage = 128;
    p[1].battery = 5000;
    p[1].usage = 2;        // 3=Basic/ Budget users

    p[2].id = 3;
    strcpy(p[2].name, "Redmi 15C 5G");
    p[2].price = 12499;
    p[2].brand = 3;      // 3=Redmi
    p[2].os = 1;         // 1=Android
    p[2].ram = 4;
    p[2].camera = 50;
    p[2].storage = 128;
    p[2].battery = 5000;
    p[2].usage = 3;  // 3=Basic/ Budget users

    p[3].id = 4;
    strcpy(p[3].name, "Oppo K13x 5G");
    p[3].price = 12499;
    p[3].brand = 4;      // 4=Oppo
    p[3].os = 1;         // 1=Android
    p[3].ram = 6;
    p[3].camera = 50;
    p[3].storage = 128;
    p[3].battery = 6000;
    p[3].usage = 2;        

    p[4].id = 5;
    strcpy(p[4].name, "Motorola G64 5G");
    p[4].price = 14999;
    p[4].brand = 5;      // 5=Motorola
    p[4].os = 1;         // 1=Android
    p[4].ram = 6;
    p[4].camera = 50;
    p[4].storage = 64;
    p[4].battery = 6000;
    p[4].usage = 2;        


    // ===== MID RANGE PHONES (30K-70K) =====

    p[5].id = 6;
    strcpy(p[5].name, "Samsung Galaxy S24 5G");
    p[5].price = 65000;
    p[5].brand = 6;      // 6=Samsung
    p[5].os = 1;        // 1=Android
    p[5].ram = 8;
    p[5].camera = 50;
    p[5].storage = 256;
    p[5].battery = 4000;
    p[5].usage = 1;        

    p[6].id = 7;
    strcpy(p[6].name, "Oppo Reno15 Pro 5G");
    p[6].price = 67999;
    p[6].brand = 4;      // 4=Oppo
    p[6].os = 1;         // 1=Android
    p[6].ram = 12;
    p[6].camera = 200;
    p[6].storage = 256;
    p[6].battery = 5000;
    p[6].usage = 3;        

    p[7].id = 8;
    strcpy(p[7].name, "iPhone 15");
    p[7].price = 54900;
    p[7].brand = 7;      // 7=Apple
    p[7].os = 2;         // 2=iOS
    p[7].ram = 6;
    p[7].camera = 48;
    p[7].storage = 128;
    p[7].battery = 3279;
    p[7].usage = 1;        

    p[8].id = 9;
    strcpy(p[8].name, "Realme 16 Pro 5G");
    p[8].price = 32999;
    p[8].brand = 2;      // 2=Realme
    p[8].os = 1;         // 1=Android
    p[8].ram = 8;
    p[8].camera = 200;
    p[8].storage = 128;
    p[8].battery = 7000;
    p[8].usage = 2;        

    p[9].id = 10;
    strcpy(p[9].name, "OnePlus Nord 5 5G");
    p[9].price = 35000;
    p[9].brand = 8;      // 8=OnePlus
    p[9].os = 1;         // 1=Android
    p[9].ram = 8;
    p[9].camera = 50;
    p[9].storage = 256;
    p[9].battery = 6800;
    p[9].usage = 2;        

    // ===== HIGH RANGE PHONES ( ABOVE 70K) =====

    p[10].id = 11;
    strcpy(p[10].name, "Apple iPhone 17 Pro");
    p[10].price = 134900;
    p[10].brand = 7;      // 7=Apple
    p[10].os = 2;        // 2=iOS
    p[10].ram = 12;
    p[10].camera = 48;
    p[10].storage = 256;
    p[10].battery = 3988;
    p[10].usage = 1;        

    p[11].id = 12;
    strcpy(p[11].name, "Samsung Galaxy S25 Ultra");
    p[11].price = 119999;
    p[11].brand = 6;      // 6=Samsung
    p[11].os = 1;         // 1=Android
    p[11].ram = 12;
    p[11].camera = 200;
    p[11].storage = 256;
    p[11].battery = 5000;
    p[11].usage = 1;        

    p[12].id = 13;
    strcpy(p[12].name, "Google Pixel 10 Pro");
    p[12].price = 124999;
    p[12].brand = 8;      // 8=Google
    p[12].os = 1;         // 1=Android
    p[12].ram = 16;
    p[12].camera = 50;
    p[12].storage = 256;
    p[12].battery = 4870;
    p[12].usage = 1;        

    p[13].id = 14;
    strcpy(p[13].name, "Xiaomi 15 Ultra");
    p[13].price = 109999;
    p[13].brand = 9;      // 9=Xiaomi
    p[13].os = 1;         // 1=Android
    p[13].ram = 16;
    p[13].camera = 50;
    p[13].storage = 512;
    p[13].battery = 5410;
    p[13].usage = 3;        

    p[14].id = 15;
    strcpy(p[14].name, "OnePlus 12 Pro ");
    p[14].price = 85000;
    p[14].brand = 8;      // 8=OnePlus
    p[14].os = 1;         // 1=Android
    p[14].ram = 16;
    p[14].camera = 50;
    p[14].storage = 512;
    p[14].battery = 5500;
    p[14].usage = 3;        
}

void recommendLaptop(struct Laptop db[]) {
    int i, l_budget, l_usage, count = 0;
        printf("\nWhat's the budget for your laptop? (In rupees): ");
        scanf("%d", &l_budget);
        printf("\nChoose your primary usage: 1. Gaming, 2. Student/office work/daily life, 3. Programming, Enter choice (0 for All): ");
        scanf("%d", &l_usage);
            for (i = 0; i <= 14; i++) {
                if (db[i].id == 0) {
                    continue; // it was giving weird output, so I added this to avoid the empty structs in the array
                }
                if (db[i].price <= l_budget && (db[i].usage == l_usage || l_usage == 0)) {
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
    int i, p_budget, p_usage, os_choice, brand_prefference, count = 0;
        printf("\nWhat's the budget for your phone? (In rupees): ");
        scanf("%d", &p_budget);
        printf("\nWhat is your top priority? \n1. Best Camera Quality \n2. Longest Battery Life \n3. High Performance / Gaming \nEnter choice (0 for All): ");
        scanf("%d", &p_usage);
        printf("\nDo you want an \n1. Andriod \n2. Ios \nEnter choice (0 for All): ");
        scanf("%d", &os_choice);
        printf("\nDo you have any brand preference? \n1. Poco \n2. Realme \n3. Redmi \n4. Oppo \n5. Motorola \n6. Samsung \n7. Apple \n8. OnePlus \n9. Xiaomi \nEnter choice (0 for All): ");
        scanf("%d", &brand_prefference);
            for (i = 0; i <= 14; i++) {
                if (db[i].id == 0) {
                    continue; // it was giving weird output, so I added this to avoid the empty structs in the array
                }
                if (db[i].price <= p_budget && (db[i].usage == p_usage || p_usage == 0) && (db[i].os == os_choice || os_choice == 0) && (db[i].brand == brand_prefference || brand_prefference == 0)) {
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
