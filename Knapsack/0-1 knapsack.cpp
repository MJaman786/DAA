#include <iostream>
using namespace std;

// This function returns the maximum value that can be
// put in the knapsack of capacity W
int knapsack(int W, int wt[], int val[], int n) {
  // Create a table to store the results
  int dp[n + 1][W + 1];

  // Initialize the table
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= W; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
      } else if (wt[i - 1] <= j) {
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  // Return the maximum profit
  return dp[n][W];
}

// Driver code
int main() {
  int W = 10;
  int wt[] = {2, 3, 5, 7};
  int val[] = {1, 4, 5, 7};
  int n = sizeof(wt) / sizeof(wt[0]);

  // Print the maximum profit
  cout << knapsack(W, wt, val, n) << endl;

  return 0;
}