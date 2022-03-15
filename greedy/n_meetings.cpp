// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, int>> v;
        int i;
        for (i=0;i<n;i++) {
            pair<int, int> p;
            p.first = end[i];
            p.second = i;
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        int c = 1;
        pair<int, int> temp;
        temp = v[0];
        
        
        for(i=1;i<n;i++) {
            if (start[v[i].second]>temp.first) {
                temp = v[i];
                c++;
            }
        }
        
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends