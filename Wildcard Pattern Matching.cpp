Given two strings pat and txt which may be of different sizes, You have to return true if 
the wildcard pattern i.e. pat, matches with txt else return false. All characters of the 
string pat and txt always belong to the Alphanumeric characters.

The wildcard pattern pat can include the characters '?' and '*'.
'?' – matches any single character.
'*' – matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire txt (not partial txt).




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool solve(string &txt, string &pat, int n, int m, vector<vector<int>> &dp){
        //base case
        if(m==0) return (n==0);
        
        if(dp[n][m]!=-1) return dp[n][m];
        
        if(n==0){
            for(int i=0; i<m; i++){
                if(pat[i]!='*') return dp[n][m]= false;
            }
            return dp[n][m]= true;
        }
        
        if(txt[n-1]==pat[m-1] || pat[m-1]=='?') return dp[n][m]= solve(txt,pat,n-1,m-1,dp);
        
        if(pat[m-1]=='*') return dp[n][m]= solve(txt,pat,n,m-1,dp) || solve(txt,pat,n-1,m,dp);
        
        return dp[n][m]= false;
    }
  
  public:
    /*You are required to complete this method*/
    bool wildCard(string &txt, string &pat) {
        // code here
        int n= txt.size();
        int m= pat.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solve(txt,pat,n,m,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        bool ans = obj.wildCard(text, pat);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends