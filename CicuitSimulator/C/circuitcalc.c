#include "header.h"
#include "function.h"

float Va[10000],Vb[10000],Vc[10000],Vd[10000],I1[10000],I2[10000],I3[10000];

float complexToFloat(float complex amp, float w, float t){
    //Fungsi untuk mengubah bilangan kompleks ke float
    //Input : amplitudo (float kompleks), omega (float), waktu dalam milidetik (float)
    //Output: float

    //Kamus
    float calcAc;

    //Operasi mengubah bilangan kompleks ke float dengan fungsi sinusoid
    calcAc = cabs(amp) * sin((w*t)+(cargf(amp))); 
    return calcAc;
}

void displayR1(){
    //Fungsi untuk menampilkan gambar rangkaian RC Seri (R1) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 1: RC Seri\n");
    puts("\t\tVa ----[R]---- Vb");
    puts("\t\t   |         |   ");
    puts("\t\t   |         v I ");
    puts("\t\t   |         |   ");
    puts("\t\t  [V]       [C]  ");
    puts("\t\t   |         |   ");
    puts("\t\t   -----------   ");
    puts("\t\t       GND     \n");
}

void displayR2(){
    //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R2) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 2: R Seri (R || C) ");
    puts("\t        I1           I3        ");
    puts("\t   Va -->-[R1]------->----- Vb ");
    puts("\t      |          |        |    ");
    puts("\t      |       I2 v        |    ");
    puts("\t      |          |        |    ");
    puts("\t     [V]        [R2]     [C]   ");
    puts("\t      |          |        |    ");
    puts("\t      ---------------------    ");
    puts("\t               GND           \n");
}

void displayR3(){
    //Fungsi untuk menampilkan gambar rangkaian RC Paralel (R3) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 3: RC Paralel");
    puts("\t                    I2         ");
    puts("\t   Va --------------->----- Vb ");
    puts("\t      |         |         |    ");
    puts("\t      |      I1 v         |    ");
    puts("\t      |         |         |    ");
    puts("\t     [I]       [R1]      [C]   ");
    puts("\t      |         |         |    ");
    puts("\t      ---------------------    ");
    puts("\t               GND           \n");
}

void displayR4(){
    //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R4) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 4: R Seri (RC || R) ");
    puts("\t                Vb             ");
    puts("\t   Va ---[R1]-------[R3]--- Vc ");
    puts("\t      |         |         |    ");
    puts("\t   I1 ^      I2 v      I3 v    ");
    puts("\t      |         |         |    ");
    puts("\t     [V]       [R2]      [C]   ");
    puts("\t      |         |         |    ");
    puts("\t      ---------------------    ");
    puts("\t               GND           \n");
}

void displayR5(){
    //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R5) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 5: R Seri (RC || RC) - sumber tegangan");
    puts("\t                Vb             ");
    puts("\t   Va ---[R1]-------------- Vc ");
    puts("\t      |         |         |    ");
    puts("\t   I1 ^      I2 v      I3 v    ");
    puts("\t      |         |         |    ");
    puts("\t      |        [R2]      [R3]   ");
    puts("\t      |         |         |    ");
    puts("\t     [V]       [R2]      [C]   ");
    puts("\t      |         |         |    ");
    puts("\t      ---------------------    ");
    puts("\t               GND           \n");
}

void displayR6(){
    //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R6) dalam bentuk karakter ASCII
    //Input : -
    //Output: -

    puts("Rangkaian 6: R Seri (RC || RC) - sumber arus");
    puts("\t                Vb             ");
    puts("\t   Va ---[R1]-------------- Vc ");
    puts("\t      |         |         |    ");
    puts("\t   I1 ^      I2 v      I3 v    ");
    puts("\t      |         |         |    ");
    puts("\t      |        [R2]      [R3]   ");
    puts("\t      |         |         |    ");
    puts("\t     [I]       [R2]      [C]   ");
    puts("\t      |         |         |    ");
    puts("\t      ---------------------    ");
    puts("\t               GND           \n");
}

void R1(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Seri (R1)
    //dengan sumber tegangan AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    //Kamus
    char sourcetype[5];
    int valid,i,input;
    float r, c, sudut, w, t, Vi, n;
    float complex cx_Vi,cx_w,cx_c,cx_r,cx_Vc;

    //Menampilkan judul program
    displayHead();
    
    //Menampilkan gambar rangkaian
    displayR1();
    
    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor (k ohm)      : ");
    scanf("%f", &r);
    printf("Kapasitor (uF)        : ");
    scanf("%f", &c);

    //Operasi mengubah nilai komponen sesuai satuan input
    r = r * 1000;
    c = 0.000001 * c;
    
    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input komponen sumber AC
        printf("Amplitudo sumber (V)  : ");
        scanf("%f",&Vi);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Ubah input ke domain kompleks
        cx_Vi = Vi * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r = r;
        cx_c = c;

        //Menghitung tegangan di node A (tegangan kapasitor) dalam bentuk kompleks
        cx_Vc=cx_Vi/(1+(I*w*c*r));
        printf("%.2f + %.2fi\n",creal(cx_Vc),cimag(cx_Vc));

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        for(t=0;t<=2*n;t++){
            Va[i] = complexToFloat(cx_Vi,w,t/2000);
            Vb[i] = complexToFloat(cx_Vc,w,t/2000);
            I1[i] = (Va[i]-Vb[i])/r;
            i++;        
        }
    }
    //Jika Sumber DC
    else{
        //Input nilai sumber DC
        printf("Tegangan sumber (V)   : ");
        scanf("%f",&Vi);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        for(t=0;t<=2*n;t++){
            Va[i] = Vi;
            Vb[i] = Vi * (1 - exp(-t/(2000*r*c)));
            I1[i] = (Vi-Vb[i])/r;
            i++;
        }
    }

    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR1(n,Va,Vb,I1);

    //Menyimpan tegangan node dan arus cabang per 0.5ms ke file csv
    saveCSV("R1",n,0,Va,Vb,0,0,I1,0,0);
    
    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R1.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R1();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}

void R2(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian R2
    //dengan sumber tegangan AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    char  sourcetype[5];
    int input,valid,j;
    float dt, charge_t, n, r1, r2, c, sudut, w, time, vi;
    float complex cx_Vi,cx_w,cx_c,cx_r1,cx_r2,cx_Vc;

    //Menampilkan judul program
    displayHead();

    //Menampilkan gambar rangkaian
    displayR2();

    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor 1 (k ohm)    : ");
    scanf("%f", &r1);
    printf("Resistor 2 (k ohm)    : ");
    scanf("%f", &r2);
    printf("Kapasitor (uF)        : ");
    scanf("%f", &c);

    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input nilai komponen AC
        printf("Amplitudo sumber (V)  : ");
        scanf("%f",&vi);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);

        r1 = r1*1000;
        r2 = r2*1000;
        c = 0.000001*c;

        cx_Vi = vi * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r1 = r1;
        cx_r2 = r2;
        cx_c = c;

        //Input iterasi
        printf("Stop time (ms)        : ");
        scanf("%f", &charge_t);
        printf("Jumlah iterasi (semakin besar semakin akurat): ");
        scanf("%f", &n);

        charge_t = charge_t*0.001;
        dt = charge_t/n;

        cx_Vc = (cx_Vi*r2)/(r1+r2+(I*w*c*r1*r2)); // perumusan tegangan kapasitor terhadap waktu

        j = 0;
        for (time=0; time<=charge_t; time+=dt){
            Va[j] = complexToFloat(cx_Vi,w,time); // tegangan node Vi
            Vb[j] = complexToFloat(cx_Vc,w,time); // tegangan node Vb
            I1[j] = (Va[j]-Vb[j])/r1;             // arus pada R1
            I2[j] = Vb[j]/r2;                     // arus pada R2
            I3[j] = complexToFloat(I*cx_Vc*w*c,w,time);
            
            j++;
        }
    }
    //Jika Sumber DC
    else{
        // Asumsi input dari user selalu benar
        printf("Tegangan sumber (V)   : ");
        scanf("%f", &vi);
        printf("Stop time (ms)        : ");
        scanf("%f", &charge_t);
        printf("Jumlah iterasi (semakin besar semakin akurat): ");
        scanf("%f", &n);
        r1 = r1*1000;
        r2 = r2*1000;
        c = 0.000001*c;
        charge_t = charge_t*0.001;
        dt = charge_t/n;
        j=0;
        for (time=0; time<=charge_t; time+=dt){
            Va[j]=vi;
            if (time==0){
                Vb[j] = 0;
                I3[j] = vi/(r1);
            }
            else{
                Vb[j] = Vb[j-1] + (   (  ( (vi-Vb[j-1])/(r1*c) ) - ( Vb[j-1]/(r2*c) )  )*dt   );
                I3[j] = ( ((vi-Vb[j-1])/r1) - (Vb[j-1]/r2 ));
            }
            I1[j] = (vi-Vb[j-1])/r1;
            I2[j] = Vb[j-1]/r2;
            j++;
                    
        }
    }
    
    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR2(charge_t,n,Va,Vb,I1,I2,I3);

    //Menyimpan tegangan node dan arus cabang file csv
    saveCSV("R2",charge_t,n,Va,Vb,0,0,I1,I2,I3);

    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R2.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R2();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}

void R3(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Paralel (R3)
    //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    //Kamus
    char sourcetype[5];
    int valid,i,input;
    float r, c, sudut, w, t, Is, n;
    float complex cx_Is,cx_w,cx_c,cx_r,cx_Vc;

    //Menampilkan judul program
    displayHead();

    //Menampilkan gambar rangkaian
    displayR3();

    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor (k ohm)      : ");
    scanf("%f", &r);
    printf("Kapasitor (uF)        : ");
    scanf("%f", &c);

    //Operasi mengubah nilai komponen sesuai satuan input
    r = r * 1000;
    c = 0.000001 * c;
    
    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input komponen sumber AC
        printf("Amplitudo sumber (A)  : ");
        scanf("%f",&Is);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Ubah input ke domain kompleks
        cx_Is = Is * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r = r;
        cx_c = c;

        //Menghitung tegangan di node A (tegangan kapasitor) dalam bentuk kompleks
        cx_Vc=cx_Is*r/(1+(I*w*c*r));
        printf("Vc = %.2f + %.2fi\n",creal(cx_Vc),cimag(cx_Vc));

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        for(t=0;t<=2*n;t++){
            Va[i] = complexToFloat(cx_Vc,w,t/2000);
            I1[i] = Va[i]/r;
            I2[i] = complexToFloat(cx_Is,w,t/2000) - I1[i];
            i++;
        }
    }
    //Jika sumber DC
    else{
        //Input nilai sumber DC
        printf("Arus sumber (A)       : ");
        scanf("%f",&Is);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        for(t=0;t<=2*n;t++){
            Va[i] = Is * r * (1 - exp(-t/(2000*r*c)));
            I1[i] = Va[i]/r;
            I2[i] = Is-I1[i];
            i++;
        }
    }

    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR3(n,Va,I1,I2);

    //Menyimpan tegangan node dan arus cabang per 0.5ms ke file csv
    saveCSV("R3",n,0,Va,0,0,0,I1,I2,0);

    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R3.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R3();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}

void R4(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R4)
    //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    //Kamus
    char sourcetype[5];
    int valid,i,input;
    float r1, r2, r3, c, sudut, w, t, Vi, n;
    float complex cx_Vi,cx_w,cx_c,cx_r1,cx_r2,cx_r3,cx_Vc;

    //Menampilkan judul program
    displayHead();

    //Menampilkan gambar rangkaian
    displayR4();

    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor 1 (k ohm)    : ");
    scanf("%f", &r1);
    printf("Resistor 2 (k ohm)    : ");
    scanf("%f", &r2);
    printf("Resistor 3 (k ohm)    : ");
    scanf("%f", &r3);
    printf("Kapasitor (uF)        : ");
    scanf("%f", &c);

    //Operasi mengubah nilai komponen sesuai satuan input
    r1 = r1 * 1000;
    r2 = r2 * 1000;
    r3 = r3 * 1000;
    c = 0.000001 * c;
    
    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input komponen sumber AC
        printf("Amplitudo sumber (V)  : ");
        scanf("%f",&Vi);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Ubah input ke domain kompleks
        cx_Vi = Vi * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r1 = r1;
        cx_r2 = r2;
        cx_r3 = r3;
        cx_c = c;

        //Menghitung tegangan di node A (tegangan kapasitor) dalam bentuk kompleks
        //cx_Vc=cx_Vb/(1+(I*w*c*r3));
        //printf("Vc = %.2f + %.2fi\n",creal(cx_Vc),cimag(cx_Vc));

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        I1[0] = Vi / (r1 +1 / ((1/r2) + (1/r3)));
        Vb[0] = Vi - (I1[0] * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = I1[0] - I2[0];       
        Vc[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            Va[i] = complexToFloat(cx_Vi,w,t/2000);
            Vb[i] = ((Va[i]/r1) + (Vc[i]/r3)) / ((1/r1) + (1/r2) + (1/r3));
            Vc[i] = complexToFloat(Vb[i]/(1+(I*w*c*r3)),w,t/2000);
            I1[i] = (Va[i] - Vb[i]) / r1;
            I2[i] = Vb[i] / r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }
    //Jika sumber DC
    else{
        //Input nilai sumber DC
        printf("Tegangan sumber (V)   : ");
        scanf("%f",&Vi);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        I1[0] = Vi / (r1 +1 / ((1/r2) + (1/r3)));
        Vb[0] = Vi - (I1[0] * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = I1[0] - I2[0];       
        Vc[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            Va[i] = Vi;
            Vb[i] = ((Va[i]/r1) + (Vc[i]/r3)) / ((1/r1) + (1/r2) + (1/r3));
            Vc[i+1] = Vb[i] * (1 - exp(-t/(2000*r3*c)));            
            I1[i] = (Va[i] - Vb[i]) / r1;
            I2[i] = Vb[i] / r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }

    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR4(n,Va,Vb,Vc,I1,I2,I3);

    //Menyimpan tegangan node dan arus cabang per 0.5ms ke file csv
    saveCSV("R4",n,0,Va,Vb,Vc,0,I1,I2,I3);

    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R4.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R4();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}

void R5(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R5)
    //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    //Kamus
    char sourcetype[5];
    int valid,i,input;
    float r1, r2, r3, c1,c2, sudut, w, t, Vi, n;
    float complex cx_Vi,cx_w,cx_c1,cx_c2,cx_r1,cx_r2,cx_r3,cx_Vc;

    //Menampilkan judul program
    displayHead();

    //Menampilkan gambar rangkaian
    displayR5();

    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor 1 (k ohm)    : ");
    scanf("%f", &r1);
    printf("Resistor 2 (k ohm)    : ");
    scanf("%f", &r2);
    printf("Resistor 3 (k ohm)    : ");
    scanf("%f", &r3);
    printf("Kapasitor 1 (uF)      : ");
    scanf("%f", &c1);
    printf("Kapasitor 2 (uF)      : ");
    scanf("%f", &c2);

    //Operasi mengubah nilai komponen sesuai satuan input
    r1 = r1 * 1000;
    r2 = r2 * 1000;
    r3 = r3 * 1000;
    c1 = 0.000001 * c1;
    c2 = 0.000001 * c2;
    
    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input komponen sumber AC
        printf("Amplitudo sumber (V)  : ");
        scanf("%f",&Vi);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Ubah input ke domain kompleks
        cx_Vi = Vi * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r1 = r1;
        cx_r2 = r2;
        cx_r3 = r3;
        cx_c1 = c1;
        cx_c2 = c2;

        //Menghitung tegangan di node A (tegangan kapasitor) dalam bentuk kompleks
        //cx_Vc=cx_Vb/(1+(I*w*c*r3));
        //printf("Vc = %.2f + %.2fi\n",creal(cx_Vc),cimag(cx_Vc));

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        I1[0] = Vi / (r1 +1 / ((1/r2) + (1/r3)));
        Vb[0] = Vi - (I1[0] * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = I1[0] - I2[0];       
        Vc[0] = Vb[0] - (I2[0] * r2);
        Vd[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            Va[i] = complexToFloat(cx_Vi,w,t/2000);
            Vb[i] = ((Va[i]/r1) + (Vc[i]/r2) + (Vd[i]/r3)) / ((1/r1) + (1/r2) + (1/r3));
            Vc[i] = complexToFloat(Vb[i]/(1+(I*w*c1*r2)),w,t/2000);
            Vd[i] = complexToFloat(Vb[i]/(1+(I*w*c2*r3)),w,t/2000);
            I1[i] = (Va[i] - Vb[i]) / r1;
            I2[i] = (Vb[i]-Vc[i]) / r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }
    //Jika sumber DC
    else{
        //Input nilai sumber DC
        printf("Tegangan sumber (V)   : ");
        scanf("%f",&Vi);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        I1[0] = Vi / (r1 + 1 / ((1/r2) + (1/r3)));
        Vb[0] = Vi - (I1[0] * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = I1[0] - I2[0];       
        Vc[0] = Vb[0] - (I2[0] * r2);
        Vd[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            Va[i] = Vi;
            Vb[i] = ((Va[i]/r1) + (Vc[i]/r2) + (Vd[i]/r3)) / ((1/r1) + (1/r2) + (1/r3));
            Vc[i+1] = Vb[i] * (1 - exp(-t/(2000*r2*c1)));
            Vd[i+1] = Vb[i] * (1 - exp(-t/(2000*r3*c2)));          
            I1[i] = (Va[i] - Vb[i]) / r1;
            I2[i] = (Vb[i] - Vc[i])/ r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }

    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR5(n,Va,Vb,Vc,Vd,I1,I2,I3);

    //Menyimpan tegangan node dan arus cabang per 0.5ms ke file csv
    saveCSV("R5",n,0,Va,Vb,Vc,Vd,I1,I2,I3);

    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R5.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R5();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}

void R6(){
    //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R6)
    //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
    //Prosedur akan menyimpan hasil perhitungan dalam file csv
    //Input : -
    //Output: -

    //Kamus
    char sourcetype[5];
    int valid,i,input;
    float r1, r2, r3, c1,c2, sudut, w, t, Is, n;
    float complex cx_Is,cx_w,cx_c1,cx_c2,cx_r1,cx_r2,cx_r3,cx_Vc;

    //Menampilkan judul program
    displayHead();

    //Menampilkan gambar rangkaian
    displayR6();

    //Memilih jenis sumber
    //Input diulang jika tidak valid
    do{
        printf("Jenis sumber (DC/AC)  : ");
        scanf("%s",sourcetype);
        if (!strcmp(sourcetype,"AC") || !strcmp(sourcetype,"DC"))
            valid = 1;
        else 
            valid = 0;
    }while (valid == 0);

    //Input nilai komponen
    printf("Resistor 1 (k ohm)    : ");
    scanf("%f", &r1);
    printf("Resistor 2 (k ohm)    : ");
    scanf("%f", &r2);
    printf("Resistor 3 (k ohm)    : ");
    scanf("%f", &r3);
    printf("Kapasitor 1 (uF)      : ");
    scanf("%f", &c1);
    printf("Kapasitor 2 (uF)      : ");
    scanf("%f", &c2);

    //Operasi mengubah nilai komponen sesuai satuan input
    r1 = r1 * 1000;
    r2 = r2 * 1000;
    r3 = r3 * 1000;
    c1 = 0.000001 * c1;
    c2 = 0.000001 * c2;
    
    //Jika sumber AC
    if (!strcmp(sourcetype,"AC")){
        //Input komponen sumber AC
        printf("Amplitudo sumber (A)  : ");
        scanf("%f",&Is);
        printf("Frekuensi sudut (w)   : ");
        scanf("%f",&w); 
        printf("Sudut fasa (derajat)  : ");
        scanf("%f",&sudut);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Ubah input ke domain kompleks
        cx_Is = Is * (cos(sudut*pi/180) + (I * sin(sudut*pi/180)));
        cx_w = w;
        cx_r1 = r1;
        cx_r2 = r2;
        cx_r3 = r3;
        cx_c1 = c1;
        cx_c2 = c2;

        //Menghitung tegangan di node A (tegangan kapasitor) dalam bentuk kompleks
        //cx_Vc=cx_Vb/(1+(I*w*c*r3));
        //printf("Vc = %.2f + %.2fi\n",creal(cx_Vc),cimag(cx_Vc));

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        Va[0] = Is * (r1 + 1 / ((1/r2) + (1/r3)));
        Vb[0] = Va[0] - (Is * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = Is - I2[0];       
        Vc[0] = Vb[0] - (I2[0] * r2);
        Vd[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            I1[i] = complexToFloat(cx_Is,w,t/2000);
            Vb[i] = (I1[i] + (Vc[i]/r2) + (Vd[i]/r3)) / ((1/r2) + (1/r3));
            Va[i] = (I1[i] * r1) + Vb[i];
            Vc[i] = complexToFloat(Vb[i]/(1+(I*w*c1*r2)),w,t/2000);
            Vd[i] = complexToFloat(Vb[i]/(1+(I*w*c2*r3)),w,t/2000);
            I2[i] = (Vb[i]-Vc[i]) / r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }
    //Jika sumber DC
    else{
        //Input nilai sumber DC
        printf("Arus sumber (A)       : ");
        scanf("%f",&Is);
        printf("Stop time (ms)        : ");
        scanf("%f", &n);

        //Menghitung tegangan node dan arus cabang tiap 0.5ms
        i=0;
        Va[0] = Is * (r1 + 1 / ((1/r2) + (1/r3)));
        Vb[0] = Va[0] - (Is * r1);
        I2[0] = Vb[0] / r2;
        I3[0] = Is - I2[0];       
        Vc[0] = Vb[0] - (I2[0] * r2);
        Vd[0] = Vb[0] - (I3[0] * r3);

        for(t=0;t<=2*n;t++){
            I1[i] = Is;
            Vb[i] = (I1[i] + (Vc[i]/r2) + (Vd[i]/r3)) / ((1/r2) + (1/r3));
            Va[i] = (I1[i] * r1) + Vb[i];
            Vc[i+1] = Vb[i] * (1 - exp(-t/(2000*r2*c1)));
            Vd[i+1] = Vb[i] * (1 - exp(-t/(2000*r3*c2)));          
            I2[i] = (Vb[i] - Vc[i])/ r2;
            I3[i] = I1[i] - I2[i];
            i++;
        }
    }

    //Menampilkan cuplikan data tegangan node dan arus cabang (max 10 data)
    printR5(n,Va,Vb,Vc,Vd,I1,I2,I3);

    //Menyimpan tegangan node dan arus cabang per 0.5ms ke file csv
    saveCSV("R6",n,0,Va,Vb,Vc,Vd,I1,I2,I3);

    //Menjalankan python untuk menampilkan grafik
    puts("\nMenampilkan Grafik Tegangan dan Arus");
    puts("Mohon tunggu sejenak");
    system ("python Python/Graph_R6.py");

    //Navigasi
    puts("");
    puts("1. Ulangi");
    puts("2. Pilih Rangkaian");
    puts("3. Menu utama");
    puts("0. Exit");
    printf("Input: ");
    scanf("%d", &input);

    if (input == 1)
        R6();
    else if (input == 2)
        jns_rangkaian();
    else if (input == 3)
        menu();
    else if (input == 0)
        keluar();
}