#include <iostream>
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if(k == 1){
            return head;
        }

        ListNode* firstHead = nullptr;
        ListNode* prevTail = nullptr;
        ListNode* currentHead = head;

        ListNode* walk = head;
        int walked = 0;
        while(walk){
            ++walked;

            if(walked == 1){
                currentHead = walk;
                walk = walk->next;
                continue;
            }

            if(walked != k){
                walk=walk->next;
                continue;
            }

            //walked == k, need revert

            walked = 0;
            if(!firstHead){
                firstHead = walk;
            }

            auto nextNode = walk->next;
            //from currentHead, up to walk, do revert
            auto toRevert = currentHead;
            auto nextToRevert = toRevert->next;
            while(true){
                auto next = nextToRevert->next;

                nextToRevert->next = toRevert;
                toRevert = nextToRevert;
                if(toRevert == walk){
                    break;
                }
                nextToRevert = next;
                next = nextToRevert;
            }

            if(!prevTail){
                prevTail = currentHead;
            }else{
                prevTail->next = walk;
                prevTail = currentHead;
            }

            currentHead->next = nextNode;
            walk = nextNode;
        }


        return firstHead;
        
    }
};

int main(){
    Solution s;
    {
        ListNode v6(6);
        ListNode v5(5,&v6);
        ListNode v4(4,&v5);
        ListNode v3(3,&v4);
        ListNode v2(2,&v3);
        ListNode v1(1,&v2);

        //auto res = s.swapPairs(&v1);
        auto res = s.reverseKGroup(&v1, 2);
        while(res){
            cout<<res->val<<endl;
            res = res->next;
        }

        return 0;
    }
    {
        ListNode v5(5);
        ListNode v4(4,&v5);
        ListNode v3(3,&v4);
        ListNode v2(2,&v3);
        ListNode v1(1,&v2);

        //auto res = s.swapPairs(&v1);
        auto res = s.reverseKGroup(&v1, 2);
        while(res){
            cout<<res->val<<endl;
            res = res->next;
        }

    }
    {
        ListNode v5(5);
        ListNode v4(4,&v5);
        ListNode v3(3,&v4);
        ListNode v2(2,&v3);
        ListNode v1(1,&v2);

        //auto res = s.swapPairs(&v1);
        auto res = s.reverseKGroup(&v1, 3);
        while(res){
            cout<<res->val<<endl;
            res = res->next;
        }

    }
}
