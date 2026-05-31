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

// ADVANCE SORTING (STRING)
void merge(char arr[][MAX_HURUF], int kiri, int tengah, int kanan) {
    int n1 = tengah - kiri + 1;
    int n2 = kanan - tengah;

    char L[n1][MAX_HURUF];
    char R[n2][MAX_HURUF];

    for (int i = 0; i < n1; i++) strcpy(L[i], arr[kiri + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[tengah + 1 + j]);

    int i = 0, j = 0, k = kiri;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            strcpy(arr[k], L[i]);
            i++;
        } else {
            strcpy(arr[k], R[j]);
            j++;
        }
        k++;
    }
    while (i < n1) {
        strcpy(arr[k], L[i]);
        i++; k++;
    }
    while (j < n2) {
        strcpy(arr[k], R[j]);
        j++; k++;
    }
}

void mergeSort(char arr[][MAX_HURUF], int kiri, int kanan) {
    if (kiri < kanan) {
        int tengah = kiri + (kanan - kiri) / 2;
        mergeSort(arr, kiri, tengah);
        mergeSort(arr, tengah + 1, kanan);
        merge(arr, kiri, tengah, kanan);
    }
}

int partition(char arr[][MAX_HURUF], int low, int high) {
    int acak = low + rand() % (high - low + 1);
    char temp[MAX_HURUF];
    strcpy(temp, arr[acak]);
    strcpy(arr[acak], arr[high]);
    strcpy(arr[high], temp);

    char pivot[MAX_HURUF];
    strcpy(pivot, arr[high]);
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    strcpy(temp, arr[i + 1]);
    strcpy(arr[i + 1], arr[high]);
    strcpy(arr[high], temp);
    return (i + 1);
}

void quickSort(char arr[][MAX_HURUF], int low, int high) {
     if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void shellSort(char arr[][MAX_HURUF], int n) {
    char temp[MAX_HURUF];
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            strcpy(temp, arr[i]);
            int j;
            for (j = i; j >= gap && strcmp(arr[j - gap], temp) > 0; j -= gap) {
                strcpy(arr[j], arr[j - gap]);
            }
            strcpy(arr[j], temp);
        }
    }
}
