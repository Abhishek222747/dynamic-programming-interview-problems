Given an integer array coins[ ] representing different denominations of currency and an integer sum,
find the number of ways you can make sum by using different combinations from coins[ ]. 
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin 
as many times as you want.
Answers are guaranteed to fit into a 32-bit integer.


                                         // 1st ways 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int coincount(vector<int> &coins,int n,int sum,vector<vector<int>>& dp){
        //base case
        if(sum==0) return 1; //1 ways by choosing nothing
        if(sum<0 || n==0) return 0;
        
        //use precomputed value from table
        if(dp[n-1][sum]!=-1) return dp[n-1][sum];
        
        //count by including and excluding
        return dp[n-1][sum]= 
        coincount(coins,n,sum-coins[n-1],dp)+coincount(coins,n-1,sum,dp);
    }
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return coincount(coins,n,sum,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends


                                            // 2nd ways 


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int coincount(vector<int> &coins,int index,int sum,vector<vector<int>>& dp){
        //base case
        if(sum==0) return 1; //1 ways by choosing nothing
        if(sum<0 || index<0) return 0;
        
        //use precomputed value from table
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        //count by including and excluding
        return dp[index][sum]= 
        coincount(coins,index,sum-coins[index],dp)+coincount(coins,index-1,sum,dp);
    }
  public:
    int count(vector<int>& coins, int sum) {
        // code here.
        int n= coins.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return coincount(coins,n-1,sum,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends