#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ret;

        int charCount[26] = {0};
        for(auto c: p){
            charCount[c- 'a']++;
        }

        int check[26]={0};
        for(int i = 0;i< s.size(); ++i){

            check[s[i] - 'a'] ++;

            bool eq = equal(check, check+26, charCount);

            if(eq){
                ret.push_back(i - p.size() + 1);
            }

            if(i >= p.size() - 1){
                check[s[i +1 - p.size() ] - 'a' ] --;
            }
        }

        return ret;
        
    }
};

int main(){
    Solution s;
    {
        string input = "cbaebabacd";
        string p = "abc";
        vector<int> expect = {0,6};
        auto res = s.findAnagrams(input, p);
        assert(expect == res);
    }
}
