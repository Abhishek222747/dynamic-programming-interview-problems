Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int minoperation(string& s1, string& s2,int n,int m, vector<vector<int>>& dp){
        //base case
        //1. if n==0 i.e; insert m or s2
        if(n==0) return m;
        //2. if m==0 i.e; delete n or s1
        if(m==0) return n;
        
        //use precomputed value from dp table
        if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
        
        //if last char same. get count for remaining char
        if(s1[n-1]==s2[m-1]) return dp[n-1][m-1]= minoperation(s1,s2,n-1,m-1,dp);
        
        //else perform insert,remove,replace
        return dp[n-1][m-1]= 1+min({minoperation(s1,s2,n,m-1,dp), 
        minoperation(s1,s2,n-1,m,dp), minoperation(s1,s2,n-1,m-1,dp)});
    }
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n= s1.length();
        int m= s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return minoperation(s1,s2,s1.length(),s2.length(),dp);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends