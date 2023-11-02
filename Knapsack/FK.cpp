#include <iostream>
using namespace std;

void knap(int num, float profit[], float weight[], float cp) {
    float rc = cp;
    float solution[num];
    float total_weight = 0.0, total_profit = 0.0;

    int i; // Declare i here

    for (i = 0; i < num; i++) {
        solution[i] = 0.0;
    }

    for (i = 0; i < num; i++) {
        if (weight[i] > rc) {
            break;
        }
        solution[i] = 1.0;
        rc = rc - weight[i];
    }

    if (i < num) {
        solution[i] = rc / weight[i];
    }

    for (i = 0; i < num; i++) {
        weight[i] = weight[i] * solution[i];
        profit[i] = profit[i] * solution[i];
    }

    for (i = 0; i < num; i++) {
        total_profit += profit[i];
        total_weight += weight[i];
    }

    cout << "Maximum profit is : " << total_profit << endl;
    cout << "Maximum weight is : " << total_weight << endl;
}

int main() {
    int num;
    cout << "Enter the number of Items = ";
    cin >> num;

    float weight[num];
    cout << "Enter the weights of Items = ";
    for (int i = 0; i < num; i++) {
        cin >> weight[i];
    }

    float profit[num];
    cout << "Enter the profits of Items = ";
    for (int i = 0; i < num; i++) {
        cin >> profit[i];
    }

    float capacity;
    cout << "Enter capacity of sack = ";
    cin >> capacity;

    float profit_weight[num];
    for (int i = 0; i < num; i++) {
        profit_weight[i] = profit[i] / weight[i];
    }

    int temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - 1 - i; j++) {
            if (profit_weight[j] < profit_weight[j + 1]) {
                temp = profit_weight[j];
                profit_weight[j] = profit_weight[j + 1];
                profit_weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    cout << "After Sorting in Decreasing Order:\n";
    cout << "-------------------------------------\n";
    cout << "| Item\t | Weight | Profit |   P/W   |\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < num; i++) {
        cout << "|    " << i + 1 << "   |   " << weight[i] << "    |   " << profit[i] << "    |    "
             << profit_weight[i] << "    |\n";
    }

    knap(num, profit, weight, capacity);

    return 0;
}
/*
------ OutPut -------
aman@aman-Latitude-E5470:~$ g++ FK.cpp -o FK.out
aman@aman-Latitude-E5470:~$ ./FK.out
Enter the number of Items = 7
Enter the weights of Items = 2 3 5 7 1 4 1
Enter the profits of Items = 10 5 15 7 6 18 3
Enter capacity of sack = 15
After Sorting in Decreasing Order:
-------------------------------------
| Item	 | Weight | Profit |   P/W   |
-------------------------------------
|    1   |   1    |   6    |    6    |
|    2   |   2    |   10   |    5    |
|    3   |   4    |   18   |    4.5  |
|    4   |   5    |   15   |    3    |
|    5   |   1    |   3    |    3    |
|    6   |   3    |   5    |    1    |
|    7   |   7    |   7    |    1    |
Maximum profit is : 55.3333
Maximum weight is : 15

*/
