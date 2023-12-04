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
        for(int i =0;i<directions.size();++i){

            char thisDir = directions[i];


            if(thisDir == 'S'){
             if(i == 0){
                    continue;
                }   

                switch (directions[i-1]){
                    case 'S':
                    case 'L':{
                        continue;
                    }
                    case 'R':
                    {
                        ret += 1;
                        directions[i-1] = 'S';
                    }
                }

                continue;
            }


            if(thisDir == 'L'){
                if(i == 0){
                    continue;
                }
                switch(directions[i-1]){
                    case 'S':{
                        ret+=1;
                        directions[i] = 'S';
                        break;
                    }
                    case 'R':{
                        directions[i-1] = 'S';
                        directions[i] = 'S';
                        ret+=2;
                        break;
                    }
                    
                }
                continue;
            }


            //this is R,only skip when right are end or no S/L
            if(i == directions.size()-1){
                break;
            }

            bool noStop = true;

            for(int lookahead = i+1;lookahead < directions.size();++lookahead){
                if(directions[lookahead]!= 'R'){
                    noStop = false;
                    break;
                }
            }

            if(noStop){
                continue;
            }

            char next = directions[i+1];
            if(next == 'R'){
                ret+=1;
                directions[i] = 'S';
            }
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
