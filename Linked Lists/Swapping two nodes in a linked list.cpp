/* Swapping two Nodes in a Linked List
Problem Statement - Swap kth node from beginning with kth node from end
This may look like a simple problem, but is an interesting question as it has the following cases
 to be handled.
x and y may or may not be adjacent.
Either x or y may be a head node.
Either x or y may be the last node.
x and/or y may not be present in the linked list.

Naive Approach - Just locate kth node from beginning and end and exchange their data values

What if we are not allowed to exchange values but we have to swap two nodes/
Approach:-
1. First we will find our first node and the node previous to it.
2. Then we will find our second node and the node previous to it.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* Swap_2_nodes(Node *head, int k)
{
    Node* temp = head;
    Node* first = head;
    Node* prev_first = NULL;
    // Finding Kth node from beginning
    while (k > 1)
    {
        temp = temp->next;
        prev_first = first;
        first = first->next;
        k--;
    }

    // Finding Kth node from end
    Node* second = head;
    Node* prev_second = NULL;
    while (temp->next != NULL)
    {
        prev_second = second;
        second = second->next;
        temp = temp->next;
    }

    // If either of the nodes is not present in the list then we cannot swap
    if (first == NULL || second == NULL)
    {
        return head;
    }

    // If Kth node from beginning and end is same then there is no point in swapping the nodes
    if (first == second)
    {
        return head;
    }

    // If our first node is head node of the linked list then we will make our second node as head node
    //otherwise we will make the node previous to first node to point to second node
    if (prev_first != NULL)
    {
        prev_first->next = second;
    }
    else
    {
        head = second;
    }

    // If our second node is head node of the linked list then we will make our first node as head node
    //otherwise we will make the node previous to second node to point to first node
    if (prev_second != NULL)
    {
        prev_second->next = first;
    }
    else
    {
        head = first;
    }

    // Swapping the next pointers of first and second node
    Node* next = first->next;
    first->next = second->next;
    second->next = next;

    return head;
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
    head = Insert(head, 4);
    head = Insert(head, 5);
    int k;
    cin >> k;

    print(head);
    head = Swap_2_nodes(head, k);
    print(head);
    return 0;
}
