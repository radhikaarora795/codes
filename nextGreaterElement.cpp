#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> s;
        // find next greater elements of all elements of nums2
        // get next greter of nums1 from ans of nums2
        // unordered map key: nums2[i] value: next greater elemnent
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            if(s.empty()){
                map[nums2[i]]=-1;
            }
            else{
                map[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}