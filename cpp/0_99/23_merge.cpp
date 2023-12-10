#include <iostream>
#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==1){
            return lists[0];
        }

        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        bool hasValue = true;
        while(hasValue){

            
            int minVal = numeric_limits<int>::max();
            int minIdx = -1;
            int emptyNumber =0 ;
            for(int i = 0;i < lists.size();++i){
                if(!lists[i]){
                    ++emptyNumber;
                    continue;
                }

                if(lists[i]->val < minVal){
                    minIdx = i;
                    minVal = lists[i]->val;
                }
            }

            hasValue = (minIdx != -1);

            if(!hasValue){
                break;
            }



            if(!head){
                if(!hasValue){
                    return nullptr;
                }

                head = lists[minIdx];
                lists[minIdx] = lists[minIdx]->next;
                continue;
            }

            auto newTail = lists[minIdx];
            lists[minIdx] = lists[minIdx]->next;

            if(!tail){
                head->next = newTail;
                tail = newTail;
            }else{
                tail->next = newTail;
                tail = newTail;
            }


            if(emptyNumber == lists.size() - 1){
                break;
            }

        }

        return head;
        
    }

};

int main(){
    Solution s;
    {
        ListNode v5(5);
        ListNode v4(4,&v5);
        ListNode v1(1,&v4);

        ListNode v24(4);
        ListNode v23(3,&v24);
        ListNode v21(1,&v23);

        ListNode v36(6);
        ListNode v32(2,&v36);

        vector<ListNode*> p{&v1,&v21,&v32};
        auto res = s.mergeKLists(p);
        while(res){
            cout<<res->val<<endl;
            res = res->next;
        }
    }
    {
        ListNode v1(1);
        vector<ListNode*> l{&v1};
        s.mergeKLists(l);
    }
}
