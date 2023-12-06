
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
    ListNode* rotateRight(ListNode* head, int k) {

        int length = 0;

        ListNode * walk = head;
                
        ListNode * tail = head;

        while(walk){
            tail = walk;
            ++length;
            walk = walk->next;
        }

        auto mod = k % length;

        if(mod == 0){
            return head;
        }

        int count = length - mod;

        walk = head;
        ListNode *prev = nullptr;
        while(count > 0){
            prev = walk;
            --count;
            walk = walk->next;
        }

        prev->next = nullptr;
        tail->next = head;
        return walk;
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

        auto res = s.rotateRight(&n1,2);
    }
}


int main(){
    Solution s;
    {
        ListNode n5(5);
        ListNode n4(4,&n5);
        ListNode n3(3,&n4);
        ListNode n2(2,&n3);
        ListNode n1(1,&n2);

        auto res = s.rotateRight(&n1,2);
    }
}

