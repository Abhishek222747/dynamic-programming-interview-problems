A top secret message containing letters  A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are an FBI agent. You have to determine the total number of ways that message can be decoded.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int solve(string &s,int index,vector<int> &dp){
        int n= s.size();
        //base case
        if(index>=n) return 1;
        
        if(dp[index]!=-1) return dp[index];
        
        int ways=0;
        
        if(s[index]!='0'){
            ways= solve(s,index+1,dp);
        }
        
        if(index+1<n && ((s[index]=='1' && s[index+1]<='9') || 
        (s[index]=='2' && s[index+1]<='6'))){
            ways+= solve(s,index+2,dp);
        }
        
        dp[index]=ways;
        return ways;
    }
  public:
    int countWays(string &s) {
        // Code here
        int n= s.size();
        vector<int> dp(n,-1);
        return solve(s,0,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.countWays(s);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends