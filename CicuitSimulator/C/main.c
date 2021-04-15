/*
==================================================================================================================
                                                 TUGAS BESAR PMC
                                                CIRCUIT SIMULATOR 

                                                    Kelompok 4:
                                         Ivan Giovanni         (13218006)
                                         Christian Dinata      (13218024)

    Persyaratan sistem:
    1. Sistem operasi Windows
    2. Memiliki aplikasi Python dengan library Pandas dan Matplotlib

    Metode Kompilasi:
    1. Buka cmd pada folder utama (CircuitSimulator)
    2. Ketikkan perintah berikut
        "cd C
        windres resources.rc resources.o
        gcc -o ..\CircuitSim main.c menu_display.c circuitcalc.c output.c resistor_capacitor.c resources.o -I."
    3. Tekan enter untuk mengompilasi program.
    
    # Menjalankan Program
    1. Buka folder utama (CicuitSimulator)
    2. Klik 2 kali pada aplikasi CircuitSim.exe
    2. Setelah muncul tampilan judul program, tekan enter untuk melanjutkan ke menu utama
    3. Terdapat beberapa pilian menu utama:
        - Tekan 1 untuk memilih jenis rangkaian
        - Tekan 2 untuk melihat nama pembuat program
        - Tekan 0 untuk keluar dari program
    4. Apabila memilih untuk keluar, jendela program akan menutup secara otomatis dalam 2 detik

    Icon credit: flaticon.com/authors/wichaiwi
==================================================================================================================
*/

#include "header.h"
#include "function.h"
#include "resources.h"

int main(){
    displayLogo();
    menu();
}