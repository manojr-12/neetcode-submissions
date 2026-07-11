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
        //vector<vector<int>>dp(n+1,vector<int>(4,INT_MAX));
        vector<int>curr(4,INT_MAX);
        vector<int>next(4,0);
        for(int i = n-1;i>=0;i--){
            for(int prev=2;prev>=-1;prev--){
                int res = INT_MAX;
                for(int j=0;j<3;j++){
                    if(prev == -1 || prev !=j){
                        int opt = costs[i][j] + next[j+1];
                        res = min(res,opt);
                    }
                }
                curr[prev+1] = res;
            }
            next = curr;
        }
        return curr[0];
    }
};