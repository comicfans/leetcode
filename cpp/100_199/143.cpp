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
    void reorderList(ListNode* head) {

        vector<ListNode*> orig;

        while(head){
            orig.push_back(head);
            head = head->next;
        }

        for(int i = 0;i < orig.size()/2;++i){
            int tailPos = orig.size()- 1-i;

            orig[i]->next = orig[tailPos];

            orig[tailPos]->next = orig[i+1];
        }


        orig[orig.size()/2]->next = nullptr;


        
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

        s.reorderList(&n1);

    }
}
