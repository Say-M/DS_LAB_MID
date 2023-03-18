#include <bits/stdc++.h>
using namespace std;

int search(int array[], int n, int key)
{
    for (int i = 0; i < n; i++)
        if (array[i] == key)
            return i;

    return -1;
}

int main()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(array) / sizeof(array[0]);
    int key = 10;
    int index = search(array, n, key);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}