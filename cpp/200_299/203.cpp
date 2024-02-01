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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return head;
        }

        while(head && head->val == val ){
            head = head->next;
        }
        if(!head){
            return head;
        }

        auto tail = head;
        auto current = tail->next;
        while(current){
            if(current->val == val){
                current = current->next;
                continue;
            }else{
                tail->next = current;
                tail = current;
                current = current->next;
            }

        }
        if(tail){
            tail->next = nullptr;
        }
        return head;
    }
};

int main(){
    Solution s;
    {
        ListNode n1(1);
        ListNode n2(2,&n1);
        ListNode n21(2,&n2);
        ListNode n12(1,&n21);
        vector<int> expect = {1,1};
        auto p = s.removeElements(&n12,2);
        for(auto v : expect){
            assert(v == p->val);
            p=p->next;
        }
        assert(!p);

    }
    {
        ListNode n6(6);
        ListNode n5(5,&n6);
        ListNode n4(4,&n5);
        ListNode n3(3,&n4);
        ListNode n61(6,&n3);
        ListNode n2(2,&n61);
        ListNode n1(1,&n2);

        vector<int> expect = {1,2,3,4,5};
        auto p = s.removeElements(&n1,6);
        for(auto v : expect){
            assert(v == p->val);
            p=p->next;
        }
        assert(!p);
    }
    {
        auto p = s.removeElements(nullptr,1);
        assert(!p);
    }
    {
        ListNode n71(7);
        ListNode n72(7,&n71);
        ListNode n73(7,&n72);
        auto p = s.removeElements(&n73,7);
        assert(!p);
    }
}
