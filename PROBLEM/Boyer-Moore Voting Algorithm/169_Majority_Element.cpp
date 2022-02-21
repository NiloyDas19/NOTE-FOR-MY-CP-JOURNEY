// https://leetcode.com/problems/majority-element/

/*

  It's a simple problem.But we need to know Boyer-Moore Majority Voting Algorithm
  to solve this problem optimally.
  TC-> O(n).
  SC-> O(1).

*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int Candidate = -1, vote = 0, cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (vote == 0)
                Candidate = nums[i];
            (nums[i] == Candidate) ? vote++ : vote--;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == Candidate)
                cnt++;
            if (cnt > n / 2)
                return Candidate;
        }
        return -1;
    }
};