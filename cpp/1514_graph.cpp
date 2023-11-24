#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        set<int> walked={start_node};

        map<int, map<int,int>> from_to;

        for(int idx = 0;idx < edges.size(); ++idx){
            auto& edge=edges[idx];
            from_to[edge[0]][edge[1]] = idx;
            from_to[edge[1]][edge[0]] = idx;
        }


        double best = 0;
        double initP = 1;
        recWalk(from_to, succProb, start_node, end_node, walked, initP, best);

        return best;
    }

    void recWalk(const map<int,map<int,int>>& from_to, vector<double>& succProb, int current, int target, set<int>& walked,double currentP, double &bestP){

        if(currentP < bestP){
            return ;
        }

        if(current == target){
            bestP = max(bestP,currentP);
            return ;
        }


        auto connectPos = from_to.find(current);
        if(connectPos == from_to.end()){
            return;
        }


        for(auto nodeEdge:connectPos->second){

            if(walked.count(nodeEdge.first)){
                continue;
            }

            auto insertPos = walked.insert(nodeEdge.first);

            double thisP = succProb[nodeEdge.second] * currentP;

            recWalk(from_to, succProb, nodeEdge.first, target, walked, thisP, bestP);

            walked.erase(insertPos.first);
        }
    }


};

int main(){
    Solution s;
    {
        vector<vector<int>> edges = {{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
        vector<double> succProb = {0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77};
        int start_node =0;
        int end_node = 3;
        s.maxProbability(5,edges, succProb,start_node, end_node);
    }
}
