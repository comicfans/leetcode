#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> fromTo;
        map<char,char> toFrom;
        for(int i =0;i<s.size();++i){
            auto toPos = fromTo.find(s[i]);
            auto fromPos = toFrom.find(t[i]);

            bool hasTo = (toPos != fromTo.end());
            bool hasFrom = (fromPos != toFrom.end());

            if(hasTo != hasFrom){
                return false;
            }

            if(!hasTo){
                fromTo[s[i]] = t[i];
                toFrom[t[i]] = s[i];
                continue;
            }

            if(toPos->second != t[i] || fromPos->second != s[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    {
        string input = "egg", output = "add";
        assert(s.isIsomorphic(input,output));
    }
    {
        string input = "foo", output = "bar";
        assert(!s.isIsomorphic(input,output));
    }
    {
        string input = "paper", output = "title";
        assert(s.isIsomorphic(input,output));
    }

}
