#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1){
            return -1;
        }

        // now we have n island, needs (n-1) moves

        map<int, set<int>> fromTo;
        for(const auto& c: connections){
            fromTo[c[0]].insert(c[1]);
            fromTo[c[1]].insert(c[0]);
        }
        
        set<set<int>> islands;

        while(!fromTo.empty()){

            set<int> newSet;

            set<int> newNodes = {fromTo.begin()->first};

            while(!newNodes.empty()){

                set<int> next;
                for(auto v: newNodes){

                    auto tos = fromTo.find(v);
                    if(tos == fromTo.end()){
                        continue;
                    }

                    copy_if(tos->second.begin(),tos->second.end(),inserter(next,next.end()),[&](auto& v){

                        if(newNodes.count(v)){
                            return false;
                        }

                        if(newSet.count(v)){
                            return false;
                        }

                        return true;
                    });

                    fromTo.erase(tos);
                }

                copy(newNodes.begin(),newNodes.end(),inserter(newSet,newSet.end()));
                swap(newNodes, next);
            }

            islands.insert(newSet);
        }

        // which nodes is not included ? 
        //
        int leftNodes = n;
        for(const auto& i : islands){
            leftNodes -= i.size();
        }

        return islands.size() + leftNodes -1;

        
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> con = {{0,1},{0,2},{1,2}};
        assert(s.makeConnected(4,con)==1);
    }

}
