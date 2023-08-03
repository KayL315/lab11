/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int minCoins(int coins[], int n, int amount) {
    int INF = 1e9; 
    int dp[amount + 1]; 

    for (int i = 0; i <= amount; i++) {
        dp[i] = INF;
    }


    dp[0] = 0;

    // Calculate the minimum number of coins needed for each amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                if (dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if (dp[amount] == INF) {
        return -1;
    }

    return dp[amount];
}

int main() {
    int numCoins;
    printf("Number of values of coins: ");
    scanf("%d", &numCoins);

    int coins[numCoins];
    printf("Coins:\n");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, numCoins, amount);
    printf("Answer: %d\n", result);

    return 0;
}
