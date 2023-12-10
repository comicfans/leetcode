#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {


        for(int i = left;i<=right;++i){
            bool inRange = false;
            for(auto& range: ranges){
                if(i >= range[0] && i<=range[1]){
                    inRange = true;
                    break;
                }
            }
            if(!inRange){
                return false;
            }
        }
        return true;
        
    }
};
