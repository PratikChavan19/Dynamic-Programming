#include <iostream>
#include <vector>
using namespace std;

int knapsackRec(int W, vector<int> &val, vector<int> &wt, int n, 
                                        vector<vector<int>> &memo)
{

    // Base Case
    if (n == 0 || W == 0)
    {
        return 0;
    }

    if(memo[n][W] != -1)
    {
        return memo[n][W];
    }

    int pick = 0;

    if (wt[n - 1] <= W)
    {
        pick = val[n - 1] + knapsackRec(W - wt[n - 1], val, wt, n - 1, memo);
    }
    
    int notPick = knapsackRec(W, val, wt, n - 1, memo);
    
    return memo[n][W] = max(pick, notPick);
}

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    
    vector<vector<int>> memo(n + 1, vector<int>(W + 1, -1));
    
    return knapsackRec(W, val, wt, n, memo);
}

int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    cout << knapsack(W, val, wt) << endl;
    return 0;
}