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
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {

        map<Node*,Node*> walked;

        return recClone(node, walked);
    }

    Node* recClone(Node* node, map<Node*,Node*>& walked){
        if(!node){
            return nullptr;
        }

        auto pos =walked.find(node);
        if(pos != walked.end()){
            return pos->second;
        }

        Node* clone = new Node(node->val);

        walked[node] = clone;

        for(auto child: node->neighbors){

            auto clonePos = walked.find(child);
            if(clonePos != walked.end()){
                clone->neighbors.push_back(clonePos->second);
                continue;
            }

            auto childClone = recClone(child, walked);
            clone->neighbors.push_back(childClone);
        }

        return clone;

    }
};
