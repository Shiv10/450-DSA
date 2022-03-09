
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



class Solution{
  public:
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        Node* curr = head;
        
        vector<int> v;
        int i, l =0;
        
        while(curr) {
            v.push_back(curr->data);
            curr = curr->next;
        }
        
        
        l = v.size();
        
        while(head) {
            if(head->data!=v[l-1]) return false;
            l--;
            head=head->next;
        }
        
        return true;
    }
};



int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends