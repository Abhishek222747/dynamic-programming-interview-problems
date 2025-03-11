Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting
some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.



//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int solve(string &s,int i,int j,vector<vector<int>> &dp){
        //base case
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int res;
        if(s[i]==s[j]){
            res= 2+solve(s,i+1,j-1,dp);
        }
        else{
            res= max(solve(s,i+1,j,dp), solve(s,i,j-1,dp));
        }
        dp[i][j]=res;
        return dp[i][j];
    }
  public:
    int longestPalinSubseq(string &s) {
        // code here
        int n= s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return solve(s,0,n-1,dp);
    }
};


//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends