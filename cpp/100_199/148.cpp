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
    ListNode* sortList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        vector<ListNode*> ordered;
        while(head){
            ordered.push_back(head);
            head=head->next;
        }

        sort(ordered.begin(),ordered.end(),[](auto lhs, auto rhs){
                return lhs->val < rhs->val;
            });

        auto it = ordered.begin();

        while(it<ordered.end()-1){

            (*it)->next = *(it+1);
            ++it;
        }

        ordered.back()->next = nullptr;

        return ordered.front();
        
    }
};
int main(){
    Solution s;
    {
        ListNode n3(3);
        ListNode n1(1,&n3);
        ListNode n2(2,&n1);
        ListNode n4(4,&n2);

        auto res = s.sortList(&n4);

        vector<int> expect = {1,2,3,4};
        for(auto v:expect){
            assert(v == res->val);
            res = res->next;
        }
        assert(!res);
        
        
    }
    {
        ListNode n0(0);
        ListNode n4(4,&n0);
        ListNode n3(3,&n4);
        ListNode n5(5,&n3);
        ListNode n11(-1,&n5);

            auto res = s.sortList(&n11);

        vector<int> expect = {-1,0,3,4,5};
        for(auto v:expect){
            assert(v == res->val);
            res = res->next;
        }
        assert(!res);

    }
}
