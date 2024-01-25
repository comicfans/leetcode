#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.size()-1;

        while(left < right && left < s.size() && right >=0){

            if(!isalpha(s[left]) && !(s[left] >= '0' && s[left] <= '9')){
                ++left;
                continue;
            }

            if(!isalpha(s[right]) && !(s[right] >= '0' && s[right] <= '9')){
                --right;
                continue;
            }

            if(tolower(s[left]) != tolower(s[right])){
                return false;

            }
                ++left;
                --right;

        }
        return true;
        
    }
};
int main(){
    Solution s;
    {
        string a = "0P";
        assert(!s.isPalindrome(a));
    }

}
