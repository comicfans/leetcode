#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canChange(string start, string target) {

        
        auto compact = [](const string& input){
            string ret;
            for(auto c:input){
                if(c == '_'){
                    continue;
                }
                ret.push_back(c);
            }
            return ret;
        };

        auto compactStart = compact(start);
        auto compactTarget = compact(target);
        if(compactStart != compactTarget){
            return false;
        }

        //for every pair of L, or R, only possible

        // open     to L 
        // less     to L
        //
        // open to R
        // more to R
        // 
        //   L  to  R

        //   L more R
        //   R to  L
        //     less 


        auto startPos = find_if(start.begin(),start.end(),[](auto c){
            return c=='L' || c=='R';
        }) - start.begin();
        auto targetPos = find_if(target.begin(),target.end(),[](auto c){
            return c== 'L' || c == 'R';
        }) - target.begin();

        while(startPos != start.size()){

            assert(start[startPos] == target[targetPos]);

            if(start[startPos] == 'L'){
                if(targetPos > startPos){
                    return false;
                }
            }else{
                //is right

                if(targetPos < startPos){
                    return false;
                }
            }

            startPos = find_if(start.begin()+startPos + 1,start.end(),[](auto c){
                return c=='L' || c=='R';
            }) - start.begin();
            targetPos = find_if(target.begin()+targetPos + 1,target.end(),[](auto c){
                return c== 'L' || c == 'R';
            }) - target.begin();



        }
        return true;

    }
};
