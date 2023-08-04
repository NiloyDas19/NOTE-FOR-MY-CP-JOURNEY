#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 5005;
ll mods[2] = {1000000007,1000000009};
ll bases[2] = {137,281};
ll pwbase[3][MAX];

void Preprocess()
{
    pwbase[0][0] = pwbase[1][0] = 1;
    for(ll i=0;i<2;i++){
        for(ll j=1 ; j < MAX ; j++){
            pwbase[i][j] = (pwbase[i][j-1] * bases[i]) %mods[i];
        }
    }
}

struct Hashing{
    ll hsh[2][MAX];
    Hashing(){};
    Hashing(string _str) {str = _str; memset(hsh,0,sizeof(hsh)); Build();}

    void Build()
    {
        for(ll i=str.size()-1 ; i>=0 ;i--){
            for(ll j=0 ; j<2 ; j++){
                hsh[j][i] = (hsh[j][i + 1] * bases[j] + str[i]) %mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j])%mods[j];
            }
        }
    }

    pair<ll,ll> GetHash(ll i, ll j){
        assert(i <= j);
        ll temp1 = (hsh[0][i] - (hsh[0][j+1] * pwbase[0][j-i+1]) %mods[0]) %mods[0];
        ll temp2 = (hsh[1][i] - (hsh[1][j+1] * pwbase[1][j-i+1]) %mods[1]) %mods[1];
        if(temp1 < 0) temp1+=mods[0];
        if(temp2 < 0) temp2+=mods[1];
        return {temp1,temp2};
    }

};


int main()
{
    ll n; cin >> n;
    string s; cin >> s;
    Preprocess();
    Hashing hsh(s);
    ll low = 0, high = n;
    while(low < high){
        ll mid = (low+high+1)/2;
        map<pair<ll,ll>,vector<ll>> m;
        for(ll i=0;i<n-mid+1;i++){
            m[hsh.GetHash(i,i+mid-1)].push_back(i);
        }
        bool ch = false;
        for(auto &it:m){
            if(it.second.size() < 2) continue;
            if(it.second.back()-it.second[0] >= mid){
                ch = true;
                break;
            }
        }
        if(ch){
            low = mid;
        }
        else high = mid-1;
    }
    cout << low << "\n";
    return 0;
}