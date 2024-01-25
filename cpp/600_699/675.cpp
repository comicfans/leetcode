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
        //speed up this
        //
        

        vector<vector<int>> steps = forest;
        for(auto& v: steps){
            fill(v.begin(),v.end(),numeric_limits<int>::max());
        }

        vector<pair<int,int>> toWalk = {{currentY, currentX}};
        int step = 0;
        steps[currentY][currentX] = step;

        while(!toWalk.empty()){
            vector<pair<int,int>> next;


            for(auto thisFrom: toWalk){

                if(thisFrom == pair<int,int>{targetY, targetX}){
                    return step;
                }
                assert(forest[thisFrom.first][thisFrom.second] != 0);


                for(int i =0 ;i < 4;++i){

                    static const int off[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
                    int newY = thisFrom.first + off[i][0];
                    int newX = thisFrom.second + off[i][1];

                    if(newY <0 || newY >= forest.size() || newX < 0 || newX >= forest[0].size()){
                        continue;
                    }

                    if(steps[newY][newX] != numeric_limits<int>::max()){
                        assert(steps[newY][newX] <= step+1);
                        continue;
                    }

                    if(forest[newY][newX] == 0){
                        continue;
                    }

                    steps[thisFrom.first][thisFrom.second] = step+1;
                    next.push_back({newY,newX});
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
        vector<vector<int>> forest = {{69438,55243,0,43779,5241,93591,73380},{847,49990,53242,21837,89404,63929,48214},{90332,49751,0,3088,16374,70121,25385},{14694,4338,87873,86281,5204,84169,5024},{31711,47313,1885,28332,11646,42583,31460},{59845,94855,29286,53221,9803,41305,60749},{95077,50343,27947,92852,0,0,19731},{86158,63553,56822,90251,0,23826,17478},{60387,23279,78048,78835,5310,99720,0},{74799,48845,60658,29773,96129,90443,14391},{65448,63358,78089,93914,7931,68804,72633},{93431,90868,55280,30860,59354,62083,47669},{81064,93220,22386,22341,95485,20696,13436},{50083,0,89399,43882,0,13593,27847},{0,12256,33652,69301,73395,93440,0},{42818,87197,81249,33936,7027,5744,64710},{35843,0,99746,52442,17494,49407,63016},{86042,44524,0,0,26787,97651,28572},{54183,83466,96754,89861,84143,13413,72921},{89405,52305,39907,27366,14603,0,14104},{70909,61104,70236,30365,0,30944,98378},{20124,87188,6515,98319,78146,99325,88919},{89669,0,64218,85795,2449,48939,12869},{93539,28909,90973,77642,0,72170,98359},{88628,16422,80512,0,38651,50854,55768},{13639,2889,74835,80416,26051,78859,25721},{90182,23154,16586,0,27459,3272,84893},{2480,33654,87321,93272,93079,0,38394},{34676,72427,95024,12240,72012,0,57763},{97957,56,83817,45472,0,24087,90245},{32056,0,92049,21380,4980,38458,3490},{21509,76628,0,90430,10113,76264,45840},{97192,58807,74165,65921,45726,47265,56084},{16276,27751,37985,47944,54895,80706,2372},{28438,53073,0,67255,38416,63354,69262},{23926,75497,91347,58436,73946,39565,10841},{34372,69647,44093,62680,32424,69858,68719},{24425,4014,94871,1031,99852,88692,31503},{24475,12295,33326,37771,37883,74568,25163},{0,18411,88185,60924,29028,69789,0},{34697,75631,7636,16190,60178,39082,7052},{24876,9570,53630,98605,22331,79320,88317},{27204,89103,15221,91346,35428,94251,62745},{26636,28759,12998,58412,38113,14678,0},{80871,79706,45325,3861,12504,0,4872},{79662,15626,995,80546,64775,0,68820},{25160,82123,81706,21494,92958,33594,5243}};
        s.cutOffTree(forest);
    }
    {
        vector<vector<int>> forest ={{6304,8591,1651,4114,407,3998,4382},{6614,927,235,3358,9086,4986,8284},{8505,3117,8012,0,5724,3323,6157},{8799,3083,8817,5648,3113,8562,8787},{2931,4668,4378,3901,8718,9635,41},{6223,4425,509,0,4855,0,0},{1685,6117,732,9372,9975,6939,6405},{4133,9246,4867,0,723,9105,9484},{2910,2771,8412,2757,8148,7315,5379}};
        assert(s.cutOffTree(forest) == 338);
    }
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
