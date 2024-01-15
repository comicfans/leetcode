#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {

        vector<string> ret;

        for(const auto s:words){

            bool newOne = true;
            for(auto c: s){
                if(c == separator){
                    newOne = true;
                    continue;
                }


                if(newOne){
                    ret.push_back(string({c}));
                }else{
                    ret.back().push_back(c);
                }
                newOne = false;
            }
        }
        return ret;
        
    }
};
