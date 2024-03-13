#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>


using namespace std;






class Solution {
public:
    string originalDigits(string s) {
map<char, array<int,10> > charCoef =
      //0,1,2,3,4,5,6,7,8,9  
    //----------------------
{{'e', {1,1,0,2,0,1,0,2,1,1}},
 {'f', {0,0,0,0,1,1,0,0,0,0}},
 {'g', {0,0,0,0,0,0,0,0,1,0}},
 {'h', {0,0,0,1,0,0,0,0,1,0}},
 {'i', {0,0,0,0,0,1,1,0,1,1}},
 {'n', {0,1,0,0,0,0,0,1,0,2}},
 {'o', {1,1,1,0,1,0,0,0,0,0}},
 {'r', {1,0,0,1,1,0,0,0,0,0}},
 {'s', {0,0,0,0,0,0,1,1,0,0}},
 {'t', {0,0,1,1,0,0,0,0,1,0}},
 {'u', {0,0,0,0,1,0,0,0,0,0}},
 {'v', {0,0,0,0,0,1,0,1,0,0}},
 {'w', {0,0,1,0,0,0,0,0,0,0}},
 {'x', {0,0,0,0,0,0,1,0,0,0}},
 {'z', {1,0,0,0,0,0,0,0,0,0}}};

        map<char, int> input;
        for(auto c: s){
            input[c]++;
        }
       

        vector<int> count(10,-1);
        //iterate to find row that only has one variable unknown

        for(auto chPos = charCoef.begin(); chPos != charCoef.end(); ){
            if(input.count(chPos->first) != 0){
                ++chPos;
                continue;
            }

            for(int i = 0; i< 10 ; ++i){
                if(chPos->second[i]!=0){
                    count[i] = 0;
                }
            }
            auto temp = chPos;
            ++chPos;
            charCoef.erase(temp);
        }

        int left = s.size();

        int numberSize[] = {4,3,3, 5,4, 4,3,5,5,4};

        while(!charCoef.empty() && left > 0){
            for(auto charPos = charCoef.begin(); charPos != charCoef.end(); ++charPos){

                auto ch= charPos->first;
                const auto& thisRow = charPos->second;

                int unknownNumber = 10;

                int knownSum = 0;
                int unknownV = -1;
                for(int i = 0;i <10; ++i){
                    if(thisRow[i] == 0){
                        //coef is zero
                        --unknownNumber;
                    }else if(count[i] != -1){
                        knownSum += count[i] * thisRow[i];
                        --unknownNumber;
                    }else{
                        unknownV = i;
                    }
                }

                if(unknownNumber != 1){
                    continue;
                }

                //unknown number = 1
                int right = input.at(ch) - knownSum;

                assert(right % thisRow[unknownV] == 0);
                count[unknownV] = right / thisRow[unknownV];
                charCoef.erase(charPos);
                left -= count[unknownV] * numberSize[unknownV];
                break;
            }
        }

        string ret;
        for(int i = 0; i< 10; ++i){
            if(count[i] == -1 || count[i] == 0){
                continue;
            }

            ret+= string(count[i],i+'0');
        }

        return ret;

    }

    


};

int main(){
    Solution s;
    {
        string input = "neo";
        auto res = s.originalDigits(input);
        assert(res== "1");
    }
    {
        string input = "owoztneoer";
        auto res = s.originalDigits(input);
        assert(res== "012");
    }
}
