class Solution {
public:
    int solver(int n){
        if(n==0){
            return 0;
        }
        int res = n;
        for(int j=1;j<=n-3;j++){// CtrlA ctrlC ctrlv
            int sol = (n-j-1)*solver(j);
            res = max(res,sol);

        }
        return res;       
    }
    int maxA(int n) {
        return solver(n);
    }
};
