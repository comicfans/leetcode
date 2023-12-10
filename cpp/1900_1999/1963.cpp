#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSwaps(string s) {

        int badPos = 0;

        int left = 0;

        for(int i =0;i<s.size();++i){

            if(s[i] == '['){
                ++left;
                continue;
            }

            if(left==0){
                ++badPos;
                continue;
            }else{
                --left;
                continue;
            }


            

            ++badPos;
        }

        return badPos/2 + badPos %2;
    }
};


