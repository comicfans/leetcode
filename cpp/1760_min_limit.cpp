#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {

        map<int,int> mp;
        for(auto &v: nums){
            mp[v]++;
        }

        //give its a virtual value
        mp[0] = 0;

        while(mp.size()>2){

            auto endPos = mp.end();
            --endPos;
            auto maxValue = endPos->first;
            auto maxNumber = endPos->second;
            --endPos;
            auto secondMax = *endPos;

        }



        
    }
};
