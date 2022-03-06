//https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

/*
   It's a dp problem.
   TC: O(n)
   SC: O(n)
*/


class Solution {
public:
    int countOrders(int n) {
      vector<long long> dp(n+1);
      dp[1] = 1LL;
      for(long long i=2;i<=n;i++){
          long long tar = 2*i - 1;
          tar = (tar*(tar+1))/2;
          dp[i] = (dp[i-1]%1000000007 * tar%1000000007)%1000000007;
      }
      return dp[n]%1000000007; 
    }
};

