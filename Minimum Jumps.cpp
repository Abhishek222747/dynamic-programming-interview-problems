You are given an array arr[] of non-negative numbers. Each number tells you the maximum 
number of steps you can jump forward from that position.

For example:
If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first 
position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.



class Solution {
  private: 
    int solve(int i,vector<int>& arr,vector<int>& dp){
        if(i>=arr.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int res=INT_MAX;
        for(int j=i+1; j<=i+arr[i] && j<arr.size(); j++){
            int val= solve(j,arr,dp);
            if(val!=INT_MAX)
            res= min(res,1+val);
        }
        dp[i]=res;
        return dp[i];
    }
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n= arr.size();
        vector<int> dp(n+1,-1);
        int ans= solve(0,arr,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
