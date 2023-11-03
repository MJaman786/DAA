#include <iostream>
#include <cmath>

using namespace std;

int x[20];
int count;

void print(int n) {
    cout << "\n\nSolution " << ++count << ":\n\n";
    for (int i = 1; i <= n; i++) {
        cout << "\t" << i;
    }
    for (int i = 1; i <= n; i++) {
        cout << "\n\n" << i;

        for (int j = 1; j <= n; j++) {
            if (x[i] == j) {
                cout << "\tQ";
            } else {
                cout << "\t-";
            }
        }
        cout << "\n";
    }
    cout << "\nPress any key to continue...";
    cin.get();
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
    cout << "Program of N-Queens using backtracking\n";
    cout << "Enter the number of queens: ";
    cin >> n;
    if (n < 1 || n > 20) {
        cout << "Invalid input. Please enter a number between 1 and 20.\n";
        return 1;
    }
    count = 0;
    Queen(1, n);
    cin.get();
    return 0;
}
