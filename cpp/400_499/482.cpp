#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string ret;

        int number = 0;
        for(int i = s.size()-1;i>=0;--i){
            
            if(s[i]=='-'){
                continue;
            }
            
            ret.push_back(toupper(s[i]));
            ++number;

            if(number %k == 0){
                ret.push_back('-');
            }
        }

        for(int i = ret.size()-1;i>=0;--i){
            if(ret[i]=='-'){
                ret.pop_back();
            }else{
                break;
            }
        }


        reverse(ret.begin(),ret.end());

        return ret;

    }
};
