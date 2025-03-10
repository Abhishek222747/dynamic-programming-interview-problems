Imagine you have a special keyboard with the following keys: 

Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.

Find maximum numbers of A's that can be produced by pressing keys on the special keyboard N times. 




//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution{
private: 
    long long int solve(int N, vector<int> &dp){
        //base case
        if(N<=6) return N;
        
        if(dp[N]!=-1) return dp[N];
        
        int maxi=0,val;
        for(int b=N-3; b>=1; b--){
            val= (N-b-1)*solve(b,dp);
            if(val>maxi) maxi= val;
        }
        dp[N]= maxi;
        return dp[N];
    }
public:
    long long int optimalKeys(int N){
        // code here
        vector<int> dp(N+1,-1);
        return solve(N,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends