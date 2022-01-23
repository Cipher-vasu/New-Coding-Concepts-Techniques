#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* top;

void push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = top;
	top = temp;
}

void pop()
{
	if (top == NULL)  // no element has yet been inserted so there is nothing to pop
	{
		cout << "Stack Underflow" << endl;
	}
	else
	{
		Node* temp = top; // otherwise exclude the last element inserted by decrementing the top pointer
		top = top->next;
		delete(temp);
	}
}

int attop()
{
	if (top == NULL)    // no element has yet been inserted so there is no element at top of stack
	{
		return -1;
	}
	else
	{
		return top->data;  // otherwise return the last element inserted in the stack
	}
}

bool isEmpty()
{
	if (top == NULL)  //no element has yet been inserted so our stack is empty
	{
		return true;
	}
	return false;
}

void print_stack()
{
	if (top == NULL)  // no element has yet been inserted so nothing to print
	{
		cout << "stack is empty" << endl;
		return;
	}
	Node* temp = top;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	top = NULL;
	cout << isEmpty() << endl;
	print_stack();
	pop();
	push( 1);
	push( 2);
	push( 3);
	cout << attop() << endl;
	print_stack();
	pop();
	print_stack();
	push( 3);
	push( 4);
	push( 5);
	print_stack();
	cout << isEmpty() << endl;
	push(6);
	return 0;

}