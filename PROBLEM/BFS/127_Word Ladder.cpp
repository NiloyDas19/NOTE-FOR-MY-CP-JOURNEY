// https://leetcode.com/problems/word-ladder/

/*
   Solve this problem using BFS.
   Best Explanation Link : https://leetcode.com/problems/word-ladder/discuss/1764646/C%2B%2Bor-Detailed-Explanation-and-Answering-WHY-for-each-step-or-Commented-codeor
*/

static int speedUp = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s;
        bool ch = false;
        for (auto &it : wordList)
        {
            if (it == endWord)
                ch = true;
            s.insert(it);
        }
        if (!ch)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        while (!q.empty())
        {
            level++;
            int sz = q.size();
            while (sz--)
            {
                string cpy = q.front();
                q.pop();
                for (int i = 0; i < cpy.size(); i++)
                {
                    string cpy1 = cpy;
                    for (char j = 'a'; j <= 'z'; j++)
                    {
                        cpy1[i] = j;
                        if (cpy == cpy1)
                            continue;
                        if (cpy1 == endWord)
                            return level + 1;
                        if (s.find(cpy1) != s.end())
                        {
                            s.erase(cpy1);
                            q.push(cpy1);
                        }
                    }
                }
            }
        }
        return 0;
    }
};