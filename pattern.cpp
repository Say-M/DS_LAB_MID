#include <bits/stdc++.h>
using namespace std;

void search(string t, string p)
{
    int s = t.length(), r = p.size();
    for (int i = 0; i <= s - r; i++)
    {
        int j;
        for (j = 0; j < r; j++)
            if (p[j] != t[i + j])
                break;
        if (j == r)
            cout << "Pattern found at index " << i << endl;
    }
}

int main()
{
    string t = "AABAACAADAABAAABAA";
    string p = "AABA";
    search(t, p);
}