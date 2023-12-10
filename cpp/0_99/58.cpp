#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {

        int ret = 0;
        for(int i = s.size()-1;i>=0;--i){
            if(s[i]==' '){
                if(ret>0){
                    return ret;
                }
                continue;
            }

            //not space
            ++ret;
        }

        return ret;
        
    }
};

int main(){


    Solution s;
    {
        string input = "hello world";
        assert(s.lengthOfLastWord(input) == 5);
    }
}
