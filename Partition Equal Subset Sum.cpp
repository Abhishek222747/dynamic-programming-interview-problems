Given an array arr[], return true if it can be partitioned into two subsets such that the 
sum of elements in both parts is the same, otherwise, false.
Note: Each element is present in either the first subset or the second subset, but not in both.


//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool checksubset(int sum,int index,vector<int>& arr,vector<vector<int>>& dp){
        //base case
        if(sum==0) return true;
        if(index<0) return false;
        //use precomputed dp table if not -1
        if(dp[index][sum]!=-1) return dp[index][sum];
        //skip if current element is greater
        if(arr[index]>sum) return dp[index][sum]= checksubset(sum,index-1,arr,dp);
        //choose by including and excluding
        return dp[index][sum]= 
        checksubset(sum-arr[index],index-1,arr,dp)||checksubset(sum,index-1,arr,dp);
    }
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        int n= arr.size();
        int sum=0;
        for(auto i: arr) sum+= i;
        if(sum%2) return false;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1)); //you can use sum/2+1 also here
        return checksubset(sum/2,n-1,arr,dp);
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

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends