#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string sortSentence(string s) {

        map<int,string> words;
        int prevEnd = -1;

        for(int i =0 ;i <= s.size();++i){

            if(s[i] == ' ' || i == s.size()){
                words[s[i-1] - '0'] = s.substr(prevEnd+1, i-prevEnd-1-1);
                prevEnd = i;
            }
        }
        
        string ret;
        for(auto &kv: words){
            if(kv.first!=1){
                ret+=' ';
            }
            ret+=kv.second;
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        assert(s.sortSentence("is2 sentence4 This1 a3")=="This is a sentence");
    }

}
