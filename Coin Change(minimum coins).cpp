You are given an array coins[] represent the coins of different denominations and a target value sum. 
You have an infinite supply of each of the valued coins{coins1, coins2, ..., coinsm}.  
Find the minimum number of coins to make the change. If not possible to make a change then return -1.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int count(int i,vector<int> &coins, int sum,vector<vector<int>>& dp){
        if(sum==0) return 0;
        if(sum<0||i==coins.size()) return INT_MAX;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        int pick= INT_MAX;
        if(coins[i]>0){
            pick= count(i,coins,sum-coins[i],dp);
            if(pick!=INT_MAX) pick++;
        }
        int notpick= count(i+1,coins,sum,dp);
        return dp[i][sum]= min(pick, notpick);
    }
  public:
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        int ans= count(0,coins,sum,dp);
        return (ans!=INT_MAX) ? ans : -1;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends