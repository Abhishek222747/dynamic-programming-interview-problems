You are given n identical eggs and you have access to a k-floored building from 1 to k.

There exists a floor f where 0 <= f <= k such that any egg dropped from a floor higher 
than f will break, and any egg dropped from or below floor f will not break.
There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the egg breaks on a certain floor, it will break on any floor above.
Return the minimum number of moves you need to determine the value of f with certainty.


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solveegg(int n,int k,vector<vector<int>>& memo){
        //base case
        if(k==1 || k==0) return k;
        if(n==1) return k;
        
        if(memo[n][k]!=-1) return memo[n][k];
        
        int min= INT_MAX;
        for(int x=1; x<=k; x++){
            int res= max(solveegg(n-1,x-1,memo), solveegg(n,k-x,memo));
            if(res<min) min= res;
        }
        return memo[n][k]= 1+min;
    }
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // your code here
        vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));
        return solveegg(n,k,memo);
    }
};

//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends