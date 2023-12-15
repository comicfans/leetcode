#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {


        int offset [4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0;

        int x = 0;
        int y = 0;
        for(int i = 0;i<4;++i){

            for(auto c: instructions){

                switch(c){
                    case 'G':{
                        x+= offset[dir][0];
                        y+= offset[dir][1];
                        continue;
                    }
                    case 'L':{
                        dir = (dir+ 4 - 1) % 4;
                        continue;
                    }
                    case 'R':{
                        dir = (dir + 1) % 4;
                        continue;
                    }
                }


            }
        }

        if(x == 0 && y == 0){
            return true;
        }

        return false;
        
    }
};
