#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {

        vector<int> all;
        all.resize(n);

        map<int,map<int,int>> edgeNumber;
        map<int,set<int>> to_from;

        for(const auto from_to: requests){
            if(from_to[0] == from_to[1]){
                continue;
            }
            all[from_to[0]]--;
            all[from_to[1]]++;
            edgeNumber[from_to[0]][from_to[1]]++;
            to_from[from_to[1]].insert(from_to[0]);
        }

        //pick minimum set of requests, makes all zero

        int bestOfAll = requests.size();
        return requests.size() - pickSet(all, edgeNumber, to_from, 0, bestOfAll);

    }

    int pickSet(vector<int>& all,
                map<int,map<int,int>>& edgeNumber,
                map<int,set<int>>& to_from,
                int alreadyPicked, int bestOfAll){

        if (alreadyPicked >= bestOfAll){
            return bestOfAll;
        }

        auto nonZeroPos = find_if(all.begin(),all.end(),[](auto v){
            return v!=0;
        });

        if (nonZeroPos == all.end()){
            return alreadyPicked;
        }

        int delta = *nonZeroPos;

        auto idx = nonZeroPos - all.begin();

        set<pair<int,int>> from_to_try;
        if(delta < 0){
            // output too many, should remove one edge that to thisPos

            assert(edgeNumber.count(idx));
            for(const auto& v:edgeNumber[idx]){
                if(v.second>0){
                    from_to_try.insert({idx, v.first});
                }
            }

        }else{
            //find reverse 
            auto pos = to_from.find(idx);
            if(pos != to_from.end()){
                for(const auto& v: pos->second){
                    assert(edgeNumber.at(v).at(idx)>=0);
                    if(edgeNumber.at(v).at(idx)==0){
                        continue;
                    }
                    from_to_try.insert({v,idx});
                    assert(edgeNumber.at(v).count(idx));
                }
            }
        }

        for(const auto tryThis: from_to_try){

            assert(edgeNumber.at(tryThis.first).at(tryThis.second) > 0);
            assert(to_from.at(tryThis.second).count(tryThis.first));

            //take this out of graph
            edgeNumber.at(tryThis.first).at(tryThis.second)--;
            all[tryThis.first]++;
            all[tryThis.second]--;

            int thisTry = pickSet(all,edgeNumber,to_from, alreadyPicked+1, bestOfAll);
            bestOfAll = min(bestOfAll, thisTry);

            all[tryThis.first]--;
            all[tryThis.second]++;
            edgeNumber.at(tryThis.first).at(tryThis.second)++;
        }
        //try to pick one to make it 
        return bestOfAll;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> seq = {{0,1},{1,0},{0,1},{1,2},{2,0},{3,4}};

        assert(s.maximumRequests(5, seq) == 5);

    }
    {
        vector<vector<int>> seq = {{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};

        assert(s.maximumRequests(5, seq) == 4);

    }
    {
        vector<vector<int>> seq = {{0,0},{1,2},{2,1}};

        assert(s.maximumRequests(3, seq) == 3);

    }
    {
        vector<vector<int>> seq = {{0,0},{1,1},{0,0},{2,0},{2,2},{1,1},{2,1},{0,1},{0,1}};

        assert(s.maximumRequests(3, seq) == 5);

    }
    {
        vector<vector<int>> seq = {{0,3},{3,1},{1,2},{2,0}};

        //assert(
        s.maximumRequests(4, seq);
        //== 5);

    }
    {
        vector<vector<int>> seq = 
            {{1,2},{2,2},{0,0},{1,1},{0,2},{0,0},{2,1},{0,1},{1,0},{2,2},{0,1},{2,0},{2,2}};

        assert(s.maximumRequests(3, seq) == 12);
    }
}
