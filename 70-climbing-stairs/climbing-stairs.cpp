class Solution {
public:
    int climbStairsDP(int n,vector<int> &stairs){
        if(n == 1 || n== 2){
            return n;
        }

        if(stairs[n] != -1){
            return stairs[n];
        }

        return stairs[n] = climbStairsDP(n-1,stairs) + climbStairsDP(n-2,stairs);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        return climbStairsDP(n,dp);
    }
};