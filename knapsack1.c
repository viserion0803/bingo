#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20] = {0}, total_profit = 0;
    int i, u = capacity;

    for (i = 0; i < n; i++) {
        if (weight[i] > u) break;
        x[i] = 1.0;
        total_profit += profit[i];
        u -= weight[i];
    }

    if (i < n) x[i] = (float)u / weight[i];
    total_profit += x[i] * profit[i];

    printf("\nThe result vector is: ");
    for (i = 0; i < n; i++) printf("%.2f\t", x[i]);
    printf("\nMaximum profit is: %.2f\n", total_profit);
}

int main() {
    float weight[20], profit[20], capacity;
    int n, i, j;
    float ratio[20], temp;

    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the weights and profits of each object:\n");
    for (i = 0; i < n; i++) scanf("%f %f", &weight[i], &profit[i]);
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++) ratio[i] = profit[i] / weight[i];

    // Sort items by profit/weight ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // Swap weights
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                // Swap profits
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    knapsack(n, weight, profit, capacity);
    return 0;
}
