#include "bits/stdc++.h"
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, idx;
    for (i = 0; i < n - 1; i++) {
        idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[idx]) idx = j;
        }
        if (idx != i) swap(arr[idx], arr[i]);
    }
}

void insertionSort(int arr[], int n) {
   int i, key, j;

   for (i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;
       while (j >= 0 && arr[j] > key) {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    bool sw;
    for (i = 0; i < n - 1; i++) {
        sw = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                sw = true;
            }
        }
        if (sw == false) break;
    }
}

//merge Sort
void merge(int arr[], int l, int m, int r) {
    int lenone = m - l + 1;
    int lentwo = r - m;
 
    int *leftArray = new int[lenone];
    int *rightArray = new int[lentwo];
 
    for (int i = 0; i < lenone; i++)
        leftArray[i] = arr[l + i];
    for (int j = 0; j < lentwo; j++)
        rightArray[j] = arr[m + 1 + j];
 
    int indexone = 0, indextwo = 0, indexmerge = l;

    while (indexone < lenone && indextwo < lentwo) {
        if (leftArray[indexone] <= rightArray[indextwo]) {
            arr[indexmerge] = leftArray[indexone];
            indexone++;
        }
        else {
            arr[indexmerge] = rightArray[indextwo];
            indextwo++;
        }
        indexmerge++;
    }
 
    while (indexone < lenone) {
        arr[indexmerge] = leftArray[indexone];
        indexone++;
        indexmerge++;
    }
 
    while (indextwo < lentwo) {
        arr[indexmerge] = rightArray[indextwo];
        indextwo++;
        indexmerge++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int begin, int end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int i = start - 1;
    for(int j = start; j < end; j++) {
    	if(arr[j] <= pivot) {
    		i++;
    		swap(arr[i], arr[j]);
    	}
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}
 
void quickSort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int pindex = partition(arr, start, end);
    quickSort(arr, start, pindex - 1);
    quickSort(arr, pindex + 1, end);
}

int main() {
	int n;
	cin >> n;
	int arr[n];
}