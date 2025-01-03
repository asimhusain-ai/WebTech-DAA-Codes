#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int tsp(int mask, int pos, vector<vector<int>>& graph, vector<vector<int>>& dp) {
    if (mask == (1 << graph.size()) - 1) // All cities visited
        return graph[pos][0]; // Return to start
    if (dp[mask][pos] != -1) return dp[mask][pos]; // Memoized result
    int ans = INT_MAX;
    for (int city = 0; city < graph.size(); city++) {
        if ((mask & (1 << city)) == 0) { // If city not visited
            int newCost = graph[pos][city] + tsp(mask | (1 << city), city, graph, dp);
            ans = min(ans, newCost);
        }
    }
    return dp[mask][pos] = ans; // Store result
}
int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    int n = graph.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, -1)); // DP table
    int result = tsp(1, 0, graph, dp); // Start from city 0
    cout << "Minimum cost of traveling: " << result << endl;
    return 0;
}