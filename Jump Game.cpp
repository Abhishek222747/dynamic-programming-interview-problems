Given a array of positive integers arr, where each element denotes the maximum length 
of jump you can cover. Find out if you can make it to the last index starting from the 
first index of the list, return true if you can reach the last index.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    bool solve(vector<int> &arr,int index,vector<int> &dp){
        //base case
        int n= arr.size();
        if(index>=n-1) return true;
        
        if(dp[index]!=-1) return dp[index];
        
        for(int jump=1; jump<=arr[index]; jump++){
            if(solve(arr,index+jump,dp)) return dp[index]=true;
        }
        return dp[index]=false;
    }
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int n= arr.size();
        vector<int> dp(n+1,-1);
        return solve(arr,0,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        int ans = ob.canReach(a);

        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends




                                                         Optimized Solution(Greedy, O(n))

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        int n= arr.size();
       int maxreach=0;
       for(int i=0; i<n; i++){
           if(i>maxreach) return false;
           maxreach= max(maxreach,i+arr[i]);
           if(maxreach>=n-1) return true;
       }
       return false;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        int ans = ob.canReach(a);

        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends