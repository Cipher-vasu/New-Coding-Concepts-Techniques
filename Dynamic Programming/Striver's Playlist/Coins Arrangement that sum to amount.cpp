#include<bits/stdc++.h>
using namespace std;

//Recursion - TC>>>>O(2 ^ n) and SC - O(amount)
//Memoization - O(n*amount) and SC - O(amount) + O(n*amount)

/*int total_ways(int index, vector<int>& denominations, int amount, vector<vector<int>>& dp)
{
	//cout << index << " " << amount << endl;
	if (amount == 0)
	{
		return 1;
	}
	if (index == 0)
	{
		if (amount % denominations[0] == 0)
		{
			return 1;
		}
		return 0;
	}
	if (dp[index][amount] != -1)
	{
		return dp[index][amount];
	}
	int take = 0;
	if (denominations[index] <= amount)
	{
		take = total_ways(index, denominations , amount - denominations[index], dp);
	}

	int not_take = total_ways(index - 1, denominations, amount, dp);
	return dp[index][amount] = take + not_take;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> denominations(n);
	for (int i = 0; i < n; i++)
	{
		cin >> denominations[i];
	}
	int amount;
	cin >> amount;

	//Tabulation TC - O(n * amount) SC - O(n * amount)
	vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
	//cout << total_ways(n - 1, denominations, amount, dp);

	/*for (int i = 0; i <= amount; i++) //(wt[0]<=capacity) //Base Case
	{
		if (i % denominations[0] == 0)
		{
			dp[0][i] = 1;
		}
		else
		{
			dp[0][i] = 0;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= amount; j++)
		{
			int take = 0;
			if (denominations[i] <= j)
			{
				take = dp[i][j - denominations[i]];
			}
			int not_take = dp[i - 1][j];
			dp[i][j] = take + not_take;
		}
	}
	cout << dp[n - 1][amount];
	*/
	// Space-Optimised using two rows
	vector<int> prev(amount + 1, 0);
	for (int i = 0; i <= amount; i++)
	{
		if (i % denominations[0] == 0)
		{
			prev[i] = 1;
		}
		else
		{
			prev[i] = 0;
		}
	}
	for (int i = 1; i < n; i++)
	{
		vector<int> curr(amount + 1, 0);
		for (int j = 0; j <= amount; j++)
		{
			int take = 0;
			if (denominations[i] <= j)
			{
				take = curr[j - denominations[i]];
			}
			int not_take = prev[j];
			curr[j] = take + not_take;
		}
		prev = curr;
	}
	cout << prev[amount];
}