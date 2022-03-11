/*
Josephus Problem
*/
#include<bits/stdc++.h>
using namespace std;

int josephus(vector<int>& seat, int k, int index)
{
	if (seat.size() == 1)
	{
		return seat[0];
	}
	index += (k - 1);
	if (index >= seat.size())
	{
		index %= seat.size();
	}
	seat.erase(seat.begin() + index);
	return josephus(seat, k, index);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> seat;
	for (int i = 0; i < n; i++)
	{
		seat.push_back(i + 1);
	}

	cout << josephus(seat, k, 0);
}