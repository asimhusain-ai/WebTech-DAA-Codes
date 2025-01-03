#include <iostream>
#include <vector>
#include <string>
using namespace std;
int longestCommonSubsequence(const string& s1, const string& s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1; // Match
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // No match
        }
    }
    return dp[m][n]; // Length of LCS
}
int main() {
    string s1 = "ABCBDAB";
    string s2 = "BDCAB";
    cout << "Length of Longest Common Subsequence: " << longestCommonSubsequence(s1, s2) << endl;
    return 0;
}