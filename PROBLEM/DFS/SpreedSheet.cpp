/**
 *   author:  Niloy_Das_19
**/

// Problem Link : https://toph.co/p/spreadsheet-1-0


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

int n,m,i,j;
vector<vector<string>> spd(1005,vector<string>(1005));
vector<string> allString;
map<string,int> mp;
void help(vector<string>&temp){
    if(allString.size() > n) return;
    vector<string>cpy;
    for(auto &it:temp){
        string te = it;
        for(char a= 'A';a<='Z';a++){
            te.pb(a);
            allString.pb(te);
            if(allString.size() > n) return;
            cpy.pb(te);
            te.pop_back();
        }
    }
    temp = cpy;
    help(temp);
}


vector<string> cuTci(string &s){
    string s1,s2,op;
    int i = 1;
    while(1){
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') break;
        s1.pb(s[i]);
        i++;
    }
    op.push_back(s[i]);
    i++;
    s2 = s.substr(i);
    vector<string> temp = {s1,op,s2};
    return temp;
}

pair<int,int> rowCol(string &s){
    string temp;
    while(s.back()>='0' && s.back()<='9'){
        temp.pb(s.back());
        s.pop_back();
    }
    reverse(full(temp));
    int row = stoi(temp);
    int col = mp[s];
    return {row,col};
}

string calc(string &left , string &op , string &right){
    if(left=="CYCLE" || right=="CYCLE") return "CYCLE";
    if(left=="DIVZERO" || left=="OVERFLOW") return left;
    if(right=="DIVZERO" || right=="OVERFLOW") return right;

    ll leftval = stoll(left);
    ll rightval = stoll(right);

    ll finalVal=0;

    if(op=="/"){
        if(rightval==0) return "DIVZERO";
        finalVal = leftval/rightval;
    }
    else if(op=="*"){
        finalVal = leftval*rightval;
    }
    else if(op=="-"){
        finalVal = leftval-rightval;
    }
    else finalVal = leftval+rightval;

    if(finalVal < INT32_MIN || finalVal > INT32_MAX) return "OVERFLOW";

    string s = to_string(finalVal);
    return s; 
}

string dfs(int x, int y, vector<vector<bool>> &visit){
    if(spd[x][y][0]!='=') return spd[x][y];
    if(visit[x][y]) return "CYCLE";
    visit[x][y] = true;
    vector<string> cutci = cuTci(spd[x][y]);
    

    pair<int,int> left = rowCol(cutci[0]);
    pair<int,int> right = rowCol(cutci[2]);


    string leftTree = dfs(left.F , left.S , visit);
    string rightTree = dfs(right.F, right.S , visit);
    
    string re = calc(leftTree,cutci[1],rightTree);
    return spd[x][y] = re;
}

void solve()
{
    cin >> n >> m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin >> spd[i][j];
        }
    }

    vector<string> temp;
    for(char a = 'A' ; a<='Z' ; a++){
        string te;
        te.pb(a);
        temp.pb(te);
    }
    allString = temp;
    help(temp);
    debug(allString)
    for(i=1;i<allString.size();i++){
        mp[allString[i-1]]= i;
    }


    vector<vector<bool>> visit(n+1,vector<bool>(m+1,false));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dfs(i,j,visit);
        }
    }
    

    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cout << spd[i][j] << " ";
        }
        cout << nn;
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
