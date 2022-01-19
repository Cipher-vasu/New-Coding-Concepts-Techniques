/*
The code is for checking whether a linked list is a Palindrome or not
Naive Approach :- We will take a stack and push the value of nodes while traversing the linked list and
                  then we will again traverse the linked list and check whether the value present at node
                  is equal to value present at the top of the stack if for any node value doesn't matches
                  we will return false.
Efficient Approach :- The intuition is to divide the llinked list into two halves and reverse the second
					  half. Then we will traverse both the halves and if value at current node of both
					  halves doesn't matches then the linked list is not a palindrome. If the no of nodes
					  in the linked list are even then we can easily follow the above process but if the
					  no of nodes in the linked list are odd then we have to exclude the middle node from
					  both the halves(in gfg solution) but in the below solution we have avoided this and
					  the reason is explained below
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node* next;
};

Node* reverse(Node* slow)
{
	Node* current = slow;
	Node* prev = NULL;
	while (current != NULL)
	{
		Node* next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

bool check(Node* f_head, Node* s_head)
{
	while (s_head != NULL)
	{
		if (f_head->data != s_head->data)
		{
			return false;
		}
		f_head = f_head->next;
		s_head = s_head->next;
	}
	return true;
}

bool palindrome(Node* head)
{
	/* Naive Approach  TC - O(n) and SC - O(n)
	stack<int> st;
	Node* temp = head;
	while (temp != NULL)
	{
		st.push(temp->data);
		temp = temp->next;
	}
	temp = head;
	while (temp != NULL)
	{
		int val = st.top();
		if (temp->data != val)
		{

			return false;
		}
		temp = temp->next;
		st.pop();
	}
	return true;*/

	//Efficient Approach

	/* the main reason to keep track of node previous of slow is that slow will be the starting node for
	the second half of the linked list therefore its previous node will be the last node of the first half
	for sloving through this approach we have to make the last node of the first half to point to NULL
	as when we will traverse both the halves first half will traverse till the end of the whole linked
	list whereas second half will traverse from middle to end hence segmentation fault will come
	OR
	We can do that when we are comparing the value of nodes of both the halves we will traverse both the
	halves until second half not reaches the NULL so now the first half will neither travel the whole linked
	list.
	Node* prev_slow = NULL;
	*/
	if (head == NULL || head->next == NULL) // our below code will not be able to handle these cases
	{
		return true;
	}
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL)  // when this while loop will end the slow will point to
	{	//the middle node of the linked list if no of nodes are odd and
		// if even then it will point to starting node of the second half of the linked list
		//prev_slow = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	/*Node* middle_node = NULL; // We are not excluding the middle node from the the both the halves of
	if (fast != NULL)           // the linked list let's understand with our linked list originally, our
	{                           // linked list is 1->2->3->2->1 after the above while loop is executed the
		middle_node = slow;     // slow pointer will point to 3 so this will be our first node of our second
		slow = slow->next;      // half after reversing the second half the linked list will become,
	}                           // 1->2->3<-2<-1 and 3 will point to NULL so length of second half is 3 and address of 1 will be returned which will be stored in slow
	prev_slow->next = NULL;*/   // and you will be thinking that length of first half is 2 but it's wrong
	// the length of the first half is also 3 as 2 is pointing to 3.
	// For detail understanding do in the notebook for this case.

	slow = reverse(slow);
	//print(slow);
	bool ans = check(head, slow);

	slow = reverse(slow);  // restoring the original linked list

	/*if (middle_node != NULL)
	{
		middle_node->next = slow;
		//prev_slow->next = middle_node;  // if we are not using prev_slow we do not have to do this as it
		// already pointing to middle node
	}
	/*else
	{   // if we are not using prev_slow we do not have to do this as it will already pointing to
		// first node of the second half
		prev_slow->next = slow;
	}*/

	return ans;
}


Node* Insert(Node* root, int n)
{
	Node* temp = new Node();
	temp->data = n;
	temp->next = NULL;
	if (root == NULL)
	{
		root = temp;
	}
	else
	{
		Node* temp1 = root;
		while (temp1->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return root;
}

void print(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Node* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	//head = Insert(head, 3);
	head = Insert(head, 2);
	head = Insert(head, 1);


	print(head);
	bool ans = palindrome(head);
	cout << ans << endl;
	print(head);
	return 0;
}