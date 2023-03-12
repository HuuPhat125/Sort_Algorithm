#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
#include <cstdlib>
using namespace std;
using namespace std::chrono;
const int max_n = 1e6;

double a[max_n];

int main()
{
    auto start = high_resolution_clock::now();
    ifstream fi("test_10.txt");
    ofstream fo("ans_1.txt");
    ofstream myfile;
    myfile.open("my_res.txt", ios::app);
    for (int i = 0; i < 1e6; i++)
        fi >> a[i];
    sort(a, a + max_n);
    for (int i = 0; i < 1e6; i++)
        fo << a[i];
    auto end = high_resolution_clock::now();
    auto time_taken = duration_cast<milliseconds>(end - start);
    myfile << "Time taken by code segment: " << time_taken.count() << " milliseconds." << endl;
    myfile.close();
    return 0;
}