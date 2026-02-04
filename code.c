#include <stdio.h>
#include <string.h>

void lst_of_all(struct Laptop l[], struct Phone p[]);
void recommendLaptop(struct Laptop db[]);
void recommendPhone(struct Phone db[]);
void printLaptopRow(struct Laptop l);
void printPhoneRow(struct Phone p);


int main() {
    int lap_budget, lap_usage, lap_ram_str, laptop_lst[20], phone_lst[20],ch; 

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

}

void lst_of_all(struct Laptop l[], struct Phone p[]) {
    
    // Laptop Entry 1
    l[0].id = 1;
    strcpy(l[0].name, "HP 15s (Core i3)"); 
    l[0].price = 38000;
    l[0].brand = 1;      
    l[0].usage = 2;      
    l[0].ram = 8;        
    l[0].storage = 512;  
    l[0].rating = 4.1;  

    // Laptop Entry 2
    l[1].id = 2;
    strcpy(l[1].name, "Dell G15 Gaming");
    l[1].price = 72000;
    l[1].brand = 2;      
    l[1].usage = 1;      
    l[1].ram = 16;
    l[1].storage = 512;
    l[1].rating = 4.5;

    
    // Phone Entry 1: (Example of Android)
    p[0].id = 1;
    strcpy(p[0].name, "Samsung Galaxy M34");
    p[0].price = 18000;
    p[0].brand = 1;      // 1=Samsung
    p[0].os = 1;         // 1=Android
    p[0].storage = 128;
    p[0].rating = 4.0;

    // Phone Entry 2: (Example of iPhone)
    p[1].id = 2;
    strcpy(p[1].name, "iPhone 13");
    p[1].price = 52000;
    p[1].brand = 2;      // 2=Apple
    p[1].os = 2;         // 2=iOS
    p[1].storage = 128;  
    p[1].rating = 4.8;

}

void recommendLaptop(struct Laptop db[]) {
    int lap_budget, lap_usage, lap_ram_str, laptop_lst[20], count =




















    return 0;
}