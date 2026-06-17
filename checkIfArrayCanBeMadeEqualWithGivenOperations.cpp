/*
Given an array arr[] consisting of N integers and following are the three 
operations that can be performed using any external number X.

Add X to an array element once.
Subtract X from an array element once.
Perform no operation on the array element.
*/

#include <iostream>
#include <vector>
using namespace std;

bool madeEqual(vector<int>& arr, int x){
    vector<int> candidates={arr[0]-x,arr[0],arr[0]+x};

    for(int target:candidates){
        bool possible=true;
        for(int num:arr){
            if(num-x != target && num != target && num+x != target){
                possible=false;
                break;
            }
        }
        if(possible){
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> a ={1,3,5};
    cout<<madeEqual(a,2);
    return 0;
} 