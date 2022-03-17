/* Question - Range Sum Query 2D - Immutable
These Aprroaches can be used when we have to find sum of a square/rectangle in a given matrix
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    long long int sum = 0;
    int row1, col1, row2, col2;
    cin >> row1 >> col1 >> row2 >> col2;
    /* Naive Approach
    for(int i=row1;i<=row2;i++)
    {
        for(int j=col1;j<=col2;j++)
        {
            sum+=matrix[i][j];
        }
    }
    cout<<sum<<endl;
    */

    /* Better Approach
    //Computing Prefix
    vector<vector<int>> prefix_sum(row,vector<int>(col));
    for(int i=0;i<row;i++)
    {
        int sum=0;
        for(int j=0;j<col;j++)
        {
            sum+=matrix[i][j];
            prefix_sum[i][j]=sum;
        }
    }
    //Computing Answer
    for(int i=row1;i<=row2;i++)
    {
        sum+=prefix_sum[i][col2];
        if(col1!=0)
        {
            sum-=prefix_sum[i][col1-1];
        }
    }
    cout<<sum<<endl;*/

    // Efficient Approach
    // Computing Prefix
    vector<vector<int>> prefix_sum(row + 1, vector<int>(col + 1));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            prefix_sum[i + 1][j + 1] = matrix[i][j] + prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j];
        }
    }

    // Computing Answer
    sum += prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row1][col2 + 1] - prefix_sum[row2 + 1][col1] + prefix_sum[row1][col1];
    cout << sum << endl;
    return 0;
}