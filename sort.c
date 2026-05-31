#include "sort.h"

// FUNGSI PEMBANTU
void generateInt(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 90000 + 10000; // Angka acak 5 digit
    }
}

void copyInt(int asal[], int tujuan[], int n) {
    for (int i = 0; i < n; i++) {
        tujuan[i] = asal[i];
    }
}

void tampilInt(int arr[], int n, char* pesan) {
    int tampil = (n < TAMPIL_N) ? n : TAMPIL_N;
    printf("%s: [", pesan);
    for (int i = 0; i < tampil; i++) {
        printf("%d", arr[i]);
        if (i < tampil - 1) printf(", ");
    }
    printf(", ... ]\n");
}

int bacaKata(char arr[][MAX_HURUF], int max) {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: File words.txt tidak ditemukan!\n");
        return 0;
    }
    int jumlah = 0;
    while (jumlah < max && fscanf(file, "%s", arr[jumlah]) != EOF) {
        jumlah++;
    }
    fclose(file);
    return jumlah;
}

void acakKata(char arr[][MAX_HURUF], int n) {
    char temp[MAX_HURUF];
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        strcpy(temp, arr[i]);
        strcpy(arr[i], arr[j]);
        strcpy(arr[j], temp);
    }
}

void copyKata(char asal[][MAX_HURUF], char tujuan[][MAX_HURUF], int n) {
    for (int i = 0; i < n; i++) {
        strcpy(tujuan[i], asal[i]);
    }
}

void tampilKata(char arr[][MAX_HURUF], int n, char* pesan) {
    int tampil = (n < TAMPIL_N) ? n : TAMPIL_N;
    printf("%s: [", pesan);
    for (int i = 0; i < tampil; i++) {
        printf("%s", arr[i]);
        if (i < tampil - 1) printf(", ");
    }
    printf(", ... ]\n");
}

void hitungWaktu(clock_t mulai, clock_t selesai) {
    double waktu = (double)(selesai - mulai) / CLOCKS_PER_SEC;
    printf("Waktu Eksekusi: %f detik\n\n", waktu);
}

// SORTING DASAR (INT)
void bubbleSort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
