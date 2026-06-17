#include <iostream>
using namespace std;

vector<int> result;

void dfs(int curr,int n){
    if(curr > n){
        return;
    }
    result.push_back(curr);
    for(int i=0;i<=9;i++){
        int next=curr*10+i;
        if(next > n) return;
        dfs(next,n);
    }
}

void lexicographical(int n){
    for(int i=1;i<=9;i++){
        if(i>n){
            break;
        }
        dfs(i,n);
    }
}

vector<int> sortLexicographical(vector<int>& arr){
    sort(arr.begin(),arr.end(),[](int a,int b){
        return to_string(a)<to_string(b);
    });
    return arr;
}

int main() {
    
    // lexicographical(33);

    // for(int x:result){
    //     cout<<x<<" ";
    // }

    vector<int> arr={10, 2, 1, 21, 12, 100};

    vector<int> ans=sortLexicographical(arr);

    for(int x:ans){
        cout<<x<<" ";
    }
    
    return 0;
}