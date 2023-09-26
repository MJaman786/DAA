#include <iostream>
#include <algorithm>
using namespace std;

double fractional_knapsack(int wt[], int val[], int num, int cp) {
  // Sort the items in decreasing order of value per weight.
  double new_arr[num];
  for (int i = 0; i < num; i++) {
    new_arr[i] = (wt[i]) / (val[i]);
  }

  sort(new_arr, new_arr + num, greater<>());

  // Initialize the total value and weight.
  double total_value = 0.0;
  double total_weight = 0.0;

  // Iterate over the items and add them to the knapsack until the capacity is reached.
  for (int i = 0; i < num; i++) {
    if (total_weight + wt[i] <= cp) {
      total_value += val[i];
      total_weight += wt[i];
    } else {
      // Add a fraction of the item to the knapsack.
      double fraction = (cp - total_weight) / wt[i];
      total_value += fraction * val[i];
      total_weight += fraction * wt[i];
      break;
    }
  }

  return total_value;
}

int main() {
  int num, cp;
  cout << "Enter the number of Iteams    = ";
  cin >> num;
  cout << "\nEnter the capacity of scack = ";
  cin >> cp;

  int wt[num], val[num];
  cout << "\nEnter the weights of Iteam = ";
  for (int i = 0; i < num; i++) {
    cin >> wt[i];
  }
  cout << "\nEnter the profit of Iteams = ";
  for (int i = 0; i < num; i++) {
    cin >> val[i];
  }

  double new_arr[num];
  for (int i = 0; i < num; i++) {
    new_arr[i] = (wt[i]) / (val[i]);
  }

  for (int i = 0; i < num; i++) {
    cout << new_arr[i] << " ";
  }

  cout << endl;

  double max_value = fractional_knapsack(wt, val, num, cp);
  cout << "The maximum value that can be placed in the knapsack is: " << max_value
       << endl;

  return 0;
}

/*
Number of items: 3
Capacity of knapsack: 50
Weights: 10, 20, 30
Values: 60, 100, 120

0.6 0.5 0.4
The maximum value that can be placed in the knapsack is: 240.0
*/