# Tugas Besar PPC
Program ini berguna untuk mensimulasikan rangkaian listrik dengan komponen resistor dan atau kapasitor, baik dengan sumber AC atau sumber DC

# Kelompok:
1. Ivan Giovanni            (13218006)
2. Christian Dinata         (13218024)

#Persyaratan sistem:
1. Sistem operasi Windows
2. Memiliki aplikasi Python dengan library Pandas dan Matplotlib

# Metode Kompilasi
Kompilasi dilakukan pada sistem operasi Windows dengan compiler gcc
1. Buka cmd pada folder utama (CicuitSimulator)
2. Ketikkan perintah berikut:
	"cd C
	 windres resources.rc resources.o"
	 gcc -o ..\CircuitSim main.c menu_display.c circuitcalc.c output.c resistor_capacitor.c resources.o -I."
3. Tekan enter untuk mengompilasi program.

# Menjalankan Program
Untuk menjalankan program, ikuti langkah berikut:
1. Buka folder utama (CicuitSimulator)
2. Klik 2 kali pada aplikasi CircuitSim.exe
2. Setelah muncul tampilan judul program, tekan enter untuk melanjutkan ke menu utama
3. Terdapat beberapa pilian menu utama:
    - Tekan 1 untuk memilih jenis rangkaian
    - Tekan 2 untuk melihat nama pembuat program
    - Tekan 0 untuk keluar dari program
4. Apabila memilih untuk keluar, jendela program akan menutup secara otomatis dalam 2 detik

Icon credit by flaticon.com/authors/wichaiwi