#include <iostream>
#include <bits/stdc++.h>
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

void reset()
{
    for (int i = 1; i <= n; i++)
        runArr[i] = inpArr[i];
}

int main()
{
    freopen((NAME + ".inp").c_str(), "r", stdin);
    freopen(("result"), "a", stdout);
    clock_t start, finish;
    n = 1e6;
    for (int i = 0; i < n; i++)
        cin >> inpArr[i];
    reset();
    start = clock();
    MergeSort(runArr, 0, n - 1);
    finish = clock();

    ofstream fo;
    fo.open("output_MergeSort.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        fo << runArr[i] << " ";
    }
    fo.close();

    cout << (finish - start) * 1.0 / CLOCKS_PER_SEC << "s\t";
    reset();
    start = clock();
    QuickSort(runArr, 0, n - 1);
    finish = clock();
    ofstream fo1;
    fo1.open("output_quickSort.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        fo1 << runArr[i] << " ";
    }
    fo1.close();

    cout << (finish - start) * 1.0 / CLOCKS_PER_SEC << "s\t";
    reset();
    start = clock();
    HeapSort(runArr, 0, n - 1);
    finish = clock();
    ofstream fo2;
    fo2.open("output_heapSort.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        fo2 << runArr[i] << " ";
    }
    fo2.close();

    cout << (finish - start) * 1.0 / CLOCKS_PER_SEC << "s\t";
    reset();
    start = clock();
    sort(runArr, runArr + n);
    finish = clock();
    ofstream fo3;
    fo3.open("output_stdsort.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        fo3 << runArr[i] << " ";
    }
    fo3.close();

    cout << (finish - start) * 1.0 / CLOCKS_PER_SEC << "s\t";
    // for(int i = 0 ; i < n ; i++){
    //     cout << runArr[i] << " ";
    // }
    cout << endl;
}