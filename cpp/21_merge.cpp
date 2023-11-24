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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1){
            return list2;
        }

        if(!list2){
            return list1;
        }

        auto thisPoint = list1->val <= list2->val?list1:list2;
        auto head = thisPoint;
        auto anotherPoint = list1->val <= list2->val?list2:list1;

        while(thisPoint || anotherPoint){

            auto nextPoint = thisPoint->next;

            if(!nextPoint){
                thisPoint->next = anotherPoint;
                break;
            }

            if(!anotherPoint){
                break;
            }


            auto lessPoint = nextPoint->val <= anotherPoint->val? nextPoint: anotherPoint;
            auto nextAnother = nextPoint->val <= anotherPoint->val? anotherPoint: nextPoint;

            thisPoint->next = lessPoint;
            thisPoint = lessPoint;
            anotherPoint = nextAnother;
        }

        return head;
        
    }
};
