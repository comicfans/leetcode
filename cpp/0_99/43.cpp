#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {

        vector<int> single(num1.size() + num2.size());

        for(int pos1 = 0; pos1 < num1.size(); ++pos1){
            for(int pos2 = 0; pos2 < num2.size(); ++pos2){
                int from1 = num1[num1.size()-1-pos1] - '0';
                int from2 = num2[num2.size()-1 - pos2] - '0';

                int offset = pos1 + pos2;
                int mul = from1 * from2;

                int bit = 0;
                while(mul > 0){
                    single[offset + bit] += mul % 10;
                    mul /=  10;
                    ++bit;
                }
            }
        }

        int inc = 0;
        for(int pos = 0; pos < single.size(); ++pos){
            int thisNum = single[pos];
            thisNum += inc;
            single[pos] = thisNum % 10;
            inc = thisNum / 10;
        }

        for(int back = single.size()-1;back >= 0; --back){
            if(single[back] == 0){
                single.pop_back();
            }else{
                break;
            }
        }
        if(single.empty()){
            return "0";
        }

        string ret;
        for(int pos = 0;pos < single.size(); ++pos){

            ret.push_back(single[single.size()-1-pos]+'0');

        }
        return ret;
    }
};

int main(){
    Solution s;
    {
        string num1 = "123";
        string num2 = "456";
        auto res = s.multiply(num1,num2);
        assert(res == "56088");
    }
}
