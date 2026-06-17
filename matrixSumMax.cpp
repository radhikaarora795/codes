/*
Find the maximum sum in a 2D matrix choosing one element per row such that 
value from row i > row i-1, in O(nm) time and O(1) space.
*/

#include <iostream>
#include <vector>
using namespace std;
/*
int findJustLessThanMax(vector<int>& arr, int n,int maxVal){
    int localMax=INT_MIN;
    for(int i=0;i<n;i++){
        if(max(localMax,arr[i]) < maxVal){
            localMax=max(localMax,arr[i]);   
        }
    }
    return localMax;
}
*/

int findJustLessThanMax(vector<int>& arr, int n, int maxVal){
    int localMax = INT_MIN;

    for(int i = 0; i < n; i++){
        if(arr[i] < maxVal){
            localMax = max(localMax, arr[i]);
        }
    }

    return localMax;
}


int lastRowMax(vector<int>& arr,int n){
    int greatest=arr[0];
    for(int i=0;i<n;i++){
        greatest=max(greatest,arr[i]);
    }
    return greatest;
}

int maxSum(vector<vector<int>>& matrix){
    if(matrix.size()==0){
        return 0;
    }
    
    int n=matrix.size();
    int m=matrix[0].size();

    int maxValue=lastRowMax(matrix[n-1],m);
    int sum=maxValue;

    for(int i=n-2;i>=0;i--){
        int localMax=findJustLessThanMax(matrix[i],m,maxValue);
        if(localMax != INT_MIN){
            sum+=localMax;
            maxValue=localMax;
        }
        else{
            return -1;
        }
    }
    return sum;
}

int main() {
    vector<int> a = {1,3,4,7,5};
    cout<<findJustLessThanMax(a,a.size(),11);
    return 0;
}