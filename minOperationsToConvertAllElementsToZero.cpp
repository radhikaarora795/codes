#include <iostream>
using namespace std;

// leetcode 3542

class Solution {
public:
    /*
    Algorithm

    For every number x:

    While stack top > x
    pop
    answer++
    If x is 0
    continue
    If stack is empty OR top != x
    push x

    Finally

    answer += stack.size()
    */

    int minOperations(vector<int>& nums) {
        stack<int> st;
        int ans=0;
        for(int x:nums){
            while(!st.empty() && st.top() > x){
                st.pop();
                ans++;
            }
            if(x == 0){
                continue;
            }
            if(st.empty() || st.top() != x){
                st.push(x);
            }
        }
        return ans+st.size();
    }
};

int main() {
    
    return 0;
}