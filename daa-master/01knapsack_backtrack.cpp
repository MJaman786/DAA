#include <iostream>
using namespace std;


// using backtracking

int bt(int pr[], int wt[], int w, int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return bt(pr, wt, w, n - 1);
    }
    else
    {              //backtrack
        return max(bt(pr, wt, n, n - 1), pr[n - 1] + bt(pr, wt, w - wt[n - 1], n - 1));
    }
}

int main()
{
    int pr[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int w = 8;
    cout << bt(pr, wt, w, 4);

    return 0;
}