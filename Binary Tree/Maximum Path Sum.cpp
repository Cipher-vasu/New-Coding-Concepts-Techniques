#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		data = val;
		left = right = NULL;
	}
};

int calcPathSum(Node* root, int& maxi)
{
	if (root == NULL)
	{
		return 0;
	}
	int leftsum = max(0, calcPathSum(root->left, maxi));
	int rightsum = max(0, calcPathSum(root->right, maxi));
	int path_sum = root->data + leftsum + rightsum;
	maxi = max(maxi, path_sum);
	return path_sum - min(leftsum, rightsum);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	struct Node* root = new Node(-10);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->right = new Node(7);
	root->right->left = new Node(9);
	queue<pair<Node*, int>> q;
	int l = 1;

	int maxi = 0;
	cout << calcPathSum(root, maxi) << endl;
	cout << maxi;
}
