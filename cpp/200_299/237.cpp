#ifdef LEETCODE
#include "../parse.h"
#endif

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
    void deleteNode(ListNode* node) {

        ListNode* cur = node;
        ListNode* next = cur->next;

        while(next){
            cur->val = next->val;

            if(!next->next){
                cur->next = nullptr;
                break;
            }

            cur = next;
            next = next->next;
        }

        cur->next = nullptr;

        
    }
};
