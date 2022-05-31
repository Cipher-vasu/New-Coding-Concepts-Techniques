/*

*/
#include<bits/stdc++.h>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string st1, st2;      // n -> size of string1
	cin >> st1 >> st2;    // m -> size of string2
	int ind1 = st1.size();
	int ind2 = st2.size();

	//Tabulation - T.C - O(n*m) and S.C - O(n*m)
	vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0));
	//cout << lcs(st1, st2, ind1, ind2, dp);

	for (int i = 1; i <= ind1; i++)
	{
		for (int j = 1; j <= ind2; j++)
		{
			if (st1[i - 1] == st2[j - 1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[ind1][ind2] << endl;
	int len = dp[ind1][ind2];
	string st;
	// TC - O(n+m)
	while (ind1 != 0 || ind2 != 0)
	{
		if (st1[ind1 - 1] == st2[ind2 - 1])
		{
			st.push_back(st1[ind1 - 1]);
			ind1--;
			ind2--;
		}
		else
		{
			if (dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1])
			{
				ind1--;
			}
			else
			{
				ind2--;
			}
		}
	}
	reverse(st.begin(), st.end());
	cout << st;
}