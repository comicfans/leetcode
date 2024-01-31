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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> counter;
        while(headA){
            counter[headA] ++;
            headA = headA->next;
        }
        while(headB){
            auto pos = counter.find(headB);
            if(pos!=counter.end()){
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
        
    }
};
