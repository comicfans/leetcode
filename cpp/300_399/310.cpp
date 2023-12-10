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



        vector<int> leafMaxLength(n);

        for(int idx = 0; idx < edgeNumber.size(); ++idx){
            if(edgeNumber[idx]!=1){
                continue;
            }

            int longestChain = 0;


            vector<int> walked = {idx};

            recWalk(fromTo, leafMaxLength, walked);
            break;
        }

        map<int,set<int>> lengthIdx;
        for(int idx = 0;idx < n;++idx){
            lengthIdx[leafMaxLength[idx]].insert(idx);
        }


        vector<int> ret(lengthIdx.begin()->second.begin(),lengthIdx.begin()->second.end());

        return ret;

    }

    void recWalk(const map<int,set<int>>& fromTo, vector<int>& leafMaxLength,vector<int>& walked){

        int lastNode = walked.back();

        leafMaxLength[lastNode] = max<int>(walked.size() - 1, leafMaxLength[lastNode]);

        bool reachOther = false;
        for(auto target: fromTo.at(lastNode)){
            if((walked.size() >= 2) && (target == walked[walked.size()-2])){
                continue;
            }

            reachOther=true;

            walked.push_back(target);

            recWalk(fromTo, leafMaxLength, walked);

            walked.pop_back();
        }

    
        if(reachOther){
            return;
        }

        //reverse  0,1,2,3
        //         3,2,0,1
        //         1,2,3
        //         3,2,1
        
        for(int i = 0; i < walked.size();++i){
            int thisNode = walked[walked.size()-1-i];
            leafMaxLength[thisNode] = max(leafMaxLength[thisNode], i);
        }
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> edges = {};
        auto res = s.findMinHeightTrees(1,edges);

        vector<int> expect = {0};
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
