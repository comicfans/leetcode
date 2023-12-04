#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countCollisions(string directions) {

        int ret = 0;

        int runningR = 0;
        char lastState = 'L';
        for(int i =0;i<directions.size();++i){

            char thisDir = directions[i];


            if(thisDir == 'S'){
                ret += runningR;
                lastState = thisDir;
                runningR = 0;
                continue;
            }


            if(thisDir == 'L'){
                char nextState = 'L';
                if(runningR > 0){
                    ret += (runningR +1);
                    nextState = 'S';
                }
                
                if(lastState == 'S'){
                    ret++;
                    nextState = 'S';
                }
                
                lastState = nextState;

                runningR = 0;
                continue;
            }

            ++runningR;
            lastState = thisDir;
        }
        

        

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        string input = "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR";
        assert(s.countCollisions(input) == 20);
    }
    {


        string input = "RLRSLL";
        assert(s.countCollisions(input) == 5);
    }
    {


        string input = "LLRR";
        assert(s.countCollisions(input) == 0);
    }
}
