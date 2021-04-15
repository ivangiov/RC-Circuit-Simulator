#include "header.h"
#include "function.h"

void printR1(float n, float* Va, float* Vb, float* I1){
    //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 1 dalam bentuk tabel ke layar
    //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
    //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    float t, interval;
    int i;

    t=0;

    //Menghitung interval waktu pencuplikan agar jumlah data tidak melebihi 10
    interval=ceil(n/5);
    
    //Header tabel
    puts("Sampel Data");
    puts("|     t      |     Va     |     Vb     |     I      |");

    //Menampilkan data dari array
    for(i=0;i<2*n;i+=interval){
        printf("| %10.3f | %10.3f | %10.3f | %10.3f |\n", t/2000,Va[i],Vb[i],I1[i]);
        t+=interval;
    }
}

void printR2(float charge_t, float n, float* Va, float* Vb, float* I1, float* I2, float* I3){
    //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 2 dalam bentuk tabel ke layar
    //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
    //Input : batasan waktu dalam milidetik, jumlah iterasi, dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    float t, interval;
    int i;

    t=0;

    //Menghitung interval waktu pencuplikan agar jumlah data tidak melebihi 10
    interval=charge_t*n/10000;

    //Header tabel
    puts("Sampel Data");
    puts("|     t      |     Va     |     I1     |     I2     |");

    //Menampilkan data dari array
    for(i=0;i<10;i+=1){
        printf("| %10.3f | %10.3f | %10.3f | %10.3f |\n", t*1000/n,Va[i],I1[i],I2[i]);
        t+=interval;
    }
}

void printR3(float n, float* Va, float* I1, float* I2){
    //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 3 dalam bentuk tabel ke layar
    //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
    //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    float t, interval;
    int i;

    t=0;

    //Menghitung interval waktu pencuplikan agar jumlah data tidak melebihi 10
    interval=ceil(n/5);

    //Header tabel
    puts("Sampel Data");
    puts("|     t      |     Va     |     I1     |     I2     |");

    //Menampilkan data dari array
    for(i=0;i<2*n;i+=interval){
        printf("| %10.3f | %10.3f | %10.3f | %10.3f |\n", t/2000,Va[i],I1[i],I2[i]);
        t+=interval;
    }
}

void printR4(float n, float* Va, float* Vb, float* Vc, float* I1, float* I2, float* I3){
    //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 4 dalam bentuk tabel ke layar
    //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
    //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    float t, interval;
    int i;

    t=0;

    //Menghitung interval waktu pencuplikan agar jumlah data tidak melebihi 10
    interval=ceil(n/5);

    //Header tabel
    puts("Sampel Data");
    puts("|     t      |     Va     |     Vb     |     Vc     |     I1     |     I2     |     I3     |");

    //Menampilkan data dari array
    for(i=0;i<2*n;i+=interval){
        printf("| %10.3f | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f |\n", t/2000,Va[i],Vb[i],Vc[i],I1[i],I2[i],I3[i]);
        t+=interval;
    }
}

void printR5(float n, float* Va, float* Vb, float* Vc, float* Vd, float* I1, float* I2, float* I3){
    //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 5 dan 6 dalam bentuk tabel ke layar
    //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
    //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    float t, interval;
    int i;

    t=0;

    //Menghitung interval waktu pencuplikan agar jumlah data tidak melebihi 10
    interval=ceil(n/5);

    //Header tabel
    puts("Sampel Data");
    puts("|     t      |     Va     |     Vb     |     Vc     |     Vd     |     I1     |     I2     |     I3     |");

    //Menampilkan data dari array
    for(i=0;i<2*n;i+=interval){
        printf("| %10.3f | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f | %10.3f |\n", t/2000,Va[i],Vb[i],Vc[i],Vd[i],I1[i],I2[i],I3[i]);
        t+=interval;
    }
}

void saveCSV(char* jenis, float n, float iteration, float* Va, float* Vb, float* Vc, float* Vd, float* I1, float* I2, float* I3){
    //Prosedur untuk menyimpan data hasil perhitungan ke file CSV
    //Total data yang disimpan adalah 2xn
    //Input : jenis rangkaian, n, jumlah interation, dan pointer ke array tegangan dan array arus
    //Output: -

    //Kamus
    FILE *fptr;
    float t,dt;
    int i;
    char filename[20];
    dt = n/iteration;

    //Menggabungkan nama file
    strcpy(filename, "Output/");
    strcat(filename, jenis);
    strcat(filename,".csv");
   
    fptr=fopen(filename,"w");
    t=0;
    if(!strcmp(jenis,"R1")){
        fprintf(fptr, "time,Va,Vb,I\n");
        for(i=0;i<=2*n;i++){
            fprintf(fptr, "%f,%f,%f,%f\n", t/2000,Va[i],Vb[i],I1[i]);
            t++;
        }
    }
    else if(!strcmp(jenis,"R2")){
        i=0;
        fprintf(fptr, "time,Va,Vb,i1,i2,i3\n");
        for(t=0;t<=n;t+=dt){
            fprintf(fptr, "%f,%f,%f,%f,%f,%f\n", t,Va[i],Vb[i],I1[i],I2[i],I3[i]);
            i++;
        }
    }
    else if(!strcmp(jenis,"R3")){
        fprintf(fptr, "time,V,I1,I2\n");
        for(i=0;i<=2*n;i++){
            fprintf(fptr, "%f,%f,%f,%f\n", t/2000,Va[i],I1[i],I2[i]);
            t++;
        }
    }
    else if(!strcmp(jenis,"R4")){
        fprintf(fptr, "time,Va,Vb,Vc,I1,I2,I3\n");
        for(i=0;i<=2*n;i++){
            fprintf(fptr, "%f,%f,%f,%f,%f,%f,%f\n", t/2000,Va[i],Vb[i],Vc[i],I1[i],I2[i],I3[i]);
            t++;
        }
    }
    else if(!strcmp(jenis,"R5") || !strcmp(jenis,"R6")){
        fprintf(fptr, "time,Va,Vb,Vc,Vd,I1,I2,I3\n");
        for(i=0;i<=2*n;i++){
            fprintf(fptr, "%f,%f,%f,%f,%f,%f,%f,%f\n", t/2000,Va[i],Vb[i],Vc[i],Vd[i],I1[i],I2[i],I3[i]);
            t++;
        }
    }
    printf("\nData lengkap tersimpan dalam folder %s\n",filename);

    fclose(fptr);
}
