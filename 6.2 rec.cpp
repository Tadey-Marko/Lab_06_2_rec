#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void fillArray(int a[], int n, int i = 0) {
    if (i == n) return;
    a[i] = -20 + rand() % 41;
    fillArray(a, n, i + 1);
}
void printArray(const int a[], int n, int i = 0) {
    if (i == n) { cout << '\n'; return; }
    cout << setw(5) << a[i];
    printArray(a, n, i + 1);
}
int countOdd(const int a[], int n, int i = 0) {
    if (i == n) return 0;
    return (a[i] % 2 != 0 ? 1 : 0) + countOdd(a, n, i + 1);
}
#ifndef UNIT_TEST
int main() {
    int n;
    cout << "Enter array size (1..1000): ";
    if (!(cin >> n) || n < 1 || n > 1000) {
        cerr << "Invalid array size.\n"; return 1;
    }
    int* a = new int[n];
    srand(3);
    fillArray(a, n);
    cout << "Array: ";
    printArray(a, n);
    cout << "Number of odd elements: " << countOdd(a, n) << '\n';
    delete[] a;
    return 0;
}
#endif
