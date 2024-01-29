#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {

        map<Node*,Node*> corresponding;

        return recCopy(head, corresponding);
        
    }

    Node* recCopy(Node* head, map<Node*,Node*>& corresponding){

        if(!head){
            return nullptr;
        }

        auto pos = corresponding.find(head);
        if(pos != corresponding.end()){
            return pos->second;
        }

        auto newCopy = new Node(head->val);
        corresponding.insert({head,newCopy});
        newCopy->next = recCopy(head->next, corresponding);
        newCopy->random = recCopy(head->random,corresponding);
        return newCopy;
    }
};
