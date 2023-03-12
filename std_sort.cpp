#include <iostream>
//#include <bits/stdc++.h>
#include <queue>
#include <time.h>
#include <algorithm>
using namespace std;
#include "quickSort.h"
#include "heapSort.h"
#include "mergeSort.h"

const int mN = 1e6 + 10;
int n;
float inpArr[mN], runArr[mN];
const string NAME = "test_10";

void reset() {
    for (int i = 1; i <= n; i++)
        runArr[i] = inpArr[i];
}

int main() {
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen((NAME + ".out").c_str(), "w", stdout);
    clock_t start, finish;
    n = 1e6;
    for (int i = 0; i < n; i++)
        cin >> inpArr[i];
    cout << "\n";
    cout << "Result in " << NAME << " are :\n";
    reset();
    start = clock();
    MergeSort(runArr, 0, n - 1);
    finish = clock();
    cout << "Merge Sort runtime is: " << (finish - start)  * 1.0 /CLOCKS_PER_SEC << "s\n";
    reset();
    start = clock();
    QuickSort(runArr, 0, n - 1);
    finish = clock();
    cout << "Quick Sort runtime is: " << (finish - start) * 1.0 /CLOCKS_PER_SEC << "s\n";
    reset();
    start = clock();
    HeapSort(runArr, 0, n - 1);
    finish = clock();
    cout << "Heap Sort runtime is: " << (finish - start) * 1.0 /CLOCKS_PER_SEC << "s\n";
    reset();
    start = clock();
    sort(runArr, runArr + n);
    finish = clock();
    cout << "std::sort in C++ runtime is: " << (finish - start)  * 1.0 /CLOCKS_PER_SEC << "s\n";
    // for(int i = 0 ; i < n ; i++){
    //     cout << runArr[i] << " "; 
    // }
}