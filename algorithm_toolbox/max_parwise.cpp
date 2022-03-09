#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n, a, prod;
    cin>>n;
    vector<long long int> v;
    for (int i=0;i<n;i++) {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    prod = v[n - 1] * v[n - 2];
    cout << prod << endl;
    ;
}