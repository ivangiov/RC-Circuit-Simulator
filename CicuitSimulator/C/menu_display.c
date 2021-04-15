#include "header.h"
#include "function.h"

void displayHead(){
    //Fungsi untuk merefresh tampilan (clear screen) dan menampilkan judul program
    //Input : -
    //Output: -

    system("cls");
    puts("--------------- CIRCUIT SIMULATOR ---------------\n");
}

void displayLogo(){
    //Prosedur untuk menampilkan halaman awal berisi displayLogo program dan credits
    //Input : -
    //Output: -

    puts("=================================================");
    puts("   _____ _                _ _                    ");
    puts("  / ____(_)              (_) |                   ");
    puts(" | |     _ _ __ ___ _   _ _| |_                  ");
    puts(" | |    | | '__/ __| | | | | __|                 ");
    puts(" | |____| | | | (__| |_| | | |_                  ");
    puts("  \\_____|_|_|  \\___|\\__,_|_|\\__|   _             ");
    puts("  / ____(_)               | |     | |            ");
    puts(" | (___  _ _ __ ___  _   _| | __ _| |_ ___  _ __ ");
    puts("  \\___ \\| | '_ ` _ \\| | | | |/ _` | __/ _ \\| '__|");
    puts("  ____) | | | | | | | |_| | | (_| | || (_) | |   ");
    puts(" |_____/|_|_| |_| |_|\\__,_|_|\\__,_|\\__\\___/|_|   \n");
    puts("=================================================\n");
    puts("\t\t   Created by:\n");
    puts("\t\t <<<KELOMPOK 4>>>");
    puts("\tIvan Giovanni          (13218006)");
    puts("\tChristian Dinata       (13218024)\n");
    printf("\t     Press Enter to Continue");
    while( getchar() != '\n' );
}

void displayCreator(){
    //Prosedur untuk menampilkan nama pembuat program
    //Input : -
    //Output: -

    //Kamus
    int input;
    
    //Menampilkan judul program
    displayHead();

    //Output
    puts("\t\t   Created by:\n");
    puts("\t\t <<<KELOMPOK 4>>>");
    puts("\tIvan Giovanni          (13218006)");
    puts("\tChristian Dinata       (13218024)");
    puts("\nIcon credit: flaticon.com/authors/wichaiwi");
    puts("");

    //Navigasi
    puts("9. Back");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 9)
        menu();
    else if (input == 0)
        keluar();
    else
        displayCreator();
}

void menu(){
    //Prosedur untuk menampilkan menu utama ke layar
    //Input : -
    //Output: - 

    //Kamus
    int input;
        
    //Menampilkan judul program
    displayHead();

    //Menu dan Navigasi
    printf("1. Jenis Rangkaian\n");
    printf("2. Program Creators\n");
    printf("0. Exit\n");
    printf("Input: ");
    scanf("%d",&input);

    if (input == 1){
        jns_rangkaian();
    }
    else if (input == 2){
        displayCreator();
    }
    else if (input == 0){
        keluar();
    }
    else{
        menu();
    }
}

void jns_rangkaian(){
    //Prosedur untuk menampilkan pilihan jenis rangkaian ke layar
    //Input : -
    //Output: -

    //Kamus
    int input;

    //Menampilkan judul program
    displayHead();

    //Menampilkan pilihan rangkaian dan navigasi
    puts("Jenis Rangkaian\n");
    printf("1. ");
    displayR1();
    printf("2. ");
    displayR2();
    printf("3. ");
    displayR3();
    printf("4. ");
    displayR4();
    printf("5. ");
    displayR5();
    printf("6. ");
    displayR6();
    puts("7. Resistansi Susunan Resistor");
    puts("8. Kapasitansi Susunan Kapasitor");
    puts("9. Back");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    //Program akan menjalankan fungsi sesuai dengan pilihan user
    if (input >= 1 && input <= 8)
        confirmCircuit(input);
    else if (input == 9)
        menu();
    else if (input == 0)
        keluar();
    else
        jns_rangkaian();
}

void confirmCircuit(int option){
    //Prosedur untuk mengonfirmasi pilihan rangkaian
    //Input : -
    //Output: -

    //Kamus
    int input;

    //Menampilkan judul program
    displayHead();

    //Menjalankan fungsi lain sesuai input option
    if (option == 1)
        displayR1();
    else if (option == 2)
        displayR2();
    else if (option == 3)
        displayR3();
    else if (option == 4)
        displayR4();
    else if (option == 5)
        displayR5();
    else if (option == 6)
        displayR6();
    else if (option == 7){
        calcResistor();
        return;
    }else if (option == 8){
        calcCapacitor();
        return;
    }
    
    //Navigasi
    printf("1. Next\n");
    printf("9. Back\n");
    printf("0. Exit\n");
    printf("Input: ");
    scanf("%d", &input);
    
    if (input == 1){
        if (option == 1)
            R1();
        else if (option == 2)
            R2();
        else if (option == 3)
            R3();
        else if (option == 4)
            R4();
        else if (option == 5)
            R5();
        else if (option == 6)
            R6();
    }
    else if (input == 9)
        jns_rangkaian();
    else if (input == 0)
        keluar();
    else
        confirmCircuit(option);
}

void keluar(){
    //Prosedur untuk menampilkan halaman penutup sebelum program berakhir
    //Input : -
    //Output: -

    //Menampilkan judul program
    displayHead();

    puts("\t    Anda keluar. Terima kasih!");
    puts("");
    Sleep(1500);
    exit(0);
}