#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {


        map<int, pair<int,int>> beginMaxEndLength;

        for(int i=0; i< arr.size();++i){


            int begin = arr[i];
            // test if this subset of existing 

            bool skip = false;
            for(const auto &kv: beginMaxEndLength){
                if((kv.second.first - begin) * (begin - kv.first)>=0 ){
                    if(difference == 0){
                        skip = true;
                        break;
                    }

                    int delta = abs(kv.second.first - begin);
                    int absD = abs(difference);
                    
                    if(delta % absD == 0){
                        skip = true;
                        break;
                    }
                }
            }

            if(skip){
                continue;
            }

            auto &resultEntry = beginMaxEndLength[begin];
            resultEntry.first = begin;
            resultEntry.second = 1;
            auto nextPos = find(arr.begin() + i+1, arr.end(), begin + difference);
            while(nextPos != arr.end()){
                resultEntry.second ++;
                resultEntry.first = *nextPos;
                nextPos = find(nextPos+1, arr.end(), *nextPos  + difference);
            }
        }

        int ret = 0;
        for(auto& kv: beginMaxEndLength){
            ret = max(ret, kv.second.second);
        }
        
        return ret;
    }
};

int main(
){
    Solution s;
    {
        vector <int> input = {16,-4,-6,-11,-8,-9,4,-11,15,15,-9,11,7,-7,10,-16,4};
        assert(s.longestSubsequence(input, 3) == 3);
    }
}
