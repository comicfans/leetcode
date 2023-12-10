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


        map<int, tuple<int,int,int>> modMaxEndLength;

        int ret = 0;
        for(int i=0; i< arr.size();++i){

            if(arr.size()-i< ret){
                break;
            }


            int begin = arr[i];
            // test if this subset of existing 

            auto existingPos = modMaxEndLength.find(abs(difference));


            if(difference == 0){
                if(existingPos != modMaxEndLength.end()){
                    continue;
                }
                

            }else{
                bool skip = false;

                if(existingPos != modMaxEndLength.end()){

                    auto beginEndLength = existingPos->second;
        
                    if((get<0>(beginEndLength) - begin) * (begin - get<1>(beginEndLength))>=0 ){
                        continue;
                    }
                }
            }

            

            tuple<int,int,int> thisTry = {begin,begin,1};

            auto nextPos = find(arr.begin() + i+1, arr.end(), begin + difference);
            while(nextPos != arr.end()){
                get<2>(thisTry)++;
                get<1>(thisTry) = *nextPos;
                nextPos = find(nextPos+1, arr.end(), *nextPos  + difference);
            }

            if(get<2>(thisTry)> get<2>(modMaxEndLength[abs(difference)])){
                modMaxEndLength[abs(difference)] = thisTry;
                ret = max(ret,get<2>(thisTry));
            }

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
