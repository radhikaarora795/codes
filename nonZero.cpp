#include <iostream>
using namespace std;

void moveZeroes(vector<int>& nums){
    int nextNonZero=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i] != 0){
            swap(nums[i],nums[nextNonZero]);
            nextNonZero++;
        }
    }
}

int main() {
    vector<int> nums={0};
    moveZeroes(nums);
    for(int x:nums){
        cout<<x<<" ";
    }
    
    return 0;
}