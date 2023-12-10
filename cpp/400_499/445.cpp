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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int l1Length = 0;

        auto walk1 = l1;
        while(walk1){
            ++l1Length;
            walk1 = walk1->next;
        }

        int l2Length = 0;

        auto walk2 = l2;
        while(walk2){
            ++l2Length;
            walk2 = walk2->next;
        }

        ListNode* lShort = l1Length < l2Length? l1:l2;
        ListNode* lLong  = l1Length < l2Length? l2:l1;

        bool topBit = recAdd(lShort, lLong, max(l2Length,l1Length) - min(l2Length,l1Length));

        if(topBit){
            ListNode* more = new ListNode(1,lLong);
            return more;
        }

        return lLong;

    }

    bool recAdd(ListNode* lShort, ListNode* lLong, int topMore){

        if(topMore>0){
            bool sub = recAdd(lShort, lLong->next, topMore - 1);
            int thisV = lLong->val + sub;
            lLong->val = thisV % 10;
            return thisV >= 10;
        }

        //aligned

        if(!lLong){
            assert(!lShort);
            return 0;
        }

        assert(lLong);
        assert(lShort);
        
        int thisValue = lLong->val + lShort->val;
        bool sub = recAdd(lShort->next, lLong->next, 0);
        thisValue += sub;

        lLong->val = thisValue % 10;

        return thisValue >= 10;
    }
};

int main(){
    Solution s;
    {
        //7243
        auto n3 = ListNode(3);
        auto n4 = ListNode(4, &n3);
        auto n2 = ListNode(2, &n4);
        auto n7 = ListNode(7, &n2);


        //564
        auto n24 = ListNode(4);
        auto n26 = ListNode(6,&n24);
        auto n25 = ListNode(5,&n26);

        auto res = s.addTwoNumbers(&n25, &n7);
    }
}
