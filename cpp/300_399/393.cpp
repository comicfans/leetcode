#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool validUtf8(vector<int>& data) {

        int pos = 0;

        while(pos != data.size()){

            int head = data[pos];

            if((head & (1<<7)) == 0){
                ++pos;
                continue;
            }

            int byteNumber = 0;
            if((head & (7 << 5)) == (3<<6)){
                byteNumber = 2;
            }else if((head & (15 << 4)) == (7 << 5)){
                byteNumber = 3;
            }else if((head & (31 << 3)) == (15 << 4)){
                byteNumber = 4;
            }else{
                return false;
            }

            if(byteNumber + pos > data.size()){
                return false;
            }

            for(int check = 1; check < byteNumber ; ++check){
                int v = data[pos + check];
                if((v & (3 << 6)) != (1 << 7)){
                    return false;
                }
            }
            pos = pos+byteNumber;


        }

        return true;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> data = {197,130,1};
        assert(s.validUtf8(data));
    }
{
        vector<int> data = {235,140,4};
        assert(!s.validUtf8(data));
    }
}
