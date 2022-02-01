// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// Head Recursion - recursive call is the first statement in the function then it’s known as Head Recursion.
// The function doesn’t have to process or perform any operation at the time of calling and all operations are done at returning time.
void print1_to_n(int n)  //Hypothesis
{
    if (n == 0)   // Base Condition
    {
        return;
    }
    print1_to_n(n - 1);
    cout << n << " ";  //Induction
}


// Tail Recursion - recursive call is the last statement in the function then it’s known as Tail Recursion.
// The function has to process or perform any operation at the time of calling and it does nothing at returning time.
void printn_to_1(int n)  //Hypothesis
{
    if (n == 0)   // Base Condition
    {
        return;
    }
    cout << n << " ";  //Induction
    printn_to_1(n - 1);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    print1_to_n(n);
    cout << endl;
    printn_to_1(n);
    return 0;
}
// } Driver Code Ends

//Count Common words with one occurrence
