#include <iostream>
using namespace std;

// leetcode 209

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int sum=0;
        int ans=INT_MAX;

        for(int j=0;j<n;j++){
            sum+=nums[j];

            while(sum >= target){
                ans=min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
        }

        if(ans == INT_MAX){
            return 0;
        }

        return ans;
    }
};

/*

Optimal Solution: Sliding Window (Two Pointers)

Since all numbers are positive, once the current window sum is at least 
target, moving the left pointer right will only decrease the sum. 
This property makes the sliding window approach work in O(n) time.

Algorithm
Expand the window by moving right.
Add nums[right] to sum.
While sum >= target:
Update the minimum length.
Shrink the window from the left.
Return the minimum length, or 0 if none exists.

*/

int main() {
    
    return 0;
}