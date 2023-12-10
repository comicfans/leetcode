#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if(!head){
            return head;
        }


        if(!head->next){
            return head;
        }

        ListNode* ret = head->next;
        ListNode* current = ret->next;
        ret->next = head;

        ListNode* tail = head;
        tail->next = nullptr;

        while(current){

            auto swapHead = current ->next;

            if(!swapHead){
                tail->next = current;
                return ret;
            }

            auto next = swapHead->next;

            tail->next = swapHead;

            swapHead->next = current;

            tail = current;
            tail->next = nullptr;
            current = next;

        }

        return ret;
        
        
    }


};

int main(){
    Solution s;
    {
        ListNode v4(4);
        ListNode v3(3,&v4);
        ListNode v2(2,&v3);
        ListNode v1(1,&v2);

        //auto res = s.swapPairs(&v1);
        auto res = s.reverseKGroup(&v1, 2);
        while(res){
            cout<<res->val<<endl;
            res = res->next;
        }
    }
    {
        auto res = s.swapPairs(nullptr);
    }
    {

        ListNode v1(1);
        auto res = s.swapPairs(&v1);
    }
}
