#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:

    void recOrder(vector<vector<int>>& edges, int root, set<int>& walked){
        for(int i =0;i<edges.size();++i){
            if(walked.count(i)){
                continue;
            }
            auto& e = edges[i];


            if((e[0] != root) &&  (e[1]!= root)){
                continue;
            }
            walked.insert(i);
            if(e[1] == root){
                e = {e[1],e[0]};
            }
            recOrder(edges, e[1], walked);
        }
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {

        set<int> walked;
        recOrder(edges, 0, walked);
        
        sort(edges.begin(),edges.end(), [](auto &lhs, auto &rhs){
            return lhs[0] < rhs[0];
        });


        auto res = recWalk(edges, values, 0);

        return res.first;
    }

    //first is sub best result, second is sum of this subTree
    pair<long long,long long> recWalk(const vector<vector<int>>& edges, const vector<int>& values,int root){

        auto eqRange = equal_range(edges.begin(), edges.end(), vector<int>{root,root},[](auto &lhs, auto &rhs){
            return lhs[0] < rhs[0];
        });

        if(eqRange.first == eqRange.second){
            //is leaf
            return {(long long)0, (long long)values[root]};
        }


        //two possible way, 
        //first, keep root, pick all subnodes
        long long keepThisPickAllSub = 0;
        long long subBestAlsoPickThis = values[root];

        for(auto it = eqRange.first; it != eqRange.second;++it){
            int subIdx = (*it)[1];

            auto sub = recWalk(edges, values, subIdx);
            keepThisPickAllSub+= sub.second;
            subBestAlsoPickThis+= sub.first;
        }

        //second, keep sub root best, and also pick this node

        long long bestOfThis = max(keepThisPickAllSub, subBestAlsoPickThis);

        return {bestOfThis, keepThisPickAllSub + values[root]};
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> edges = {{0,1},{0,2},{0,3},{2,4},{4,5}};
        vector<int> values = {5,2,5,2,1,1};
        assert(s.maximumScoreAfterOperations(edges,values) == 11);

    }
    {

        vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
        vector<int> values = {20,10,9,7,4,3,5};
        assert(s.maximumScoreAfterOperations(edges,values) == 40);
    }
    {
        vector<vector<int>> edges = {{7,0},{3,1},{6,2},{4,3},{4,5},{4,6},{4,7}};
        vector<int> values = {2,16,23,17,22,21,8,6};
        assert(s.maximumScoreAfterOperations(edges,values) == 113);
    }

}
