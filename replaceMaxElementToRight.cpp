#include <iostream>
#include <vector>
using namespace std;

// [6,7,11,4,10,8] → [11,11,11,10,10,8]

void replace(vector<int> &arr){
    int n=arr.size();
    int maxRight=arr[n-1];
    arr[n-1] = maxRight;
    for(int i=n-2;i>=0;i--){
        maxRight=max(maxRight,arr[i]);
        arr[i]=maxRight;
    }
    for(int x:arr){
        cout<<x<<" ";
    }
}

int main() {
    vector<int> arr={6,7,11,4,10,8};
    replace(arr);
    
    return 0;
}