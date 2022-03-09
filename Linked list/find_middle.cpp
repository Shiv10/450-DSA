/**
 * Definition for singly-linked list.

 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int k = 0;
        unordered_map<int, ListNode *> v;
        ListNode *curr = head;

        while (curr)
        {
            v[k] = curr;
            k++;
            curr = curr->next;
        }
        int n = k / 2;
        return v[n];
    }
};