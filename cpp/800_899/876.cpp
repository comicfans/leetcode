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
    ListNode* middleNode(ListNode* head) {
        
        int count = 0;

        auto current = head;
        while(current){
            ++count;
            current = current->next;
        }

        int middle = count / 2;

        current = head;
        for(int i = 0;i<middle; ++i){
            current = current->next;
        }

        return current;

    }
};
