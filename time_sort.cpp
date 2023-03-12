#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
const int max_n = 1e6;

//heap sort
void heapify(double arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;

    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(double arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// QuickSort implementation
void quickSort(double arr[], int low, int high) {
    int i = low, j = high;
    double pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j) quickSort(arr, low, j);
    if (i < high) quickSort(arr, i, high);
}

void merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    double L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Mergesort algorithm to sort array arr[l..r]
void mergeSort(double arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2; // Find the middle point

        // Recursively sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// UTILITY FUNCTIONS

int main(){
    freopen ("result.txt", "w", stdout);
    string sort_function[4] = {"heapSort(arr1, max_n);", "quickSort(arr1, arr1[0], arr1[max_n -1]);", "mergeSort(arr1, arr1[0], arr1[max_n -1]);", "sort(arr1, arr1 + max_n);"};
    for(int j = 1 ; j < 11 ; j++){
        string file_name = "test_" + to_string(j) + ".txt" ;
        double arr1[max_n + 5];
        freopen(file_name.c_str(),"r",stdin);
        for(int i =  0; i < max_n ; i++) cin >> arr1[i];
        for(int i =  0; i < 3 ; i++) cout << arr1[i] << " ";
        //for(int i = 0 ; i < 4 ; i++){
            auto start = high_resolution_clock::now();
            //sort_function[i];
            heapSort(arr1, max_n);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << duration.count() << " microseconds"  << '\t';

            auto start1 = high_resolution_clock::now();
            //sort_function[i];
            //sort(arr1, arr1 + max_n);
            quickSort(arr1, arr1[0], arr1[max_n -1]);
            auto stop1 = high_resolution_clock::now();
            auto duration1 = duration_cast<microseconds>(stop1 - start1);
            cout << duration1.count() << " microseconds"  << '\t';

            auto start2 = high_resolution_clock::now();
            //sort_function[i];
            //sort(arr1, arr1 + max_n);
            mergeSort(arr1, arr1[0], arr1[max_n -1]);
            auto stop2 = high_resolution_clock::now();
            auto duration2 = duration_cast<microseconds>(stop2 - start2);
            cout << duration2.count() << " microseconds"  << '\t';

            auto start3 = high_resolution_clock::now();
            //sort_function[i];
            sort(arr1, arr1 + max_n);
            auto stop3 = high_resolution_clock::now();
            auto duration3 = duration_cast<microseconds>(stop3 - start3);
            cout << duration3.count() << " microseconds"  << '\t';
        //}
        cout << endl;

    }
    

}

