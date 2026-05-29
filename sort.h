#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INT 1000
#define MAX_KATA 10000
#define MAX_HURUF 64
#define TAMPIL_N 15

// Utilitas
void generateInt(int arr[], int n);
void copyInt(int asal[], int tujuan[], int n);
void tampilInt(int arr[], int n, char* pesan);

int bacaKata(char arr[][MAX_HURUF], int max);
void acakKata(char arr[][MAX_HURUF], int n);
void copyKata(char asal[][MAX_HURUF], char tujuan[][MAX_HURUF], int n);
void tampilKata(char arr[][MAX_HURUF], int n, char* pesan);

void hitungWaktu(clock_t mulai, clock_t selesai);

// Sorting Dasar
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

// Advance Sorting
void mergeSort(char arr[][MAX_HURUF], int kiri, int kanan);
void merge(char arr[][MAX_HURUF], int kiri, int tengah, int kanan);
void quickSort(char arr[][MAX_HURUF], int low, int high);
int partition(char arr[][MAX_HURUF], int low, int high);
void shellSort(char arr[][MAX_HURUF], int n);

#endif
