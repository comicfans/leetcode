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

        
       
        auto startPos = find_if(start.begin(),start.end(),[](auto c){
            return c=='L' || c=='R';
        }) - start.begin();
        auto targetPos = find_if(target.begin(),target.end(),[](auto c){
            return c== 'L' || c == 'R';
        }) - target.begin();

        while(startPos != start.size()){

            if(start[startPos] != target[targetPos]){
                return false;
            }

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

        if(targetPos!= target.size()){
            return false;
        }


        return true;

    }
};
