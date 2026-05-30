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

    return 0;
}
