#include<bits/stdc++.h>
using namespace std;

int a[100005],seg[4*100005];

void build(int ind,int low,int high){
      if(low==high){
          seg[ind] = a[low];
          return ;
      }
      int mid = (low+high)/2;
      build(2*ind+1,low,mid);
      build(2*ind+2,mid+1,high);
      seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}


int query(int ind,int low,int high, int l,int r){
    if(low>=l && high<=r) return seg[ind];
    if(l> high || low>r) return INT_MAX;
    int mid = (low+high)/2;
    int left = query(2*ind+1,low,mid,l,r);
    int right = query(2*ind+2,mid+1,high,l,r);
    return min(left,right);
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    build(0,0,n-1);

    int q;
    cin >> q;
    while (q--)
    {
       int l,r;
       cin >> l >> r;
       int ans = query(0,0,n-1,l,r);
       cout << ans << endl;
    }
    
    return 0;
}