#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
const int max_n = 1e6;

double a[max_n + 5] ;

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
int main(){
    auto start =high_resolution_clock::now();
    ifstream fi("test_1.txt");
    ofstream fo("ans_1.txt");
    for(int i = 0 ; i < max_n ; i++){
        fi >> a[i];
    }
    mergeSort(a, 0, max_n - 1);
    for(int i = 0 ; i < max_n ; i++){
        fo << a[i];
    }
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken by code segment: " << time_taken.count() << " milliseconds." << endl;
}