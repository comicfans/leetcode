#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        vector<ListNode*> vec;

        auto thisHead = head;
        while(thisHead){
            vec.push_back(thisHead);
            thisHead= thisHead->next;
        }

        if(n == vec.size()){
            return head->next;
        }

        auto prev = vec[vec.size() - n - 1];
        ListNode *next = vec[vec.size()-n]->next;
        prev->next = next;


        return head;
    }
};
