Given an array arr of non-negative integers and an integer target, 
the task is to count all subsets of the array whose sum is equal to the given target.

class Solution {
  public:
    int mod= 1e9+7;
    
    int countsubset(vector<int>& arr,int n,int target,vector<vector<int>>& dp){
        //base case
        if(n==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0) return 1;
            if(target==arr[0]) return 1;
            return 0;
        }
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        if(arr[n]>target) return dp[n][target]= countsubset(arr,n-1,target,dp);
        
        int include= countsubset(arr,n-1,target-arr[n],dp);
        int exclude= countsubset(arr,n-1,target,dp);
        
        return dp[n][target]= (include+exclude)%mod;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n= arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans= countsubset(arr,n-1,target,dp);
        return ans;
    }
};