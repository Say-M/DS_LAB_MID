#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k, item;
    cin >> k >> item;
    k--;
    for (int i = n - 1; i >= k; i--)
        a[i + 1] = a[i];
    a[k] = item;
    n++;

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}