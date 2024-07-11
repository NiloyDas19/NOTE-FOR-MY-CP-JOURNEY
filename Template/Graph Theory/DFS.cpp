#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for(auto &v : g[u]) if(!vis[v]) dfs(v);
}

  
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> componenets;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i);
                componenets.push_back(i);
            }
        }
        int roads = componenets.size() - 1;
        cout << roads << "\n";
        for(int i = 0; i < roads; i++){
            cout << componenets[i] << " " << componenets[i + 1] << "\n";
        }
    }
    return 0;
}

// Problem Link: https://cses.fi/problemset/task/1666/
