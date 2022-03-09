// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        // Your code here
        int n = s.length();
        int top = -1;
        char stack[n];
        unordered_map<char, char> v;
        v[']'] = '[';
        v[')'] = '(';
        v['}'] = '{';
        for(int i=0;i<n;i++){
            if(top==-1) {
                stack[++top] = s[i];
                continue;
            }
            
            if(s[i]==']' || s[i] == ')' || s[i] == '}') {
                char c = s[i];
                if(v[c]==stack[top]) {
                    top--;
                } else {
                    stack[++top] = c;
                }
            } else {
                stack[++top] = s[i];
            }
        }
        
        return top==-1;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends