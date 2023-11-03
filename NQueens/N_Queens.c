#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>

int x[20];
int count;

void print(int n) {
    printf("\n\nSolution %d :\n\n", ++count);
    for (int i = 1; i <= n; i++) {
        printf("\t%d", i);
    }
    for (int i = 1; i <= n; i++) {
        printf("\n\n%d", i);

        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                printf("\tQ");
            } else {
                printf("\t-");
            }
        }
        printf("\n");
    }
    printf("\nPress any key to continue...");
    getch();
}

int place(int row, int column) {
    for (int i = 1; i <= row - 1; i++) {
        if (x[i] == column || abs(x[i] - column) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void Queen(int row, int n) {
    int column;
    for (column = 1; column <= n; column++) {
        if (place(row, column)) {
            x[row] = column;
            if (row == n) {
                print(n);
            } else {
                Queen(row + 1, n);
            }
        }
    }
}

int main() {
    int n;
    printf("Program of N-Queens using backtracking\n");
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n < 1 || n > 20) {
        printf("Invalid input. Please enter a number between 1 and 20.\n");
        return 1;
    }
    count = 0;
    Queen(1, n);
    getch();
    return 0;
}
