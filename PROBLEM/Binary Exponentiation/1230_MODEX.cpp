#include <bits/stdc++.h>
using namespace std;

long long biexpoi(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res % mod * a % mod) % mod;
        a = (a % mod * a % mod) % mod;
        n >>= 1;
    }
    return res % mod;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long t;
    while (1)
    {
        cin >> t;
        if(t==0) break;
        while (t--)
        {
            long long a, n, mod;
            cin >> a >> n >> mod;
            cout << biexpoi(a, n, mod) << endl;
        }
    }
    return 0;
}