#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
         cin>>arr[i];
    }
    int xr =0;
    for(auto n : arr){
        xr = xr ^ n;
    }
    cout<<xr;
    return 0;
}