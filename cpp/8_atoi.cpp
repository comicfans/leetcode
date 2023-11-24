#include <limits>
#include <sstream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int myAtoi(string s) {

        int maxInt = numeric_limits<int>::max();
        int minInt = numeric_limits<int>::min();

        //throw leading space

        int currentPos = 0;
        for(int i=currentPos;i<s.size();++i){
            if(s[i] == ' '){
                ++currentPos;
            }else{
                break;
            }
        }
        if(currentPos == s.size()){
            return 0;
        }

        // detect digits or +/
        vector<char> digits;
        for(int i=0;i<=9;++i){
            digits.push_back('0'+i);
        }

        int sign = 1;
        if(s[currentPos] == '+'){
            sign = 1;
            ++currentPos;
        } else if(s[currentPos] == '-'){
            sign = -1;
            ++currentPos;
        } else{
            if(!binary_search(digits.begin(),digits.end(), s[currentPos])){
                return 0;
            }
        }
        //detect digits
        int64_t maybeBigger = 0;
        for(int i = currentPos; i <s.size();++i){

            if(!binary_search(digits.begin(),digits.end(),s[i])){
                //not number, return currentValue
                return sign * maybeBigger;
            }


            int thisNumber = (s[i] - '0');
            int64_t total = maybeBigger * 10 + thisNumber;

            if(sign > 0){
                if(total >  maxInt){
                    return maxInt;
                }else{
                    maybeBigger = total;
                    continue;
                }
            }

            //sign < 0
            if(total > -(int64_t)minInt){
                return minInt;
            }

            maybeBigger = total;
        }

        
        return sign * maybeBigger;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.myAtoi("42") == 42);
        assert(s.myAtoi("   -42") == -42);
        assert(s.myAtoi("4193 with words") == 4193);
        s.myAtoi("-91283472332");
    }
}
