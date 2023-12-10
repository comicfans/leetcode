#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {

        map<char,set<int>> pos;

        for(int i =0;i<s.size();++i){
            pos[s[i]].insert(i);
        }

        map<int,char> ret;
        int prevPos = -1;
        for(auto& kv:pos){

            auto& possible = kv.second; 

            //pick the one > end last pos
            auto pickPos = possible.lower_bound(prevPos+1);
            if(pickPos == possible.end()){
                --pickPos;
            }


            ret[*pickPos] = kv.first;
            prevPos = *pickPos;

        }

        string str;
        for(auto& kv :ret){
            str.push_back(kv.second);
        }

        return str;
        
    }
};

int main(){
    Solution s;
{
        auto res = s.removeDuplicateLetters("cbacdcbc");
        assert(res == "acdb");
    }
    {
        assert(s.removeDuplicateLetters("bcabc")=="abc");
    }
    
}

