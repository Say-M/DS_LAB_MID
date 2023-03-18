#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
}

void printArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int array[] = {10, 9, 1, 2, 8, 7, 3, 4, 6, 5};
    int n = sizeof(array) / sizeof(array[0]);
    bubbleSort(array, n);
    printArray(array, n);
}