// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


 // } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    int addNumber(Node *current){
        int carry;
        if(current->next){
            carry = addNumber(current->next);
        } else {
            int d;
            d = current->data+1;
            if(d>9){
                current->data = d%10;
                return 1;
            } else {
                current->data = d;
                return 0;
            }
        }
        
        int d;
        d = current->data+carry;
        if(d>9){
            current->data = d%10;
            return 1;
        } else {
            current->data = d;
            return 0;
        }
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        int carry = addNumber(head);
        if(carry==0) return head;
        else {
            Node *temp =new Node(1);
            temp->next = head;
            head = temp;
            return head;
        }
        return NULL;
    }
    
    
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 
  // } Driver Code Ends