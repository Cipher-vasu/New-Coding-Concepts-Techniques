#include<bits/stdc++.h>
using namespace std;

int bfs(int node, vector<int> adj[], int boardSize)
{
	queue<pair<int, int>> q;
	q.push({node, 0});

	vector<int> vis(boardSize, 0);
	vis[node] = 1;

	while (!q.empty())
	{
		int currPos = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (currPos == boardSize)
		{
			return dist;
		}

		for (auto it : adj[currPos])
		{
			if (vis[it] == 0)
			{
				vis[it] = 1;
				q.push({it, dist + 1});
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int boardSize = n * m;

	int ladders;
	cin >> ladders;
	unordered_map<int, int> ladder;
	for (int i = 0; i < ladders; i++)
	{
		int u, v;
		cin >> u >> v;
		ladder[u] = v;
	}

	int snakes;
	cin >> snakes;
	unordered_map<int, int> snake;
	for (int i = 0; i < snakes; i++)
	{
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	vector<int> adj[boardSize + 1];

	for (int i = 1; i <= boardSize + 1; i++)
	{
		for (int j = 1; j <= 6 && i + j <= (boardSize + 1); j++)
		{
			int src = i;
			int dest = 0;

			if (ladder.find(i + j) != ladder.end())
			{
				dest = ladder[i + j];
			}
			else if (snake.find(i + j) != snake.end())
			{
				dest = snake[i + j];
			}
			else
			{
				dest = i + j;
			}

			adj[src].push_back(dest);
		}
	}

	cout << bfs(1, adj, boardSize + 1) << endl;



}