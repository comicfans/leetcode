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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(!head){
            return false;
        }

        ListNode *jump1=head;
        ListNode *jump2=head;

        while(true){

            jump1 = jump1->next;
            if(!jump1){
                return false;
            }

            jump2 = jump2->next;
            if(!jump2){
                return false;
            }
            jump2 = jump2->next;
            if(!jump2){
                return false;
            }
            if(jump1==jump2){
                return true;
            }
        }

        return false;
        
    }
};
