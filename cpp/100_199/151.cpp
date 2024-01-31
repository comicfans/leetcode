#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ret;

        int noSpacePos = find_if(s.rbegin(),s.rend(),[](char c){
            return c != ' ';
        }) - s.rbegin();

        while(noSpacePos < s.size()){

            int nextSpacePos = find(s.rbegin()+noSpacePos, s.rend(),' ') - s.rbegin();

            reverse_copy(s.rbegin()+noSpacePos, s.rbegin()+ nextSpacePos, back_inserter(ret));

            ret.push_back(' ');

            noSpacePos = find_if(s.rbegin()+nextSpacePos+1,s.rend(),[](char c){
                return c != ' ';
            }) - s.rbegin();
        }
        
        

        if(ret.size()>1 && ret.back()==' '){
            ret.pop_back();
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        string input = "  hello world  ";
        string expect =  "world hello";
        auto res = s.reverseWords(input);
        assert(res == expect);
    }
    {
        string input = "the sky is blue";
        auto res = s.reverseWords(input);
        assert(res == "blue is sky the");
    }
    {
        string input = "a good   example";
        string expect =  "example good a";
        auto res = s.reverseWords(input);
        assert(res == expect);
    }
}
