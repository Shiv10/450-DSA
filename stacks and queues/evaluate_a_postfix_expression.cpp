#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        stack<char> st;
        stack<int> val;
        unordered_map<char, int> nums;
        nums['1'] = 1;
        nums['2'] = 2;
        nums['3'] = 3;
        nums['4'] = 4;
        nums['5'] = 5;
        nums['6'] = 6;
        nums['7'] = 7;
        nums['8'] = 8;
        nums['9'] = 9;
        nums['0'] = 0;
    
        int n = s.length();
        int i=n-1;
        while(i>-1) {
            st.push(s[i--]);
        }
        
        while(!st.empty()){
            if(st.top()=='+' || st.top()=='*' || st.top()=='/' || st.top()=='-'){
                
                char op = st.top();
                
                int second = val.top();
                val.pop();
                int first = val.top();
                val.pop();
                
                int result;
                
                if(op=='+') {
                    result = first + second;
                } else if (op=='-') {
                    result = first - second;
                } else if (op=='*') {
                    result = first * second;
                } else if (op=='/') {
                    result = first / second;
                }
                
                val.push(result);
            
            } else {
                // cout<<nums[st.top()]<<" ";
                val.push(nums[st.top()]);
            }
            st.pop();
        }
        return val.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}