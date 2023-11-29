#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1){
            return {0};
        }


        //find longest edge /2 ,
        //longest edge should appear only once from edges
        

        vector<int> edgeNumber(n);

        map<int,set<int>> fromTo;
        for(const auto e: edges){
            edgeNumber[e[0]]++;
            edgeNumber[e[1]]++;
            fromTo[e[0]].insert(e[1]);
            fromTo[e[1]].insert(e[0]);
        }



        vector<vector<int>> longestWalk;

        for(int idx = 0; idx < edgeNumber.size(); ++idx){
            if(edgeNumber[idx]!=1){
                continue;
            }

            int longestChain = 0;


            vector<int> walked = {idx};

            recWalk(fromTo, longestWalk, walked);
        }

        vector<int> ret;

        for(const auto& p : longestWalk){
            ret.push_back(p[p.size()/2]);
            if(p.size()%2 == 0){
                ret.push_back(p[p.size()/2-1]);
            }
        }

        sort(ret.begin(),ret.end());
        auto end = unique(ret.begin(),ret.end());
        ret.resize(end - ret.begin());

        return ret;

    }

    void recWalk(const map<int,set<int>>& fromTo, vector<vector<int>>& longestWalk,vector<int>& walked){

        bool reachOther = false;
        for(auto target: fromTo.at(walked.back())){
            if((walked.size() >= 2) && (target == walked[walked.size()-2])){
                continue;
            }

            reachOther = true;

            walked.push_back(target);

            recWalk(fromTo, longestWalk, walked);

            walked.pop_back();
        }

        if(reachOther){
            return;
        }

        //calc walked
        if(longestWalk.empty()){
            longestWalk.push_back(walked);
            return;
        }

        if(longestWalk.back().size() > walked.size()){
            return;
        }

        if(longestWalk.back().size() < walked.size()){
            longestWalk.clear();
        }

        longestWalk.push_back(walked);
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> edges = {};
        auto res = s.findMinHeightTrees(1,edges);

        vector<int> expect = {1};
        assert(res == expect);

    }
    {
        vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
        auto res = s.findMinHeightTrees(4,edges);

        vector<int> expect = {1};
        assert(res == expect);

    }
    {
        vector<vector<int>> edges = {{3,0},{3,1},{3,2},{3,4},{5,4}};
        auto res = s.findMinHeightTrees(6,edges);

        vector<int> expect = {3,4};
        assert(res == expect);

    }
}
