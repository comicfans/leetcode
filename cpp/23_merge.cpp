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

        ListNode * head = nullptr;
        ListNode * tail = nullptr;

        while(!lists.empty()){

            vector<ListNode*> nonull;
            copy_if(lists.begin(),lists.end(), back_inserter(nonull),[](auto p){return bool(p);});
            
            if(nonull.empty()){
                break;
            }
            
            int minVal = numeric_limits<int>::max();
            int minIdx = 0;
            for(int i = 0;i < nonull.size();++i){
                if(nonull[i]->val < minVal){
                    minIdx = i;
                    minVal = nonull[i]->val;
                }
            }

            if(!head){
                head = nonull[minIdx];
                nonull[minIdx] = nonull[minIdx]->next;
                lists = nonull;
                continue;
            }

            auto newTail = nonull[minIdx];
            nonull[minIdx] = nonull[minIdx]->next;

            if(!tail){
                head->next = newTail;
                tail = newTail;
            }else{
                tail->next = newTail;
                tail = newTail;
            }


            if(nonull.size()==1){
                break;
            }

            lists = nonull;
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
}
