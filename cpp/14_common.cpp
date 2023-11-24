#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string ret = "";

        for(int i = 0; ;++i){

            char v = -1;
            bool allMatch = true;
            for(auto& s: strs){
                if(i == s.size()){
                    allMatch = false;
                    break;
                }
                if(v == (char) -1){
                    v = s[i];
                }else{
                    if(s[i]!=v){
                        allMatch = false;
                        break;
                    }
                }
            }

            if(allMatch){
                ret.push_back(v);
            }else{
                break;
            }
        }


        return ret;
    }
};
