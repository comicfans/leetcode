#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumOperations(string num) {

        // div by 25
        // 00
        // 25
        // 50
        // 75

        string possible[] = {"00","25","50","75"};

        int state[4] = {0};

        for(int i = num.size()-1; i >= 0; --i){
            for(int tryThis =0; tryThis < 4;++tryThis){
                if(state[tryThis] == 0){
                    if(num[i] == possible[tryThis][1]){
                        state[tryThis] = 1;
                    }
                    continue;
                }

                if(state[tryThis] == 1){
                    if(num[i] == possible[tryThis][0]){
                        int res = (num.size()-i-2);
                        return res;
                    }
                }

            }

        }

        //can't found
        auto zeroPos = num.find("0");
        if(zeroPos != string::npos){
            return num.size() -1; 
        }


        return num.size(); 
        
        
    }
};

int main(){
    Solution s;
    {
        string input = "2245047";
        assert(s.minimumOperations(input) == 2);
    }
}
