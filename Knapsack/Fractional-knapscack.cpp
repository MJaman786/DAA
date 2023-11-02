#include <stdio.h>

void knapsack(int n, float capacity, float weights[], float profits[]) {
    float solution[15], remainingCapacity, totalProfit = 0.0, totalWeight = 0.0;
    int i;

    remainingCapacity = capacity;

    for (i = 0; i < n; i++) {
        solution[i] = 0.0;
    }

    for (i = 0; i < n; i++) {
        if (weights[i] > remainingCapacity) {
            break;
        }
        solution[i] = 1.0;
        remainingCapacity -= weights[i];
    }
    
    if (i < n) {
        solution[i] = remainingCapacity / weights[i];
    }
    
    printf("Solution Vector is : ");
    for (i = 0; i < n; i++) {
        printf("%d %f ", i, solution[i]);
    }

    for (i = 0; i < n; i++) {
        weights[i] = weights[i] * solution[i];
        profits[i] = profits[i] * solution[i];
    }

    for (i = 0; i < n; i++) {
        totalProfit += profits[i];
        totalWeight += weights[i];
    }
    
    printf("\nMaximum profit is : %f\n", totalProfit);
    printf("Maximum weight is : %f\n", totalWeight);
}

int main() {
    int n;
    float profits[15], weights[15], profitToWeightRatio[15], temp, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &weights[i]);
    }

    printf("Enter the profits of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &profits[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    for (int i = 0; i < n; i++) {
        profitToWeightRatio[i] = profits[i] / weights[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (profitToWeightRatio[j] < profitToWeightRatio[j + 1]) {

                temp = profitToWeightRatio[j];
                profitToWeightRatio[j] = profitToWeightRatio[j + 1];
                profitToWeightRatio[j + 1] = temp;

                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;

                temp = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = temp;
                
            }
        }
    }

    printf("\nThe items are arranged as follows:\n");
    printf("\n\nItems\tWeight\tProfits\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%f\t%f\n", i, weights[i], profits[i]);
    }

    knapsack(n, capacity, weights, profits);
    return 0;
}
/*
Enter the number of items: 7
Enter the weights of items: 2 3 5 7 1 4 1
Enter the profits of items: 10 5 15 7 6 18 3
Enter the knapsack capacity: 15

The items are arranged as follows:


Items   Weight  Profits
0       1.000000        6.000000  
1       2.000000        10.000000 
2       4.000000        18.000000
3       5.000000        15.000000
4       1.000000        3.000000
5       3.000000        5.000000
6       7.000000        7.000000
Solution Vector is : 0 1.000000 1 1.000000 2 1.000000 3 1.000000 4 1.000000 5 0.666667 6 0.000000
Maximum profit is : 55.333332
Maximum weight is : 15.000000
*/
