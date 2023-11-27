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

    vector<vector<int>> cache;

    int knightDialer(int n) {

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

        if(cache.empty() ){
            for(int i =0;i<=9;++i){
                cache.push_back({1,(int)fromTo[i].size()});
            }
        }

        for(auto& c: cache){
            c.reserve(n-1);
        }


        for(int step = cache[0].size(); step <=n; ++step){
            for(int i = 0;i<=9;++i){

                long long total = 0;
                for(auto v: fromTo[i]){
                    total+= cache[v][step - 1];
                    total %= ((long long)pow(10,9)+7);
                }


                cache[i].push_back(total);
            }
        }


        long long ret = 0;
        for(const auto& v: cache){
            ret+= v[n-1];
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
