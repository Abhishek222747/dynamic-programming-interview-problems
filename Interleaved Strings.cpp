Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
Interleaving of two strings s1 and s2 is a way to mix their characters to form a new string s3, 
while maintaining the relative order of characters from s1 and s2. Conditions for interleaving:

Characters from s1 must appear in the same order in s3 as they are in s1.
Characters from s2 must appear in the same order in s3 as they are in s2.
The length of s3 must be equal to the combined length of s1 and s2.


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    bool check(string& s1, string& s2, string& s3, int i, int j,vector<vector<int>>& dp){
        int k=i+j;
        //base case
        if(i==s1.size() && j==s2.size() && k==s3.size()) return true;
        
        //use precomputed value from dp table
        if(dp[i][j]!=-1) return dp[i][j];
        
        //move forward on each string one by one
        bool a= (i<s1.size()) && (s3[k]==s1[i]) && check(s1,s2,s3,i+1,j,dp);
        bool b= (j<s2.size()) && (s3[k]==s2[j]) && check(s1,s2,s3,i,j+1,dp);
        
        return dp[i][j]= a||b;
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string& s1, string& s2, string& s3) {
        // Your code here
        int n= s1.size();
        int m= s2.size();
        if(n+m!=s3.size()) return false;
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return check(s1,s2,s3,0,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        if (obj.isInterleave(a, b, c))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends