/* Activity Selection Problem
This Approach can be used in problems like Merge Intervals,etc
*/
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int> a, vector<int> b) // Comparator function to sort the time intervals according to time interval
{
	if (a[1] != b[1])
	{
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

vector<pair<int, int>> select_activities(vector<vector<int>> &intervals)
{
	vector<pair<int, int>> ans;
	if (intervals.size() == 0) // Edge case if there are no intervals
	{
		return ans;
	}

	// Using C++ sort STL

	// First we will sort both the start and finish vectors according  to finishing time
	sort(intervals.begin(), intervals.end(), cmp);
	// Now, after sorting at index 0 the activity which has lowest finishing time will be present
	ans.push_back({intervals[0][0], intervals[0][1]});
	int end = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++)
	{
		if (end <= intervals[i][0])  // if this activity does not collides with ongoing activity
		{
			ans.push_back({intervals[i][0], intervals[i][1]});
			end = intervals[i][1];
		}
	}

	// Using Priority Queue

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 0; i < intervals.size(); i++)
	{
		pq.push({intervals[i][1], intervals[i][0]}); //p
	}

	int start = pq.top().second;
	end = pq.top().first;
	ans.push_back({start, end});
	pq.pop();

	while (!pq.empty())
	{
		if (pq.top().second >= end)
		{
			start = pq.top().second;
			end = pq.top().first;
			ans.push_back({start, end});
		}
		pq.pop();
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> intervals(n, vector<int>(2));
	for (int i = 0; i < n; i++)
	{
		cin >> intervals[i][0] >> intervals[i][1];
	}
	vector<pair<int, int>> ans = select_activities(intervals);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}