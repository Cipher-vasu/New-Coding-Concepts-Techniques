/*
Unbounded Knapsack - Infinite supply of each item
*/
#include<bits/stdc++.h>
using namespace std;

// Recursion- TC-exponential and SC- O(capacity)
// Memoization - TC (n*capacity) and SC - O(n*capacity)+O(capacity)
/*
int max_steal(int index, vector<int>& wt, vector<int>& val, int capacity, vector<vector<int>>& dp)
{
	if (index == 0)
	{
		return (capacity/wt[0])*val[0];
	}
	if (dp[index][capacity] != -1)
	{
		return dp[index][capacity];
	}
	int take = 0;
	if (wt[index] <= capacity)
	{
		take = val[index] + max_steal(index, wt, val, capacity - wt[index], dp);
	}
	int not_take = max_steal(index - 1, wt, val, capacity, dp);
	return dp[index][capacity] = max(take, not_take);
}
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> wt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> wt[i];
	}
	vector<int> val(n);
	for (int i = 0; i < n; i++)
	{
		cin >> val[i];
	}
	int capacity;
	cin >> capacity;
	//vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
	//cout << max_steal(n - 1, wt, val, capacity, dp);
	// Tabulation - TC-O(n*capacity) SC-O(n*capacity)
	/*for (int i = 0; i <= capacity; i++)
	{
		if (wt[0] <= i)
		{

			dp[0][i] = (i / wt[0]) * (val[0]);
			//cout << (i / wt[0]) << " " << i << " " << dp[0][i] << endl;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			int take = 0;
			if (wt[i] <= j)
			{
				take = val[i] + dp[i][j - wt[i]];
			}
			int not_take = dp[i - 1][j];
			dp[i][j] = max(take, not_take);
		}
	}
	cout << dp[n - 1][capacity];
	*/
	// Space Optimization using 2 rows
	/*vector<int> prev(capacity + 1, 0);
	vector<int> curr(capacity + 1, 0);
	for (int i = 0; i <= capacity; i++)
	{
		if (wt[0] <= i)
		{

			prev[i] = (i / wt[0]) * (val[0]);
			//cout << (i / wt[0]) << " " << i << " " << dp[0][i] << endl;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			int not_take = prev[j];
			int take = 0;
			if (wt[i] <= j)
			{
				take = val[i] + curr[j - wt[i]];
			}
			curr[j] = max(take, not_take);
		}
		prev = curr;
	}
	cout << prev[capacity];
	*/

	// Space Optimization using 1 rows
	vector<int> prev(capacity + 1, 0);
	for (int i = 0; i <= capacity; i++)
	{
		if (wt[0] <= i)
		{

			prev[i] = (i / wt[0]) * (val[0]);
			//cout << (i / wt[0]) << " " << i << " " << dp[0][i] << endl;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			int not_take = prev[j];
			int take = 0;
			if (wt[i] <= j)
			{
				take = val[i] + prev[j - wt[i]];
			}
			prev[j] = max(take, not_take);
		}
	}
	cout << prev[capacity];
}