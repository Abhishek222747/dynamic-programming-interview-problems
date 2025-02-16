Stickler the thief wants to loot money from n houses arranged in a line. He cannot loot two 
consecutive houses and aims to maximize his total loot. Given an array, arr[] where arr[i] 
represents the amount of money in the i-th house, find the maximum amount he can loot.

//here both dp[n-1] and dp[n] will work as former is 0 based indexing and latter is 1 based with no 
changes except precomputed line


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
class Solution {
  private:
    int maxloot(vector<int>&arr, int n, vector<int> &dp){
        //base case
        if(n<=0) return 0;
        
        //use precomputed value from dp
        if(dp[n-1]!=-1) return dp[n-1];
        
        //include the current and and give gap  && skip the current
        return dp[n-1]= max(arr[n-1]+maxloot(arr,n-2,dp), maxloot(arr,n-1,dp));
    }
  public:
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int>& arr) {
        // Your code here
        int n= arr.size();
        vector<int> dp(n+1, -1);
        return maxloot(arr,n,dp);
    }
};

//{ Driver Code Starts.

int main() {

    // taking total testcases
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

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends