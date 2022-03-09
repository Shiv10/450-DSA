#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    vector<int> v;
    cin>>n;
    for(i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    for(i=0;i<n/2;i++){
        int temp;
        temp = v[i];
        v[i] = v[n-i-1];
        v[n-i-1] = temp;
    }

    for(auto x: v){
        cout<<x<<endl;
    }
    return 0;
}