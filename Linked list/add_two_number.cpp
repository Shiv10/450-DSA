// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    
    Node* reverse(Node *head){
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first = reverse(first);
        second = reverse(second);
        int carry=0;
        int d;
        Node *head;
        d = first->data+second->data;
        carry = d/10;
        d = d%10;
        Node *current = new Node(d);
        head = current;
        first = first->next;
        second = second->next;
        while(first && second){
            d = first->data+second->data+carry;
            carry = d/10;
            d = d%10;
            Node* temp = new Node(d);
            current->next = temp;
            current = temp;
            first = first->next;
            second = second->next;
        }
        
        while(first){
            d = first->data+carry;
            carry = d/10;
            d = d%10;
            Node* temp = new Node(d);
            current->next = temp;
            current = temp;
            first = first->next;
        }
        
        while(second){
            d = second->data+carry;
            carry = d/10;
            d = d%10;
            Node* temp = new Node(d);
            current->next = temp;
            current = temp;
            second = second->next;
        }
        
        if(carry==1){
            Node* temp = new Node(1);
            current->next = temp;
        }
        
        head = reverse(head);
        return head;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends