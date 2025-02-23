Given a string s and a dictionary of n words dictionary, find out if "s" can be segmented into
 a space-separated sequence of dictionary words.
Return 1 if it is possible to break the s into a sequence of dictionary words, else return 0. 

Note: From the dictionary dictionary each word can be taken any number of times and in any order.



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
private:
    int solve(string str, vector<string> &d, unordered_map<string,int>& dp){
        //base case
        if(str.empty()) return 1;
        
        if(dp.find(str)!=dp.end()) return dp[str];
        int n= str.size();
        unordered_set<string> dict(d.begin(), d.end());

        for(int i=1; i<=n; i++){
            string prefix= str.substr(0, i);
            if(dict.count(prefix) && solve(str.substr(i),d,dp)) 
            return dp[str]=1;
        }
        return dp[str]=0;;
    }
public:
    int wordBreak(int n, string str, vector<string> &d) {
        //code here
        unordered_map<string,int> dp;
        return solve(str,d,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends