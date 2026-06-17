#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> arr=nums;
        for(int x:nums){
            arr.push_back(x);
        }

        int m=arr.size();

        stack<int> st;
        vector<int> nextGreater(m);
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nextGreater[i]=-1;
            }
            else{
                nextGreater[i]=st.top();
            }
            st.push(arr[i]);
        }

        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nextGreater[i];
        }

        return ans;
    }
};

int main() {
    
    return 0;
}