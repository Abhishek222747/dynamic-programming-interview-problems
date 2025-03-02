You are given a string s and an integer k.
In one operation, you can replace the character at any position with the next or previous 
letter in the alphabet (wrapping around so that 'a' is after 'z'). For example, replacing 'a'
with the next letter results in 'b', and replacing 'a' with the previous letter results in 'z'. 
Similarly, replacing 'z' with the next letter results in 'a', and replacing 'z' with the previous 
letter results in 'y'.

Return the length of the longest palindromic subsequence of s that can be obtained after 
performing at most k operations.

 

Example 1:

Input: s = "abced", k = 2

Output: 3

Explanation:

Replace s[1] with the next letter, and s becomes "acced".
Replace s[4] with the previous letter, and s becomes "accec".
The subsequence "ccc" forms a palindrome of length 3, which is the maximum.

Example 2:

Input: s = "aaazzz", k = 4

Output: 6

Explanation:

Replace s[0] with the previous letter, and s becomes "zaazzz".
Replace s[4] with the next letter, and s becomes "zaazaz".
Replace s[3] with the next letter, and s becomes "zaaaaz".
The entire string forms a palindrome of length 6.

 

Constraints:

1 <= s.length <= 200
1 <= k <= 200
s consists of only lowercase English letters.




//Trimmed solution

class Solution {
private:
    // Memoization table
    vector<vector<vector<int>>> dp;

    int solve(string &s, int i, int j, int op) {
        // Base cases
        if (i > j) return 0;
        if (i == j) return 1;

        // Check memoization
        if (dp[i][j][op] != -1) return dp[i][j][op];

        int result = 0;
        // If characters match, proceed inward
        if (s[i] == s[j]) {
            result = solve(s, i + 1, j - 1, op) + 2;
        } else {
            // Option 1: Skip one character from either end
            result = max(solve(s, i + 1, j, op), solve(s, i, j - 1, op));

            // Option 2: Replace characters if operations are available
            if (op > 0) {
                int diff= abs(s[i]-s[j]);
                int cost = min(diff, 26-diff);
                if (op >= cost) {
                    result = max(result, solve(s, i + 1, j - 1, op - cost) + 2);
                }
            }
        }

        // Memoize result
        return dp[i][j][op] = result;
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n= s.length();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(s,0,n-1,k);
    }
};





//same as above but looking like a dumb shit code

class Solution {
private:
    // Functions to find next and previous characters with wrapping
    char nextChar(char c) { return (c == 'z') ? 'a' : c + 1; }
    char prevChar(char c) { return (c == 'a') ? 'z' : c - 1; }

    // Function to calculate minimum steps to convert a to b
    int transformationCost(char a, char b) {
        int forward = (b >= a) ? (b - a) : (26 - (a - b));
        int backward = (a >= b) ? (a - b) : (26 - (b - a));
        return min(forward, backward);
    }

    // Memoization table
    vector<vector<vector<int>>> dp;

    int solve(string &s, int i, int j, int op) {
        // Base cases
        if (i > j) return 0;
        if (i == j) return 1;

        // Check memoization
        if (dp[i][j][op] != -1) return dp[i][j][op];

        int result = 0;
        // If characters match, proceed inward
        if (s[i] == s[j]) {
            result = solve(s, i + 1, j - 1, op) + 2;
        } else {
            // Option 1: Skip one character from either end
            result = max(solve(s, i + 1, j, op), solve(s, i, j - 1, op));

            // Option 2: Replace characters if operations are available
            if (op > 0) {
                int cost = transformationCost(s[i], s[j]);
                if (op >= cost) {
                    result = max(result, solve(s, i + 1, j - 1, op - cost) + 2);
                }
            }
        }

        // Memoize result
        return dp[i][j][op] = result;
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n= s.length();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(s,0,n-1,k);
    }
};
