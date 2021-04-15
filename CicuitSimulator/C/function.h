//======================================================================================================================
//Display Menu dan Navigasi: menu_display.c

    void displayHead();
        //Prosedur untuk merefresh tampilan (clear screen) dan menampilkan judul program

    void displayLogo();
        //Prosedur untuk menampilkan halaman awal berisi displayLogo program dan credits

    void displayCreator();
        //Prosedur untuk menampilkan nama pembuat program

    void menu();
        //Prosedur untuk menampilkan menu utama

    void jns_rangkaian();
        //Prosedur untuk menampilkan pilihan jenis rangkaian ke layar

    void confirmCircuit(int option);
        //Prosedur untuk mengonfirmasi pilihan rangkaian

    void keluar();
        //Prosedur untuk menampilkan halaman penutup sebelum program berakhir


//======================================================================================================================
//Perhitungan dan Analisis Rangkaian: circuitcalc.c

    float complexToFloat(float complex amp, float w, float t);
        //Fungsi untuk mengubah bilangan kompleks ke float
        //Input : amplitudo (float kompleks), omega (float), waktu dalam milidetik (float)
        //Output: float
        
    void displayR1();
        //Fungsi untuk menampilkan gambar rangkaian RC Seri (R1) dalam bentuk karakter ASCII

    void displayR2();
        //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R2) dalam bentuk karakter ASCII

    void displayR3();
        //Fungsi untuk menampilkan gambar rangkaian RC Paralel (R3) dalam bentuk karakter ASCII

    void displayR4();
        //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R4) dalam bentuk karakter ASCII

    void displayR5();
        //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R5) dalam bentuk karakter ASCII

    void displayR6();
        //Fungsi untuk menampilkan gambar rangkaian RC Campuran (R6) dalam bentuk karakter ASCII

    void R1();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Seri (R1)
        //dengan sumber tegangan AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv

    void R2();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian R2
        //dengan sumber tegangan AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv

    void R3();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Paralel (R3)
        //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv

    void R4();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R4)
        //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv

    void R5();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R5)
        //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv
    
    void R6();
        //Prosedur untuk menghitung tegangan node dan arus cabang pada rangkaian RC Campuran (R6)
        //dengan sumber arus AC ataupun DC dan menyimpan hasil perhitungan pada array
        //Prosedur akan menyimpan hasil perhitungan dalam file csv


//======================================================================================================================
//Perhitungan Susunan Resistor dan Kapasitor: resistor_capacitor.c

    void calcResistor();
        //Prosedur untuk menghitung resistansi dari susunan resistor seri, paralel, dan campuran

    void calcCapacitor();
        //Prosedur untuk menghitung kapasitansi dari susunan kapasitor seri, paralel, dan campuran


//======================================================================================================================
//Penanganan Hasil Perhitungan: output.c

    void printR1(float n, float* Va, float* Vb, float* I1);
        //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 1 dalam bentuk tabel ke layar
        //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
        //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus

    void printR3(float n, float* Va, float* I1, float* I2);
        //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 3 dalam bentuk tabel ke layar
        //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
        //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    
    
    void printR2(float charge_t, float n, float* Va, float* Vb, float* I1, float* I2, float* I3);
        //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 2 dalam bentuk tabel ke layar
        //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
        //Input : batasan waktu dalam milidetik, jumlah iterasi, dan pointer ke array tegangan dan array arus

    void printR4(float n, float* Va, float* Vb, float* Vc, float* I1, float* I2, float* I3);
        //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 4 dalam bentuk tabel ke layar
        //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
        //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus
    
    void printR5(float n, float* Va, float* Vb, float* Vc, float* Vd, float* I1, float* I2, float* I3);
        //Prosedur untuk menampilkan cuplikan data hasil perhitungan rangkaian 5 dan 6 dalam bentuk tabel ke layar
        //Jumlah maksimal data yang ditampilkan yakni 10 data dengan interval waktu data yang seragam
        //Input : batasan waktu dalam milidetik (float) dan pointer ke array tegangan dan array arus

    void saveCSV(char* jenis, float n, float iteration, float* Va, float* Vb, float* Vc, float* Vd, float* I1, float* I2, float* I3);
        //Prosedur untuk menyimpan data hasil perhitungan ke file CSV
        //Total data yang disimpan adalah 2xn
        //Input : jenis rangkaian, n, jumlah interation, dan pointer ke array tegangan dan array arus