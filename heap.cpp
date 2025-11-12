#include<iostream>
using namespace std;

void Insert(int arr[],int n){
    for(int i=2;i<=n;i++){
        int temp = arr[i];
        int t=i;
        while(t>1 && temp>arr[t/2]){
            arr[t] = arr[t/2];
            t = t/2;
        }
        arr[t] = temp;
    }
}


int main(){
    int arr[] = {0, 10, 20, 15, 25, 30, 40};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insert(arr, n-1);
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
}