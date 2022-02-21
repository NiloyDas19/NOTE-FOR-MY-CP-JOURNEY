#include<bits/stdc++.h>
using namespace std;


long long biexpor(long long a, long long n){
    if(n==0) return 1;
    long long res = biexpor(a,n/2);
    if(n&1) res = res * res * a;
    else res = res * res;
    return res;
}

int main(){
    long long a,n;
    cin >> a >> n;
    cout << biexpor(a,n) << endl;
    return 0;
}