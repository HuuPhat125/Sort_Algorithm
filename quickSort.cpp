#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
const int max_n = 1e6;

double a[max_n + 5] ;

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
int main(){
    auto start =high_resolution_clock::now();
    ifstream fi("test_1.txt");
    ofstream fo("ans_1.txt");
    for(int i = 0 ; i < max_n ; i++){
        fi >> a[i];
    }
    quickSort(a, 0, max_n - 1);
    for(int i = 0 ; i < max_n ; i++){
        fo << a[i];
    }
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    cout << "Time taken by code segment: " << time_taken.count() << " milliseconds." << endl;
}