#include<bits/stdc++.h>
using namespace std;

/*Recursive - TC-O(2^n) SC-O(n)
Memoizations - TC-O(n*sum) SC-O(n)+O(n*sum)
int tot_subset_with_sum_k(int index, vector<int>& vec, int k, vector<vector<int>>& dp)
{
	if (k == 0)
	{
		return 1;
	}
	if (index == 0)
	{
		return vec[index] == k ? 1 : 0;
	}
	if (dp[index][k] != -1)
	{
		return dp[index][k];
	}
	int pick = tot_subset_with_sum_k(index - 1, vec, k -  vec[index], dp);
	int not_pick = tot_subset_with_sum_k(index - 1, vec, k, dp);
	return dp[index][k] = pick + not_pick;
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	//vector<vector<int>> dp(n, vector<int>(k + 1, 0));
	//cout << tot_subset_with_sum_k(n - 1, vec, k, dp);
	/* Tabulation TC-O(n*k) SC-O(n*k)
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = 1;
	}
	dp[0][vec[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			int pick = 0;
			if (vec[i] <= j)
			{
				pick = dp[i - 1][j -  vec[i]];
			}
			int not_pick = dp[i - 1][j];
			dp[i][j] = pick + not_pick;
		}
	}
	cout << dp[n - 1][k];*/

	// Space-Optimization TC-O(n*k) SC-O(1)
	vector<int> prev(k + 1, 0);
	prev[0] = 1;
	prev[vec[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		vector<int> curr(k + 1, 0);
		for (int j = 0; j <= k; j++)
		{
			int pick = 0;
			if (vec[i] <= j)
			{
				pick = prev[j -  vec[i]];
			}
			int not_pick = prev[j];
			curr[j] = pick + not_pick;
		}
		prev = curr;
	}
	cout << prev[k];
}