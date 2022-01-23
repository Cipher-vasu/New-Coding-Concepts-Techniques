#include<bits/stdc++.h>
using namespace std;

#define size 5      // given maximum size of array
int top;            // variable to store the index where last element was pushed

void push(vector<int> &st, int x)
{
	if (top == (size - 1))    // if this condition is it means that our array/stack is full an no more elements can be inserted in array/stack
	{
		cout << "Stack Overflow" << endl;
	}
	else
	{
		st[++top] = x;  // otherwise increment the top and insert the element in array/stack
	}
}

void pop(vector<int> &st)
{
	if (top == -1)  // no element has yet been inserted so there is nothing to pop
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		top--;  // otherwise exclude the last element inserted by decrementing the top pointer
	}
}

int attop(vector<int> &st)
{
	if (top == -1)    // no element has yet been inserted so there is no element at top of stack
	{
		return -1;
	}
	else
	{
		return st[top];  // otherwise return the last element inserted in the stack
	}
}

bool isEmpty(std::vector<int> &st)
{
	if (top == -1)  //no element has yet been inserted so our stack is empty
	{
		return true;
	}
	return false;
}

void print_stack(vector<int> &st)
{
	if (top == -1)  // no element has yet been inserted so nothing to print
	{
		cout << "stack is empty" << endl;
		return;
	}
	for (int i = 0; i <= top; i++)
	{
		cout << st[i] << " ";
	}
	cout << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	top = -1;
	vector<int> st(size);
	cout << isEmpty(st) << endl;
	print_stack(st);
	pop(st);
	push(st, 1);
	push(st, 2);
	push(st, 3);
	cout << attop(st) << endl;
	print_stack(st);
	pop(st);
	print_stack(st);
	push(st, 3);
	push(st, 4);
	push(st, 5);
	print_stack(st);
	cout << isEmpty(st) << endl;
	push(st, 6);
	return 0;

}