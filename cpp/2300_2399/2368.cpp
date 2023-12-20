#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {

        std::map<int, set<int>> fromTos;

        sort(restricted.begin(),restricted.end());

        for(const auto& fromTo: edges){

            int from = fromTo[0];
            int to = fromTo[1];

            if(binary_search(restricted.begin(),restricted.end(), from) || binary_search(restricted.begin(),restricted.end(),to)){
                continue;
            }

            fromTos[from].insert(to);
            fromTos[to].insert(from);
        }

        vector<int> chain = {0};

        return recWalk(fromTos, 0,  -1) + 1;
    }

    int recWalk(const map<int,set<int>>& fromTos, int root, int prev){

        auto pos =  fromTos.find(root);
        if(pos == fromTos.end()){
            return 0;
        }

        int sub = 0;
        for(auto v: pos->second){

            if(v == prev){
                continue;
            }
            

            ++sub;


            int thisSub = recWalk(fromTos, v, root);


            sub += thisSub;
        }

        return sub ;
    }
};

int main(){
    Solution s;
    {
        int n = 7;
        vector<vector<int>> edges = {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}};
        vector<int> restricted = {4,2,1};
        assert(s.reachableNodes(n,edges,restricted) == 3);
    }
    {
        int n = 7 ;
        vector<vector<int>> edges = {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}};
        vector<int> restricted = {4,5};

        assert(s.reachableNodes(n,edges,restricted) == 4);
    }
}
