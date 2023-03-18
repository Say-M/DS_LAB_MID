#include <bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int n, int key)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int m = (s + e) / 2;
        if (array[m] == key)
            return m;
        else if (array[m] > key)
            e = m - 1;
        else
            s = m + 1;
    }
    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 5;
    int loc = binarySearch(array, n, key);
    if (loc != -1)
        cout << "Element found at loc " << loc << endl;
    else
        cout << "Element not found" << endl;
}