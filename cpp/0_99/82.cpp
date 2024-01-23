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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* retHead = nullptr;

        ListNode* tail = nullptr;
        ListNode* current = head;

        while(current){

            auto lookAhead = current->next;

            int count = 1;
            while(lookAhead){
                if(lookAhead->val== current->val){
                    ++count;
                    lookAhead = lookAhead->next;
                }else{
                    break;
                }
            }

            if(count == 1){
                if(!retHead){
                    retHead = current;
                    tail = current;
                }else{
                    tail->next = current;
                    tail = current;
                }
                
                current = lookAhead;
                continue;
            }

            current = lookAhead;
        }
        if(tail){
            tail->next = nullptr;
        }

        return retHead;
        
    }
};

int main(){
    Solution s;
    {
        ListNode n5(5);
        ListNode n42(4,&n5);
        ListNode n41(4,&n42);
        ListNode n32(3,&n41);
        ListNode n31(3,&n32);
        ListNode n2(2,&n31);
        ListNode n1(1,&n2);

        auto res = s.deleteDuplicates(&n1);
        vector<int> expect = {1,2,5};
        for(int i = 0; i< expect.size();++i){
            assert(expect[i] == res->val);
            res = res->next;
        }
    }
    {
        ListNode n3(3);
        ListNode n2(2,&n3);
        ListNode n13(1,&n2);
        ListNode n12(1,&n13);
        ListNode n1(1,&n12);

        auto res = s.deleteDuplicates(&n1);
        vector<int> expect = {2,3};
        for(int i = 0; i< expect.size();++i){
            assert(expect[i] == res->val);
            res = res->next;
        }
    }
}
