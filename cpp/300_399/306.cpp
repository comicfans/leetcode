#include <cstdint>
#include <vector>
#include <sstream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {

        if(num.size() < 3){
            return false;
        }

        for(int firstLength = 1; firstLength <= num.size()-2; ++firstLength){

            if((firstLength > 1) && (num[0] == '0')){
                return false;
            }
            
            stringstream ss;
            ss<< num.substr(0,firstLength);
            uint64_t firstNumber;
            ss>>firstNumber;

            for(int secondLength = 1; secondLength < (num.size() - firstLength);++secondLength ){
                if((secondLength > 1) && (num[firstLength]) == '0'){
                    break;
                }

                stringstream ss;
                ss<< num.substr(firstLength, secondLength);
                uint64_t secondNumber;
                ss>>secondNumber;


                uint64_t prev1 = firstNumber;
                uint64_t prev2 = secondNumber;
                int checkBegin = firstLength + secondLength;

                bool atLeastOne = true;

                while(true){

                    if(checkBegin == num.size()){
                        break;
                    }

                    uint64_t next = prev1 + prev2;
                    stringstream ss;
                    ss<<next;
                    string str;
                    ss>>str;

                    if(str.size() + checkBegin > num.size()){
                        atLeastOne = false;
                        break;
                    }else{

                        if(!equal(str.begin(),str.end(),num.begin()+checkBegin)){
                            atLeastOne = false;
                            break;
                        }else{
                            atLeastOne = true;
                            checkBegin = checkBegin + str.size();
                            prev1 = prev2;
                            prev2 = next;
                        }
                    }
                }

                if(atLeastOne){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution s;
    {
        assert(s.isAdditiveNumber("123"));
        assert(s.isAdditiveNumber("199111992"));
        assert(s.isAdditiveNumber("198019823962"));
    }
}
