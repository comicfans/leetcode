#include <utility>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        

        ListNode* leftHead= nullptr;
        ListNode* leftTail = nullptr;



        ListNode* current= head;

        for(int i =1; i<left;++i){
            if(!leftHead){
                leftHead = current;
            }
            leftTail = current;
            current = current->next;
        }

        ListNode *revertTail = current;
        ListNode* revertHead = current;
        ListNode* rightPart = current->next;
        for(int revert = 0; revert < right - left; ++revert){
            revertHead = rightPart;
            rightPart = revertHead->next;
            revertHead->next = current;
            current = revertHead;
        }

        revertTail->next = rightPart;

        if(leftHead){
            leftTail->next = revertHead;
            return leftHead;
        }

        return revertHead;

    }
};

int main(){
    Solution s;
       {

        ListNode n5(5);
        ListNode n4(4,&n5);
        ListNode n3(3,&n4);
        ListNode n2(2,&n3);
        ListNode n1(1,&n2);

        auto res = s.reverseBetween(&n1,3,4);
        vector<int> expect = {1,2,4,3,5};
        for(int i = 0;i<expect.size();++i){
            assert(expect[i]==res->val);
            res = res->next;
        }
        assert(res== nullptr);


    }
    {
        ListNode n5(5);
        ListNode n4(4,&n5);
        ListNode n3(3,&n4);
        ListNode n2(2,&n3);
        ListNode n1(1,&n2);

        auto res = s.reverseBetween(&n1,2,4);
        vector<int> expect = {1,4,3,2,5};
        for(int i = 0;i<expect.size();++i){
            assert(expect[i]==res->val);
            res = res->next;
        }
        assert(res== nullptr);
    }
    {
        ListNode n5(5);
        auto res = s.reverseBetween(&n5,1,1);
        vector<int> expect = {5};
        for(int i = 0;i<expect.size();++i){
            assert(expect[i]==res->val);
            res = res->next;
        }
        assert(res== nullptr);

    }
    
}

