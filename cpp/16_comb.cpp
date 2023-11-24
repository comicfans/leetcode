#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> possible = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


        vector<string> choosed;
        for(int d = 0; d< digits.size(); ++d){
            choosed.push_back(possible[digits[d]-'0']);
        }


        vector<int> chooseIdx;
        chooseIdx.resize(choosed.size());

        string prevStr ;
        prevStr.resize(digits.size(),0);

        vector<string> ret;

        while(true){
            string pickString;
            pickString.resize(digits.size());

            for(int i =0;i< digits.size();++i){
                pickString[i] = choosed[i][chooseIdx[i]];
            }

            bool skip = false;
            if(pickString <= prevStr){
                skip = true;
            }
            prevStr = pickString;
            if(!skip){
                ret.push_back(pickString);
            }


            // choose idx

            int addPos = digits.size()-1;
            while(addPos >= 0){
                chooseIdx[addPos]++;
                if(chooseIdx[addPos] == choosed[addPos].size()){

                    for(int j = addPos; j < choosed.size(); ++j){
                        chooseIdx[j] = 0;
                    }

                    --addPos;
                    continue;
                }else{
                    break;
                }
            }

            if(addPos < 0){
                break;
            }
        }

        return ret;

        
    }
};

int main(){
    Solution s;
    {
        s.letterCombinations("234");
    }
}
