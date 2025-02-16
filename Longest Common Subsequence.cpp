Given two strings s1 and s2, return the length of their longest common subsequence (LCS). 
If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements 
without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  private:
    int lcscount(string& s1, string& s2, int n, int m,vector<vector<int>>& dp){
        //base class
        if(n==0||m==0) return 0;
        
        //use precomputed value from dp table
        if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
        
        //if last charaters in both string are matching
        if(s1[n-1]==s2[m-1]){
            return dp[n-1][m-1]= 1+lcscount(s1,s2,n-1,m-1,dp);
        }//if characters are not matching
        else{
            return dp[n-1][m-1]= 
            max(lcscount(s1,s2,n-1,m,dp), lcscount(s1,s2,n,m-1,dp));
        }
    }
  public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(string& s1, string& s2) {
        // your code here
        int n= s1.size();
        int m= s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return lcscount(s1,s2,n,m,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2; // Take both the strings as input
        Solution ob;
        cout << ob.lcs(s1, s2) << endl; // Call the lcs function
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends