// https://leetcode.com/problems/smallest-string-with-swaps/

/*
    Problem based on DSU.
*/

class Solution
{
public:
    int parent[100005], sz[100005];
    void make(int v)
    {
        parent[v] = v;
        sz[v] = 1;
    }
    int find(int v)
    {
        if (v == parent[v])
            return v;
        return (parent[v] = find(parent[v]));
    }
    void Union(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u != v)
        {
            if (sz[u] < sz[v])
                swap(u, v);
            parent[v] = u;
            sz[u] += sz[v];
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
            make(i);
        for (auto &it : pairs)
        {
            Union(it[0], it[1]);
        }
        vector<priority_queue<char, vector<char>, greater<>>> temp(100005);
        for (int i = 0; i < n; i++)
        {
            int r = find(i);
            temp[r].push(s[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int r = find(i);
            s[i] = temp[r].top();
            temp[r].pop();
        }

        return s;
    }
};
