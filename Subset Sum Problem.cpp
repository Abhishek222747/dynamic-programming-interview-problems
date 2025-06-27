Given an array of positive integers arr[] and a value sum, determine if there is 
a subset of arr[] with sum equal to given sum. 


class Solution {
  private: 
    bool solve(vector<int>& arr,int sum,int index,vector<vector<int>>& dp){
        int n= arr.size();
        if(sum==0) return true;
        if(index==n) return false;
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        bool take= false;
        if(sum>=arr[index]){
            take= solve(arr,sum-arr[index],index+1,dp);
        }
        bool not_take= solve(arr,sum,index+1,dp);
        
        return dp[index][sum]= take ||not_take;
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n= arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
    }
};