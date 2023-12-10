#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
#include <iterator>



using namespace std;

vector<vector<int>> KEEP_DIFF = {{0,1,8},{2,5,6,9}};

class Solution {
public:

    

    int rotatedDigits(int n) {

        //first tell how many max digits of n
        //
        std::vector<int> digits;
        while(n>0){
            digits.push_back(n%10);
            n/=10;
        }

        reverse(digits.begin(),digits.end());

        //this is combination problem, for good number of digits n
        // it must be combined by at least one of DIFF, and any of possible

        int allDigits = recPick(false, false, digits, 0);

        // also add all less digit values
        
        int result = allDigits;
        int shorterDigits = digits.size()-1;
        if(shorterDigits > 0){
            if(!cache.count(shorterDigits)){
                cache[shorterDigits] = rotatedDigits(pow(10,shorterDigits)-1);
            }
            result += cache[shorterDigits];
        }

        return result;

        
    }

    int recPick(bool parentSmall, bool hasDiff, vector<int> digits, int thisIdx){
        if(thisIdx == digits.size()){
            //if no hasDiff, can't use, mul 0
            //if has Diff, ok
            //
            
            return (int)hasDiff;
        }



        int total = 0;
        for(int i=0;i<2;++i){

            if(parentSmall){
                int chooseAll = KEEP_DIFF[i].size();
                
                int thisSub = chooseAll * recPick(true,((bool)i)|| hasDiff,digits, thisIdx+1);

                total+= thisSub;
                continue;
            }
                
            //parent same, must pick <= values
            int smallChoose = 0;
            int sameChoose = 0;

            for(auto it = KEEP_DIFF[i].begin();it<KEEP_DIFF[i].end();++it){

                    if((thisIdx == 0) && (*it == 0)){
                        continue;
                    }

                    if(*it < digits[thisIdx]){
                        ++smallChoose;
                        continue;
                    }

                    if(*it == digits[thisIdx]){
                        sameChoose = 1;
                        break;
                    }

                    break;
            }
            if(smallChoose > 0){
                int smallSub = smallChoose * recPick(true,((bool)i)|| hasDiff,digits, thisIdx+1);
                total += smallSub;
            }

            if(sameChoose > 0){
                int sameSub = recPick(false,((bool)i)|| hasDiff, digits, thisIdx + 1);
                total += sameSub;
            }

        }

        return total;
    }

    std::map<int, int> cache;

};

int main(int ,char **){
    Solution s;

    {
        //s.rotatedDigits(99);
        assert(s.rotatedDigits(10)==4);
        assert(s.rotatedDigits(1)==0);
        assert(s.rotatedDigits(2)==1);
        assert(s.rotatedDigits(857)==247);
    }
}
