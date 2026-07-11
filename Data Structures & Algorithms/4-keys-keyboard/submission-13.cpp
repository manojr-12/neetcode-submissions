class Solution {
public:
    int solver(vector<int>&dp,int i){
        if(i==0){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int res = i;
        for(int j=1;j<=i-3;j++){ // CtrlA ctrlC ctrlv
            int sol = (i-j-1)*solver(dp,j);
            res = max(res,sol);

        }
        return dp[i] = res;       
    }
    int maxA(int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int res = i;
            for(int j=1;j<=i-3;j++){ 
                int sol = (i-j-1)* dp[j];
                res = max(res,sol);

            }
            dp[i] = res;   
        }
        return dp[n];
    }
};
