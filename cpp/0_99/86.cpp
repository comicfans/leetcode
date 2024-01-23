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
    ListNode* partition(ListNode* head, int x) {
        ListNode * smallHead=nullptr;
        ListNode * smallTail=nullptr;
        ListNode * bigHead=nullptr;
        ListNode * bigTail=nullptr;

        ListNode* current = head;

        while(current){
            if(current->val < x){
                if(!smallHead){
                    smallHead=current;
                    smallTail = current;
                }else{
                    smallTail->next = current;
                    smallTail = current;
                }

            }else{
                if(!bigHead){
                    bigHead = current;
                    bigTail = current;
                }else{
                    bigTail->next = current;
                    bigTail = current;
                }
            }
            current = current->next;
        }

        if(bigTail){
            bigTail->next = nullptr;
        }

        if(smallTail){
            smallTail->next = bigHead;
            return smallHead;
        }

       

        return bigHead;


    }
};

int main(){
    Solution s;
    {
        ListNode n2(2);
        ListNode n5(5,&n2);
        ListNode n21(2,&n5);
        ListNode n3(3,&n21);
        ListNode n4(4,&n3);
        ListNode n1(1,&n4);

        auto res = s.partition(&n1,3);
        vector<int> expect = {1,2,2,4,3,5};
        for(int i = 0;i<expect.size();++i){
            assert(expect[i] == res->val);
            res = res->next;
        }
        assert(res == nullptr);
    }
    {
        ListNode n1(1);
        ListNode n2(2,&n1);

        auto res = s.partition(&n2,2);
        vector<int> expect = {1,2};
        for(int i = 0;i<expect.size();++i){
            assert(expect[i] == res->val);
            res = res->next;
        }
        assert(res == nullptr);
    }
    
}
