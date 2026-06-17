#include <iostream>
using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string result="";
        stack<int> st;
        for(int i=0;i<=pattern.size();i++){
            st.push(i+1);
            if(i == pattern.size() || pattern[i]=='I'){
                while(!st.empty()){
                    result+=to_string(st.top());
                    st.pop();
                }
            }
        }
        int n=result.size();
        if(n == 0) return "not";
        
        return result;
    }
};

int main() {
    
    return 0;
}

/*

class Solution {
public:
    string largestNumber(string pattern) {
        string result = "";
        stack<int> st;
        int n = pattern.size();

        for (int i = 0; i <= n; i++) {
            st.push(n + 1 - i);   // push in decreasing order

            if (i == n || pattern[i] == 'D') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }

        return result;
    }
};

*/