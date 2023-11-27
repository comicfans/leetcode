#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:


    int knightDialer(int n) {

        if(n == 1){
            return 10;
        }


        vector<vector<int>> pad;
        for(int i = 0;i<3;++i){
            vector<int> row;
            for(int j = 0;j<3;++j){
                row.push_back(i*3+j+1);
            }
            pad.push_back(row);
        }

        pad.push_back({-1,0,-1});

        vector<vector<int>> fromTo;
        fromTo.resize(10);



        for(int y = 0;y<pad.size();++y){
            for(int x = 0;x<3;++x){

                int yOffset[] = {-2,-1,1,2};

                for(int thisYOffset: yOffset){

                    int xOffset = 3- abs(thisYOffset);

                    for(int sign:{-1,1}){

                        int fromNum = pad[y][x];

                        if(fromNum == -1){
                            continue;
                        }

                        int targetY = y+thisYOffset;
                        int targetX = x + xOffset * sign;

                        if(targetY <0 || targetY >= pad.size() || targetX < 0 || targetX >=3){
                            continue;
                        }

                        int targetNum = pad[targetY][targetX];
                        if(targetNum == -1){
                            continue;
                        }
                        

                        fromTo[fromNum].push_back(targetNum);
                    }

                }
            }
        }

        vector<int> lastCount(10);
        for(int i =0;i<=9;++i){
            lastCount[i] = fromTo[i].size();
        }



        vector<int> thisStep(10);
        for(int step = 2; step <n; ++step){
            for(int i = 0;i<=9;++i){
                long long total = 0;
                for(auto v: fromTo[i]){
                    total+= lastCount[v];
                    total %= ((long long)pow(10,9)+7);
                }


                thisStep[i]=total;
            }
            swap(lastCount, thisStep);
        }

        long long ret = 0;
        for(const auto& v: lastCount){
            ret+= v;
            ret %= ((long long)pow(10,9)+7);
        }

        return ret ;
    }
};

int main(){
    Solution s;
    assert(s.knightDialer(1)==10);
    assert(s.knightDialer(2)==20);
    assert(s.knightDialer(3131)==136006598);
}
