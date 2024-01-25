#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) :_parent(parent){
        
        vector<pair<int,int>> parentChild;
        for(int i = 0;i<parent.size();++i){
            parentChild.push_back({parent[i],i});
        }

        sort(parentChild.begin(),parentChild.end());


    }
    map<int,int> _belongs;

    map<int,vector<int>> _chains;
    
    int getKthAncestor(int node, int k) {

        int current = node;
        for(int i = 0; i < k; ++i){
            current = _parent[current];
            if(current == -1){
                return -1;
            }
        }
        return current;
        
    }

private :
    const vector<int>& _parent;
};

#include "../parse.h"

int main(){
    {
    
        int k = 7;
        vector<int> parent = {-1, 0, 0, 1, 1, 2, 2} ;

        TreeAncestor t(k,parent);

        assert(t.getKthAncestor(3,1)==1);
        assert(t.getKthAncestor(5,2)==0);
        assert(t.getKthAncestor(6,3)==-1);
    }
    {
        int k = 5000;
        auto parent = pvi("1483_case1.txt",0);

        TreeAncestor t(k,parent);

        int res = t.getKthAncestor(43495,41615);

    }
}
