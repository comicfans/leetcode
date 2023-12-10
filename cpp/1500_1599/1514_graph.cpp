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

        map<int, multimap<double,int>> from_to;

        bool hasStart = false;
        bool hasEnd = false;

        for(int idx = 0;idx < edges.size(); ++idx){
            auto& edge=edges[idx];
            auto p = succProb[idx];

            if((edge[0]==start_node)||(edge[1] == start_node)){
                hasStart = true;
            }

            if((edge[0] == end_node) ||(edge[1] == end_node)){
                hasEnd = true;
            }

            from_to[edge[0]].insert({p, edge[1]});
            from_to[edge[1]].insert({p, edge[0]});
        }

        if(!hasStart && !hasEnd){
            return 0;
        }

        // do a quick connect test?
        set<int> connectSet = {start_node};
        bool found = false;
        while(true){
            set<int> outer = {};
            for(auto from: connectSet){
                auto toPos = from_to.find(from);
                if(toPos == from_to.end()){
                    continue;
                }
                for(auto pTarget:toPos->second){
                    if(connectSet.count(pTarget.second)){
                        continue;
                    }
                    if(pTarget.second == end_node){
                        found = true;
                        break;
                    }
                    outer.insert(pTarget.second);
                }
            }
            if(found || outer.empty()){
                break;
            }
            copy(outer.begin(),outer.end(),inserter(connectSet,connectSet.begin()));
        }
        if(!found){
            return 0;
        }



        vector<double> bestP;
        bestP.resize(n);
        bestP[start_node] = 1;
        bestP[end_node] = 0;

        recUpdate(from_to, bestP, start_node, end_node);

        return bestP[end_node];
    }

    void recUpdate(const map<int, multimap<double,int>>& from_to, vector<double>& bestP, int changedNode, int end_node){


        auto connectPos = from_to.find(changedNode);
        if(connectPos == from_to.end()){
            return;
        }

        double currentP = bestP[changedNode];


        set<int> bfs;
        for(auto pTarget:connectPos->second){

            double targetP = currentP * pTarget.first;
            if(targetP > bestP[pTarget.second]){
                bestP[pTarget.second] = targetP;
                if(pTarget.second != end_node){
                    bfs.insert(pTarget.second);
                }
            }
        }

        for(auto t:bfs){
            recUpdate(from_to, bestP, t, end_node);
        }
    }
    


};

#include "parse.h"

int main(){
    Solution s;
    {
        vector<vector<int>> edges = {{2,3},{1,2},{3,4},{1,3},{1,4},{0,1},{2,4},{0,4},{0,2}};
        vector<double> succProb = {0.06,0.26,0.49,0.25,0.2,0.64,0.23,0.21,0.77};
        int start_node =0;
        int end_node = 3;
        s.maxProbability(5,edges, succProb,start_node, end_node);
    }
    {
        auto edges = pvvi("1514_case1.txt",0);
        auto succProb= pvd("1514_case1.txt",1);
        int start_node = 7168;
        int end_node = 6293;
        s.maxProbability(10000,edges, succProb, start_node, end_node);

    }
}
