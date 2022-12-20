#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int>& vis, int &time, vector<vector<int>>& t)
{
	vis[node] = 1;
	t[node][0] = ++time;

	for (auto it : adj[node])
	{
		if (vis[it] == 0)
		{
			dfs(it, adj, vis, time, t);
		}
	}
	t[node][1] = ++time;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> adj[n];

	int edges;
	cin >> edges;


	for (int i = 0; i < edges; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	int time = -1;

	vector<int> vis(n, 0);
	vector<vector<int>> t(n, vector<int>(2, 0));

	for (int i = 0; i < n; i++)
	{
		if (vis[i] == 0)
		{
			dfs(i, adj, vis, time, t);
			time++;
		}

	}

	for (int i = 0; i < n; i++)
	{
		cout << t[i][0] << " " << t[i][1] << endl;
	}

}