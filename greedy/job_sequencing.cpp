#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int, int>> v;
        int i;
        int mdead=0;
        for(i = 0; i<n; i++) {
            pair<int, int> p;
            p.first = arr[i].profit;
            p.second = arr[i].dead;
            if(p.second>mdead) {
                mdead = p.second;
            }
            v.push_back(p);
        }
        
        vector<int> a(mdead+1,-1);
        
        sort(v.begin(), v.end());
        
        // for(int x=n-1;x>-1;x--) {
        //     cout<<v[x].first<<" "<<v[x].second<<endl;
        // }
        
        

        
        for(i=n-1;i>-1;i--) {
            int j = v[i].second;
            while(j>0){
                if(a[j]==-1) {
                    a[j] = v[i].first;
                    break;
                }
                j--;
            }
        }
        
        int mp = 0, c= 0;
        for(auto x: a) {
            if(x!=-1) {
                mp+=x;
                c++;
            }
        }

        vector<int> temp(2);
        temp[0] = c;
        temp[1] = mp;
        
        return temp;
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends