#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {


        for(int i=0;i < s.size()/2;++i){

            if(s[i] == s[s.size()-1-i]){
                continue;
            }


            if(s[i+1] == s[s.size()-1-i]){
                if(rec(s+1,s.size()-i){
                }
            }

            if(s[i] == s[s.size()-1-i-1]){
                rightOffset = 1;
                continue;
            }

            return false;
        }

        return true;
    }

    bool rec(string s,int begin,int end) {
        int size = end - begin ;
        if(size <=1){
            return true;
        }


        for(int i=0;i < s.size()/2;++i){

            if(s[i+leftOffset] == s[s.size()-1-i - rightOffset]){
                continue;
            }

            if(leftOffset+ rightOffset>0){
                return false;
            }

            if(s[i+1] == s[s.size()-1-i]){
                leftOffset = 1;
                continue;
            }

            if(s[i] == s[s.size()-1-i-1]){
                rightOffset = 1;
                continue;
            }

            return false;
        }

        return true;
    }
};

int main(){
    Solution s;
    {
        string str = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        assert(s.validPalindrome(str));
    }
}

