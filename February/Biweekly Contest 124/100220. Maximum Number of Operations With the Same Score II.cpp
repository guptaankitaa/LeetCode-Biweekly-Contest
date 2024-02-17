

class Solution {
public:
    
    int solve(int i,int j,int sum,vector<int>&a,vector<vector<int>>&dp){
        
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int p1=0;
        int p2=0;
        int p3=0;
        
        if(i+1<=j && a[i]+a[i+1]==sum){
            p1=1+solve(i+2,j,sum,a,dp);
        }
        
        if(j-1>=i && a[j]+a[j-1]==sum){
            p2=1+solve(i,j-2,sum,a,dp);
        }
        
        if(a[i]+a[j]==sum){
            p3=1+solve(i+1,j-1,sum,a,dp);
        }
        
        
        return dp[i][j]=max(p1,max(p2,p3));
        
    }
    int maxOperations(vector<int>& a) {
        
        int n=a.size();
        
        vector<int>v1;
        vector<int>v2;
        vector<int>v3;
        
        
         vector<vector<int>>dp1(n,vector<int>(n,-1));
         vector<vector<int>>dp2(n,vector<int>(n,-1));
         vector<vector<int>>dp3(n,vector<int>(n,-1));
        
        
         for(int i=0;i<n-2;i++)v2.push_back(a[i]);
         for(int i=1;i<n-1;i++)v3.push_back(a[i]);
         for(int i=2;i<n;i++)v1.push_back(a[i]);
        
         int p1=solve(2,n-1,(a[0]+a[1]),a,dp1);
         int p2=solve(0,n-3,(a[n-1]+a[n-2]),a,dp2);
         int p3=solve(1,n-2,(a[0]+a[n-1]),a,dp3);
        
        return 1+max(p1,max(p2,p3));
        
        
        
    }
};
