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
    ListNode* insertionSortList(ListNode* head) {

        vector<ListNode*> ordered;

        while(head){
            if(ordered.empty()){
                ordered.push_back(head);
                head = head->next;
                continue;
            }

            auto insIdx = lower_bound(ordered.begin(),ordered.end(),head,[](auto lhs, auto rhs){
                return lhs->val < rhs->val;
            }) - ordered.begin();

            ordered.insert(ordered.begin()+insIdx,head);

            auto next = head->next;
            if(insIdx!= 0){
                ordered[insIdx-1]->next = head;
            }

            if(insIdx!=ordered.size()-1){
                ordered[insIdx]->next = ordered[insIdx+1];
            }

            head = next;

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

        auto res = s.insertionSortList(&n4);

        vector<int> expect = {1,2,3,4};
        for(auto v:expect){
            assert(v == res->val);
            res = res->next;
        }
        assert(!res);
        
        
    }
}
