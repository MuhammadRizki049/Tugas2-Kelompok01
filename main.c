#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

int main() {
    srand(time(NULL)); // Reset seed random
    
    // Array Data Asli
    int dataIntAwal[MAX_INT];
    char dataKataAwal[MAX_KATA][MAX_HURUF];
    
    // Array Data yang akan disorting
    int dataIntKerja[MAX_INT];
    char dataKataKerja[MAX_KATA][MAX_HURUF];
    
    int jumlahKata = 0;
    int kataSudahDimuat = 0;

    clock_t mulai, selesai;
    int pilihanUtama, pilihanSub;

    // Persiapkan integer saat awal program
    generateInt(dataIntAwal, MAX_INT);

    do {
        printf("\n=== MENU UTAMA ===\n");
        printf("1. Sorting Dasar\n");
        printf("2. Advance Sorting\n");
        printf("3. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihanUtama);

        if (pilihanUtama == 1) {
            do {
                printf("\n= SORTING DASAR =\n");
                printf("1. Bubble Sort\n");
                printf("2. Insertion Sort\n");
                printf("3. Selection Sort\n");
                printf("4. Kembali\n");
                printf("Pilih metode: ");
                scanf("%d", &pilihanSub);

                if (pilihanSub >= 1 && pilihanSub <= 3) {
                    // Reset data kerja ke data asli
                    copyInt(dataIntAwal, dataIntKerja, MAX_INT);
                    
                    tampilInt(dataIntKerja, MAX_INT, "Sebelum");
                    
                    mulai = clock(); // Hitung waktu mulai
                    if (pilihanSub == 1) bubbleSort(dataIntKerja, MAX_INT);
                    else if (pilihanSub == 2) insertionSort(dataIntKerja, MAX_INT);
                    else if (pilihanSub == 3) selectionSort(dataIntKerja, MAX_INT);
                    selesai = clock(); // Hitung waktu selesai

                    tampilInt(dataIntKerja, MAX_INT, "Sesudah");
                    hitungWaktu(mulai, selesai);
                }
            } while (pilihanSub != 4);

        } else if (pilihanUtama == 2) {
            if (kataSudahDimuat == 0) {
                jumlahKata = bacaKata(dataKataAwal, MAX_KATA);
                if (jumlahKata > 0) {
                    kataSudahDimuat = 1;
                    printf("\nBerhasil memuat %d kata dari words.txt!\n", jumlahKata);
                } else {
                    continue;
                }
            }

            do {
                printf("\n= ADVANCE SORTING =\n");
                printf("1. Merge Sort\n");
                printf("2. Quick Sort\n");
                printf("3. Shell Sort\n");
                printf("4. Kembali\n");
                printf("Pilih metode: ");
                scanf("%d", &pilihanSub);

                if (pilihanSub >= 1 && pilihanSub <= 3) {
                    // Reset dan acak ulang data setiap kali sorting
                    copyKata(dataKataAwal, dataKataKerja, jumlahKata);
                    acakKata(dataKataKerja, jumlahKata);
                    
                    tampilKata(dataKataKerja, jumlahKata, "Sebelum");
                    
                    mulai = clock();
                    if (pilihanSub == 1) mergeSort(dataKataKerja, 0, jumlahKata - 1);
                    else if (pilihanSub == 2) quickSort(dataKataKerja, 0, jumlahKata - 1);
                    else if (pilihanSub == 3) shellSort(dataKataKerja, jumlahKata);
                    selesai = clock();

                    tampilKata(dataKataKerja, jumlahKata, "Sesudah");
                    hitungWaktu(mulai, selesai);
                }
            } while (pilihanSub != 4);
        }

    } while (pilihanUtama != 3);

    printf("\nProgram selesai.\n");
    return 0;
}
