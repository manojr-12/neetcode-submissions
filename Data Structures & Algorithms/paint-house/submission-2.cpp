class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<vector<int>>& costs,int n,int i,int prev){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int res = INT_MAX;
        for(int j=0;j<3;j++){
            if(prev == -1 || prev !=j){
                int opt = costs[i][j] + solve(dp,costs,n,i+1,j);
                res = min(res,opt);
            }
        }
        return dp[i][prev+1] = res;
    }
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return solve(dp,costs,n,0,-1);
    }
};