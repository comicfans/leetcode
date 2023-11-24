#include <vector>
#include <iterator>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        set<int> smallOnes;

        set<int> bigOnes;

        for(auto &edge:edges){
            int big = edge[0];
            int small = edge[1];
            smallOnes.insert(edge[1]);
            if(smallOnes.count(big)){
                smallOnes.insert(big);
            }

            auto bigPos = bigOnes.find(small);
            if(bigPos != bigOnes.end()){
                smallOnes.insert(small);
                bigOnes.erase(bigPos);
            }
        }

        for(int i=0;i<n;++i){

            if(!smallOnes.count(i) && !bigOnes.count(i)){
                bigOnes.insert(i);
            }
        }

        return bigOnes.size() == 1? *bigOnes.begin():-1;


    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> edges={};
        assert(s.findChampion(1, edges) == 0);
    }
    {
        vector<vector<int>> edges = {{3,1},{3,4},{5,4},{2,0},{2,3},{0,3},{1,5}};
        assert(s.findChampion(6, edges) == 2);

    }
}
