#include<bits/stdc++.h>
using namespace std;


long long biexpoi(long long a, long long n){
   long long res = 1;
   while (n>0)
   {
       if(n&1) res = res * a;
       a = a * a;
       n >>= 1;
   }
   return res;
}


int main(){
    long long a,n;
    cin >> a >> n;
    cout << biexpoi(a,n) << endl;
    return 0;
}