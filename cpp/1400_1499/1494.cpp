#include <csignal>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {

        //search from leaf back to root
        
        sort(relations.begin(),relations.end());
        map<int,set<int>> leafToRoot;

        vector<bool> isRoot(n);
        for(const auto& rel:relations){
            leafToRoot[rel[1]].insert(rel[0]);
            isRoot[rel[0]-1] = true;
        }

        vector<int>  firstReady;

        //node,roots
        vector<pair<int,int>>  unready;

        vector<int> levels(n);

        for(int i =0;i<n;++i){
            if(isRoot[i]){
                continue;
            }
            mark(leafToRoot,firstReady,levels,0,i+1);
            sort(firstReady.begin(),firstReady.end());
        }

        vector<pair<int,int>> ready;
        ready.reserve(firstReady.size());
        for(auto r : firstReady){
            ready.push_back({levels[r-1], r});
        }

        sort(ready.begin(),ready.end());

        int step = 0;

        while(!ready.empty() || !unready.empty()){
            //pick n job from ready queue
            // while sort, deeper level appear later
            int pickedJob = min<int>(k, ready.size());

            vector<pair<int,int>> picked (ready.begin() + ready.size() - pickedJob, ready.end());
            ready.resize(ready.size() - pickedJob);

            ++step;

            // will these picked job create new ready node ?
            for(auto &n : picked){
                int node = n.second;
                auto eq= equal_range(relations.begin(),relations.end(),vector<int>{node,node},[](auto& lhs, auto & rhs){
                    return lhs[0] < rhs[0];
                });

                for(auto morePos = eq.first;morePos!= eq.second;++morePos){

                int thisMore = (*morePos)[1];

                auto unreadyEq = equal_range(unready.begin(),unready.end(),
                                              pair<int,int>{thisMore,thisMore},[](auto &lhs, auto& rhs){
                    return lhs.first < rhs.first;
                });

                if (unreadyEq.first == unreadyEq.second){
                    int leftReq = leafToRoot[thisMore].size() - 1;
                    if(leftReq > 0){

                        auto insPos = lower_bound(unready.begin(),unready.end(),
                                                  pair<int,int>{thisMore,thisMore},[](auto& lhs, auto& rhs){
                            return lhs.first < rhs.first;
                        });
                        unready.insert(insPos,{thisMore, leafToRoot[thisMore].size() - 1});
                    }else{
                        pair<int,int> levelNode = {levels[thisMore-1],thisMore};
                        auto pos = lower_bound(ready.begin(),ready.end(),levelNode);
                        ready.insert(pos, levelNode);
                    }
                }else{
                    //already in, reduce one require
                    unreadyEq.first->second--;
                    if(unreadyEq.first->second == 0){
                        pair<int,int> levelNode = {levels[thisMore - 1],thisMore};
                        auto pos = lower_bound(ready.begin(),ready.end(), levelNode);
                        ready.insert(pos, levelNode);
                        unready.erase(unreadyEq.first);
                    }
                }

                }
            }
        }

        return step;
    }

    void mark(const map<int,set<int>>& leafToRoot,
              vector<int>& ready,vector<int>& levels, int currentLevel,int root){

        auto childrenPos = leafToRoot.find(root);

        levels[root - 1] += currentLevel;
        if(childrenPos == leafToRoot.end()){

            auto eq = equal_range(ready.begin(),ready.end(),root);

            if(eq.first == eq.second){
                ready.push_back(root);
            }


            return;
        }

        for(auto target: childrenPos->second){
            mark(leafToRoot,ready,levels,currentLevel +1,target);
        }
    }

};

int main(){
    Solution s;
    {
        int n = 12;
        vector<vector<int>> relations = {{11,10},{6,3},{2,5},{9,2},{4,12},{8,7},{9,5},{6,2},{7,2},{7,4},{9,3},{11,1},{4,3}};
        int k = 3;
        assert(s.minNumberOfSemesters(n,relations,k) == 4);
    }
    {
        int n = 11;
        vector<vector<int>> relations = {{1,2},{2,3},{3,4},
                                         {5,8},{5,9},{5,10},{5,11},
                                         {6,8},{6,9},{6,10},{6,11},
                                         {7,8},{7,9},{7,10},{7,11}};
        int k = 3;
        s.minNumberOfSemesters(n,relations, k);
    }
    {
        int  n =12;
        vector<vector<int>> relations = {{1,2},{2,3},{4,5},{5,6},{7,8},{8,9},{10,11},{11,12}};
        int k =3;
        assert(s.minNumberOfSemesters(n,relations,k) == 4);
    }
{
        int n =13;
        vector<vector<int>> relations = {{12,8},{2,4},{3,7},{6,8},{11,8},{9,4},{9,7},{12,4},{11,4},{6,4},{1,4},{10,7},{10,4},{1,7},{1,8},{2,7},{8,4},{10,8},{12,7},{5,4},{3,4},{11,7},{7,4},{13,4},{9,8},{13,8}};
        int k = 9;
        s.minNumberOfSemesters(n,relations,k);
    }
    
    {

        int n = 4;
        vector<vector<int>> relations ={{2,1},{2,4}};
        int k = 2;

        assert(s.minNumberOfSemesters(n,relations,k)==2);
    }

    {
        int n = 5;
        vector<vector<int>> relations = {{3,1}};
        int k =4;
        s.minNumberOfSemesters(n,relations, k);
    }
    {

        int n =11;
        vector<vector<int>> relations = {};
        int k = 2;
        int expect = 6;
        assert(s.minNumberOfSemesters(n,relations,k) == expect);
    }
    {
        int n = 4;
        vector<vector<int>> relations = {{2,1},{3,1},{1,4}};
        int k = 2;
        int expect =  3;

        assert(s.minNumberOfSemesters(n,relations,k) == expect);
    }
    {
        int n = 5;
        vector<vector<int>> relations = {{2,1},{3,1},{4,1},{1,5}};
        int k = 2;
        int expect =  4;

        assert(s.minNumberOfSemesters(n,relations,k) == expect);
    }

}
