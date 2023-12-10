#include <vector>
#include <cassert>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0){
            return false;
        }

        stringstream ss;
        ss<<x;
        string str;
        ss>>str;

        for(int i=0;i<str.size()/2;++i){
            if(str[i] != str[str.size()-1-i]){
                return false;
            }
        }

        return true;
        
    }
};
