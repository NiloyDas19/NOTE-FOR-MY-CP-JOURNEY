//https://codeforces.com/contest/25/problem/D

/**
 *   author:  Niloy_Das_19
**/

#include <bits/stdc++.h>
using namespace std;

/*************************************************************************************************/
#define mod 1000000007
#define firstio() ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define F first
#define S second
#define ll long long
#define pb push_back
#define nn "\n"
#define yes cout <<"YES"<< nn
#define no  cout << "NO"<< nn
#define bct(x) __builtin_popcountll(x)
#define full(x) x.begin(),x.end()
#define all(x) sort(x.begin(),x.end())
#define rall(x) sort(x.rbegin(),x.rend())
/*************************************************************************************************/



/*************************************************************************************************/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " ";print(x);cerr<<endl;
#else
#define debug(x)
#endif

void print(int x){cerr << x;}
void print(ll x){cerr << x;}
void print(double x){cerr << x;}
void print(char x){cerr << x;}
void print(string x){cerr << x;}

template <class T> void print(vector <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T> void print(set <T> v) {cerr << "[ "; for (T i : v) {print(i); cerr << " ";} cerr << "]";}
template <class T,class V> void print(map <T,V> v) {cerr << endl <<  "[ \n"; for (auto i=v.begin();i!=v.end();i++) {print(i->F); cerr << " "; print(i->S); cerr<<endl;} cerr << "]";}
/*************************************************************************************************/



/*************************************************************************************************/
vector<ll> sieve(ll n){ vector<bool> prime(n + 1, false); for (ll i = 4; i <= n; i += 2) {prime[i] = true;}for (ll i = 3; i * i <= n; i += 2) {if (!prime[i]) {for (int j = i * i; j <= n; j += 2 * i) {prime[j] = true;}}}vector<ll> ans;for (ll i = 2; i <= n; i++) {if (!prime[i]) ans.pb(i);}return ans;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll bexpo(ll a, ll b, ll mo) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mo; a = (a * a) % mo; b = b >> 1;} return res;}
/************************************************************************************************/


int parent[1005],sz[1005];
vector<pair<int,int>> ans;

void make(int v){
	parent[v] = v;
	sz[v] = 1;
}

int find(int v){
	if(v==parent[v]) return v;
	return parent[v] = find(parent[v]);
}

void Union(int u,int v){
	int a = find(u);
	int b = find(v);

	if(a==b){
		ans.pb({u,v});
	}
	else{
		if(sz[a]<sz[b])
			swap(a,b);
		parent[b] = a;
		sz[a]+=sz[b];
	}
}

void solve()
{
	ll t=1,i,j;
	// cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(i=1;i<=n;i++)
			make(i);
		for(i=0;i<n-1;i++){
			int u,v;
			cin >> u >> v;
			Union(u,v);
		}

		vector<int> ans1;
		for(i=1;i<=n;i++){
			if(parent[i]==i){
				ans1.pb(i);
			}
		}

		cout << ans1.size()-1 << nn;
		j=0;

		debug((int)ans.size())
		for(i=1;i<ans1.size();i++){
			cout << ans[j].F << " " << ans[j].S << " " << ans1[0] << " " << ans1[i] << nn;
			j++;
		}
	}
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("Error.txt","w",stderr);
#endif
	firstio()
	solve();
	return 0;
}

 