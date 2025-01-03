#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; ++len) {    
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {   
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}
int main() {
    vector<int> dimensions = {1, 2, 3, 4};
    cout << "Minimum number of multiplications is " << matrixChainOrder(dimensions) << endl;
    return 0;
}