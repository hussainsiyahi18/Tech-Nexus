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
/* 1. Gaming
2. student/office
3. programming
    */
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
    l[5].brand = 6;
    l[5].usage = 3;
    l[5].ram = 16;
    l[5].storage = 512;

    l[6].id = 7;
    strcpy(l[6].name, "Acer Swift Go 14");
    l[6].price = 79000;
    l[6].brand = 5;
    l[6].usage = 3;
    l[6].ram = 16;
    l[6].storage = 1000;

    l[7].id = 8;
    strcpy(l[7].name, "Lenovo ThinkPad E14");
    l[7].price = 60000;
    l[7].brand = 3;
    l[7].usage = 3;
    l[7].ram = 16;
    l[7].storage = 512;

    l[8].id = 9;
    strcpy(l[8].name, "HP Pavilion 14");
    l[8].price = 60000;
    l[8].brand = 2;
    l[8].usage = 3;
    l[8].ram = 16;
    l[8].storage = 512;

    l[9].id = 10;
    strcpy(l[9].name, "ASUS Vivobook S");
    l[9].price = 56000;
    l[9].brand = 1;
    l[9].usage = 3;
    l[9].ram = 16;
    l[9].storage = 512;


    // ===== GAMING / HIGH END =====

    l[10].id = 11;
    strcpy(l[10].name, "Lenovo LOQ 15");
    l[10].price = 85000;
    l[10].brand = 3;
    l[10].usage = 1;
    l[10].ram = 16;
    l[10].storage = 512;

    l[11].id = 12;
    strcpy(l[11].name, "ASUS TUF F16");
    l[11].price = 97000;
    l[11].brand = 1;
    l[11].usage = 1;
    l[11].ram = 16;
    l[11].storage = 512;

    l[12].id = 13;
    strcpy(l[12].name, "MSI Katana A15");
    l[12].price = 97000;
    l[12].brand = 7;
    l[12].usage = 1;
    l[12].ram = 16;
    l[12].storage = 512;

    l[13].id = 14;
    strcpy(l[13].name, "Acer Nitro 16");
    l[13].price = 80000;
    l[13].brand = 5;
    l[13].usage = 1;
    l[13].ram = 16;
    l[13].storage = 512;

    l[14].id = 15;
    strcpy(l[14].name, "Acer Predator Helios Neo 16");
    l[14].price = 155000;
    l[14].brand = 5;
    l[14].usage = 1;
    l[14].ram = 32;
    l[14].storage = 1000;
}


    
    // Phone Entry 1: (Example of Android)
    p[0].id = 1;
    strcpy(p[0].name, "Samsung Galaxy M34");
    p[0].price = 18000;
    p[0].brand = 1;      // 1=Samsung
    p[0].os = 1;         // 1=Android
    p[0].storage = 128;

    // Phone Entry 2: (Example of iPhone)
    p[1].id = 2;
    strcpy(p[1].name, "iPhone 13");
    p[1].price = 52000;
    p[1].brand = 2;      // 2=Apple
    p[1].os = 2;         // 2=iOS
    p[1].storage = 128;

}

void recommendLaptop(struct Laptop db[]) {
    int lap_budget, lap_usage, lap_ram_str, laptop_lst[20], count =




















    return 0;
}
