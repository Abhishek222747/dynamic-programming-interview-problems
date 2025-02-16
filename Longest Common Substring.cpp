You are given two strings s1 and s2. Your task is to find the length 
of the longest common substring among the given strings.



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int count(string& s1, string& s2,int n,int m,vector<vector<int>>& dp){
        //base case
        if(n==0||m==0||s1[n-1]!=s2[m-1]) return 0;
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(s1[n-1]==s2[m-1]){
            return dp[n][m]= 1+count(s1,s2,n-1,m-1,dp);
        }else{
              return dp[n][m]=0;
        }
    }
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n= s1.size();
        int m= s2.size();
        int res=0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                res= max(res, count(s1,s2,i,j,dp));
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends