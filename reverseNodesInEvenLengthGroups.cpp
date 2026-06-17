#include <iostream>
using namespace std;


/*

Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurs.
- The length of the last group is 4, which is even, hence the nodes are reversed.

*/

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int> arr;
        ListNode* temp=head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int n=arr.size();
        int start=0;
        int len=1;

        while(start<n){
            int end=min(start+len,n);
            int actualLen=end-start;

            if(actualLen % 2 == 0){
                reverse(arr.begin()+start,arr.begin()+end);
            }

            start=end;
            len++;
        }

        temp=head;

        for(int i=0;i<n;i++){
            temp->val=arr[i];
            temp=temp->next;
        }

        return head;
    }
};

int main() {
    
    return 0;
}