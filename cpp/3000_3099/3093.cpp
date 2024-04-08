#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    string str  = "";
    int idx = -1;
    map<string, vector<Node*>> children;

    ~Node(){
        for(auto kv: children){
            for(auto n:kv.second){
                if(n){
                    delete n;
                }
            }
            
        }
    }

    void add(const string& str, int charPos, int idx){

        if(charPos == -1){
            this->idx = idx;
            return;
        }

        int common = 0;
        for(;charPos - common >=0 && common < str.size(); ++common){

            if(str[charPos - common] == str[common]){
                break;
            }
        }

        Node * op = this;
        if(common < str.length()){
            //need to split

            string commonStr = str.substr(0,common);

            string newChildren = str.substr(common);

            auto p = new Node{
                .str = newChildren,
                .idx = this->idx,
                .children = this->children
            };

            this->str = commonStr;
            this->children.clear();
            this->children[newChildren].push_back(p);
            op = p;
        }

        op->add(str,charPos - common, idx);
    }

    int lookup(const string& query, int charPos){

        int common = 0;
        for(;charPos - common >= 0 && common < str.size(); ++common){
            if(str[common] != query[charPos - common]){
                break;
            }
        }

        int nowCharPos = charPos - common;

        if(nowCharPos == -1){
            //already matched
            //find min short children
        }

    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        Node root;

        for(int i = 0;i< wordsContainer.size(); ++i){
            const auto& s = wordsContainer[i];
            root.add(s,(int)s.size()-1,i);
        }

        vector<int> ret(wordsQuery.size());

        for(int i = 0;i<wordsQuery.size(); ++i){
            const auto& query = wordsQuery[i];
            ret[i] = root.lookup(query, (int)query.size() - 1);
        }
        
        return ret;
    }
};
