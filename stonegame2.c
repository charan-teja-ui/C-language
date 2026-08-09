#include <stdlib.h>

int n;
int suffix[105];
int memo[105][105];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int dp(int i, int M) {
    if (i >= n)
        return 0;

    if (i + 2 * M >= n)
        return suffix[i];

    if (memo[i][M] != -1)
        return memo[i][M];

    int opponent = suffix[i];

    for (int X = 1; X <= 2 * M && i + X <= n; X++) {
        int nextM = max(M, X);

        opponent = min(opponent, dp(i + X, nextM));
    }

    memo[i][M] = suffix[i] - opponent;

    return memo[i][M];
}

int stoneGameII(int* piles, int pilesSize) {
    n = pilesSize;

    suffix[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        suffix[i] = suffix[i + 1] + piles[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            memo[i][j] = -1;
        }
    }

    return dp(0, 1);
}
