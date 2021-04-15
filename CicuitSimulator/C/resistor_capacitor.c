#include "header.h"
#include "function.h"

void calcResistor(){
    //Prosedur untuk menghitung resistansi dari susunan resistor seri, paralel, dan campuran
    //Input : -
    //Output: -

    //Kamus
    int i,n,mode;
    float r,r0;

    r0 = 0;
    mode = -1;

    //Pengulangan jika tidak memilih mode back atau exit
    do{
        //Menampilkan judul program
        displayHead();

        puts("Resistansi Susunan Resistor\n");
        puts("*Bila susunan campuran, lakukan perhitungan dari\n susunan terdalam.\n");

        //Jika ada hasil perhitungan sebelumnya, maka hasil ditampilkan
        if (r0 != 0)
            printf("r0 = %.4f ohm\n",r0);

        //Menampilkan menu dan navigasi
        puts("Menu:");
        puts("1. Resistansi Seri ");
        puts("2. Resistansi Paralel ");
        puts("3. Reset r0");
        puts("9. Back");
        puts("0. Exit");
        printf("\nPilihan : ");
        scanf("%d",&mode);

        //Jika dipilih mode 1 atau 2, maka akan dilakukan perhitungan
        if (mode == 1 || mode == 2){
            //Input jumlah komponen
            printf("Jumlah resistor : ");
            scanf("%d",&n);

            //Perhitungan kapasitansi
            for(i=0;i<n;i++){
                printf("R%d (ohm) :",i+1);
                scanf("%f",&r);
                if(mode==1)
                    r0 += r;
                else if(mode == 2 && r0 == 0)
                    r0 = r;
                else if(mode == 2 && r0 > 0)
                    r0 = 1/((1/r0) + (1/r));
            }

            //Output
            printf("Resistansi total : %.4f ohm\n",r0);

            fflush(stdin);
            printf("\n\t     Press Enter to Continue");
            while( getchar() != '\n' );
        }
        //Jika dipilih mode 3, maka r0 akan direset
        else if (mode == 3)
            r0=0;
    }while (mode !=9 && mode != 0);

    //Navigasi
    if (mode == 9)
        jns_rangkaian();
    else if (mode == 0)
        keluar();
    
}

void calcCapacitor(){
    //Prosedur untuk menghitung kapasitansi dari susunan kapasitor seri, paralel, dan campuran
    //Input : -
    //Output: -

    //Kamus
    int i,n,mode;
    float c,c0;

    c0 = 0;
    mode = -1;

    //Pengulangan jika tidak memilih mode back atau exit
    do{
        //Menampilkan judul program
        displayHead();

        puts("Kapasitansi Susunan Kapasitor\n");
        puts("*Bila susunan campuran, lakukan perhitungan dari\n susunan terdalam.\n");
        
        //Jika ada hasil perhitungan sebelumnya, maka hasil ditampilkan
        if (c0 != 0)
            printf("c0 = %.4f uF\n",c0);

        //Menampilkan menu dan navigasi
        puts("Menu:");
        puts("1. Kapasitansi Seri ");
        puts("2. Kapasitansi Paralel ");
        puts("3. Reset c0");
        puts("9. Back");
        puts("0. Exit");
        printf("\nPilihan : ");
        scanf("%d",&mode);

        //Jika dipilih mode 1 atau 2, maka akan dilakukan perhitungan
        if (mode == 1 || mode == 2){
            //Input jumlah komponen
            printf("Jumlah Kapasitor : ");
            scanf("%d",&n);
            for(i=0;i<n;i++){
                //Input value tiap komponen
                printf("C%d (uF) :",i+1);
                scanf("%f",&c);

                //Perhitungan kapasitansi
                if(mode == 1 && c0 == 0)
                    c0 = c;
                else if(mode == 1 && c0 > 0)
                    c0 = 1/((1/c0) + (1/c));
                else
                    c0 += c;
            }

            //Output
            printf("Kapasitansi total : %.4f uF\n",c0);

            fflush(stdin);
            printf("\n\t     Press Enter to Continue");
            while( getchar() != '\n' );
        }
        //Jika dipilih mode 3, maka c0 akan direset
        else if (mode == 3)
            c0=0;
    }while (mode !=9 && mode != 0);

    //Navigasi
    if (mode == 9)
        jns_rangkaian();
    else if (mode == 0)
        keluar();
}