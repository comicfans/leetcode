#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {

        vector<int> values;

        while(head){
            values.push_back(head->val);
            head = head->next;
        }

        int ret = -1;
        for(int i = 0;i< values.size()/2;++i){
            int thisRes = values[i] + values[values.size()-1-i];
            ret = max(thisRes, ret);
        }

        return ret;

        
    }
};
