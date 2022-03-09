#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int lb, int mid, int ub) {
    int arr1 = mid - lb + 1;
    int arr2 = ub - mid;
    
    int subArr1[arr1];
    int subArr2[arr2];
    int i, j, k;
    for(i=0;i<arr1;i++){
        subArr1[i] = a[lb+i];
    }


    for(i=0; i<=arr2; i++){
        subArr2[i] = a[mid+1+i];
    }

    i = j = 0;
    k = lb;

    while(i<arr1 && j<arr2) {
        if(subArr1[i]<=subArr2[j]) {
            a[k] = subArr1[i];
            i++;
        } else {
            a[k] = subArr2[j];
            j++;
        }
        k++;
    }

    while(i<arr1) {
        a[k] = subArr1[i];
        i++;
        k++;
    }

    while (j<arr2) {
        a[k] = subArr2[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int lb, int ub){
    if(lb<ub) {
        int mid = (ub+lb)/2;
        mergeSort(a, lb, mid);
        mergeSort(a, mid+1, ub);
        merge(a, lb, mid, ub);
    }
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }

    mergeSort(a, 0, n-1);
    for(int i = 0; i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}