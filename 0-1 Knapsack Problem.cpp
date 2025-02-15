You are given the weights and values of items, and you need to put these items in a knapsack of capacity capacity to achieve the maximum total value in the knapsack. Each item is available in only one quantity.

In other words, you are given two integer arrays val[] and wt[], which represent the values and weights associated with items, respectively. You are also given an integer capacity, which represents the knapsack capacity. Your task is to find the maximum sum of values of a subset of val[] such that the sum of the weights of the corresponding subset is less than or equal to capacity. You cannot break an item; you must either pick the entire item or leave it (0-1 property).

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int knapsackhelper(int w,vector<int> &val, vector<int> &wt,int index,vector<vector<int>>& memo){
        //base case
        if(index<0) return 0;
        //use pre calculated value if not -1
        if(memo[index][w]!=-1) return memo[index][w];
        //store the value in table say business logic
        if(wt[index]>w){
            //skip the current if its weight is greater
            memo[index][w]= knapsackhelper(w,val,wt,index-1,memo);
        }else{
            //find max by including and excluding
            memo[index][w]= max(val[index]+knapsackhelper(w-wt[index],val,wt,index-1,memo),
            knapsackhelper(w,val,wt,index-1,memo));
        }
        return memo[index][w];
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n= wt.size();
        vector<vector<int>> memo(n, vector<int>(capacity+1,-1));
        return knapsackhelper(capacity,val,wt,n-1,memo);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends