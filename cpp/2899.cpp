#include <vector>
#include <cassert>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {

        vector<int> ret;
        vector<int> nums;

        int prevCount = 0;
        for(auto str: words){

            if(str == "prev"){
                ++prevCount;

                if(prevCount> nums.size()){
                    ret.push_back(-1);;
                }else{
                    ret.push_back(nums[nums.size() - prevCount]);
                }
                continue;
            }

            prevCount = 0;

            stringstream s;
            s<<str;
            int number;
            s>>number;
            nums.push_back(number);
        }
        return ret;
        
    }
};
