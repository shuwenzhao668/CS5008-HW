#include <stdio.h>

int max(int a, int b) {
    if(a > b){
        return a;
    } return b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    int dp[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    printf("Number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Item values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Item weights:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Knapsack weight capacity: ");
    scanf("%d", &W);

    int maxValue = knapSack(W, wt, val, n);

    printf("Answer: Maximum value: %d\n", maxValue);

    return 0;
}