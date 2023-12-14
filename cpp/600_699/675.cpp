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
    int cutOffTree(vector<vector<int>>& forest) {

        if(forest[0][0] == 0){
            return -1;
        }

        vector<pair<int,pair<int,int>>> heightPos;
        for(int y = 0;y< forest.size();++y){
            const auto& row= forest[y];

        
            for(int x = 0; x < forest[y].size(); ++x){
                 auto v = forest[y][x];
                if(v>1){
                    heightPos.push_back({v,{y,x}});
                }
            }
        }

        // sort by height is enough
        sort(heightPos.begin(),heightPos.end(),[](auto& lhs,auto& rhs){
            return get<0>(lhs) < get<0>(rhs);
        });

        //must cut from head to back

        int ret = recCut(forest, 0,0, heightPos, 0);
        return ret == numeric_limits<int>::max()? -1 : ret;
        
    }

    int recCut(vector<vector<int>>& forest, int currentY, int currentX,
               const vector<pair<int,pair<int,int>>>& heightPos, int heightIdx){

        if(heightIdx == heightPos.size()){
            return 0;
        }

        int targetHeight = get<0>(heightPos[heightIdx]);

            auto& thisTarget = heightPos[heightIdx];
            int targetY= thisTarget.second.first;
            int targetX =thisTarget.second.second;

            forest[targetY][targetX] = 1;
            int singleWalk = walk(forest, currentY,currentX, targetY,targetX);
            forest[targetY][targetX] = get<0>(thisTarget);

            if(singleWalk == numeric_limits<int>::max()){
                //this can't walk
                return singleWalk;
            }

            forest[targetY][targetX] = 1;
            int leftWalk = recCut(forest, targetY, targetX, heightPos, heightIdx + 1);
            forest[targetY][targetX] = get<0>(thisTarget);

            if(leftWalk == numeric_limits<int>::max()){
                return leftWalk;
            }

            int thisPath = singleWalk + leftWalk;


        return thisPath;
    }

    int walk(const vector<vector<int>>& forest, int currentY, int currentX, int targetY, int targetX){

        vector<vector<int>> steps = forest;
        for(auto& v: steps){
            fill(v.begin(),v.end(),numeric_limits<int>::max());
        }

        set<pair<int,int>> toWalk = {{currentY, currentX}};

        int step = 0;
        while(!toWalk.empty()){
            set<pair<int,int>> next;
            for(auto thisFrom: toWalk){

                if(thisFrom == pair<int,int>{targetY, targetX}){
                    return step;
                }
                assert(forest[thisFrom.first][thisFrom.second] != 0);

                steps[thisFrom.first][thisFrom.second] = step;

                for(int i =0 ;i < 4;++i){

                    static const int off[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
                    int newY = thisFrom.first + off[i][0];
                    int newX = thisFrom.second + off[i][1];

                    if(newY <0 || newY >= forest.size() || newX < 0 || newX >= forest[0].size()){
                        continue;
                    }

                    if(steps[newY][newX] != numeric_limits<int>::max()){
                        assert(steps[newY][newX] <= step);
                        continue;
                    }

                    if(forest[newY][newX] == 0){
                        continue;
                    }
                    next.insert({newY,newX});
                }
            }

            swap(next, toWalk);
            ++step;
        }
        return numeric_limits<int>::max();
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> forest = {{1,2,3},{0,0,0},{7,6,5}};
        assert(s.cutOffTree(forest) == -1);
    }
    {
       vector<vector<int>> forest={{9, 12, 5, 14}, {17, 11, 13, 15}, {2, 20, 19, 21}, {16, 4, 7, 8}, {18, 3, 6, 10}};


        //vector<vector<int>> forest = {{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
        assert(s.cutOffTree(forest) == 57);
    }
    {
        vector<vector<int>> res = {{2395,206,0,5388},{4985,2866,0,1789},{0,0,7052,0},{0,3029,3327,685},{0,0,7846,0},{0,0,1542,0},{7577,0,2902,623},{2610,9817,0,8198}};
    }
    {
        vector<vector<int>> forest = {{0,0,0,3528,2256,9394,3153},{8740,1758,6319,3400,4502,7475,6812},{0,0,3079,6312,0,0,0},{6828,0,0,0,0,0,8145},{6964,4631,0,0,0,4811,0},{0,0,0,0,9734,4696,4246},{3413,8887,0,4766,0,0,0},{7739,0,0,2920,0,5321,2250},{3032,0,3015,0,3269,8582,0}};
        s.cutOffTree(forest);
    }

    {
        vector<vector<int>> forest = {{1,2,3},{0,0,4},{7,6,5}};
        assert(s.cutOffTree(forest) == 6);
    }
}
