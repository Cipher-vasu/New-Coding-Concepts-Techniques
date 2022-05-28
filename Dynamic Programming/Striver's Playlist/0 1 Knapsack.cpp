#include<bits/stdc++.h>
using namespace std;

//Recursion - O(2 ^ n) and SC - O(n)
//Memoization - O(n*capacity) and SC - O(n) + O(n*capacity)
/*int max_money(int index, vector<int>& wt, vector<int>& val, int capacity, vector<vector<int>>& dp)
{
	if (index == 0)
	{
		if (wt[0] <= capacity)
		{
			return val[index];
		}
		return 0;
	}
	if (dp[index][capacity] != -1)
	{
		return dp[index][capacity];
	}
	int steal = INT_MIN;
	if (wt[index] <= capacity)
	{
		steal = val[index] + max_money(index - 1, wt, val, capacity - wt[index], dp);
	}
	int not_steal = max_money(index - 1, wt, val, capacity, dp);
	return dp[index][capacity] = max(steal, not_steal);
}*/

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

	/* Tabulation TC - O(n*capacity) SC - O(n*capacity)
	vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
	//cout << max_money(n - 1, wt, val, capacity, dp);
	for (int i = wt[0]; i <= capacity; i++) //(wt[0]<=capacity) //Base Case
	{
		dp[0][i] = val[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			int steal = INT_MIN;
			if (wt[i] <= j)
			{
				steal = val[i] + dp[i - 1][j - wt[i]];
			}
			int not_steal = dp[i - 1][j];
			dp[i][j] = max(steal, not_steal);
		}
	}
	cout << dp[n - 1][capacity];*/

	/* Space-Optimised using two rows
	vector<int> prev(capacity + 1, 0);
	for (int i = wt[0]; i <= capacity; i++)
	{
		prev[i] = val[0];
	}
	for (int i = 1; i < n; i++)
	{
		vector<int> curr(capacity + 1, 0);
		for (int j = 0; j <= capacity; j++)
		{
			int steal = INT_MIN;
			if (wt[i] <= j)
			{
				steal = val[i] + prev[j - wt[i]];
			}
			int not_steal = prev[j];
			curr[j] = max(steal, not_steal);
		}
		prev = curr;
	}
	cout << prev[capacity - 1];*/

	// Space-Optimised using one rows
	vector<int> prev(capacity + 1, 0);
	for (int i = wt[0]; i <= capacity; i++)
	{
		prev[i] = val[0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = capacity; j >= 0; j--)
		{
			int steal = INT_MIN;
			if (wt[i] <= j)
			{
				steal = val[i] + prev[j - wt[i]];
			}
			prev[j] = max(steal, prev[j]);
		}
	}
	cout << prev[capacity];
}