#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> prefix_check(vector<vector<int>>& ans)
{
	vector<vector<int>> pre;
	for (auto vec : ans)
	{
		/*int count_0 = 0;
		int count_1 = 0;*/
		int count = 0;
		int flag = 1;
		for (auto ch : vec)
		{
			if (ch == 1)
			{
				count++;
			}
			else
			{
				count--;
			}
			if (count < 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			pre.push_back(vec);
		}
	}
	return pre;
}

void generate_n_bit(int n, vector<int> temp, int count_0, int count_1, vector<vector<int>>& ans)
{
	if (count_0 + count_1 == n)
	{
		if (count_1 >= count_0)
		{
			ans.push_back(temp);
		}
		return;
	}
	vector<int> temp1 = temp;
	if ((count_1 + count_0) < n)
	{
		temp1.push_back(1);
		generate_n_bit(n, temp1, count_0, count_1 + 1, ans);
		temp.push_back(0);
		generate_n_bit(n, temp, count_0 + 1, count_1, ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> temp;
	vector<vector<int>> ans;
	generate_n_bit(n, temp, 0, 0, ans);
	vector<vector<int>> pre = prefix_check(ans);
	for (int i = 0; i < pre.size(); i++)
	{
		for (int j = 0; j < pre[i].size(); j++)
		{
			cout << pre[i][j];
		}
		cout << endl;
	}

}