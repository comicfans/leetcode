#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        string quickTest = s;
        sort(quickTest.begin(),quickTest.end());
        quickTest.resize(unique(quickTest.begin(),quickTest.end())-quickTest.begin());

        for(auto ch: quickTest){

            bool atLeastOne = false;
            for(auto d:wordDict){

                if(d.find(ch)!=string::npos){
                    atLeastOne  =true;
                    break;
                }
            }

            if(!atLeastOne){
                return false;
            }
        }



        sort(wordDict.begin(),wordDict.end());

        vector<int> canMatch(s.size(),-1);
        return recMatch(s, wordDict, 0,canMatch);
        
    }

    bool recMatch(const string& s, const vector<string>& dict, int pos, vector<int>& canMatch){
        if(pos== s.size()){
            return true;
        }

        if(canMatch[pos] != -1){
            return canMatch[pos];
        }


        auto firstChar = s[pos];

        string toMatch(1,firstChar);
        auto searchBegin = lower_bound(dict.begin(),dict.end(),toMatch);

        int lengthLeft = s.size() - pos;
        for(auto it = searchBegin;it!=dict.end();++it){


            if((*it)[0]!= firstChar){
                break;
            }

            if(it->length() > lengthLeft){
                continue;
            }

            auto thisMatch = equal(it->begin(),it->end(),s.begin()+pos);
            if(!thisMatch){
                continue;
            }

            auto subMatch = recMatch(s,dict,  pos+ it->length(),canMatch);
            if(subMatch){
                return true;
            }

        }
        canMatch[pos] = 0;
        return false;
    }
};

int main(
){

    Solution s;
    {
string str= "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        vector<string> dict = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
        s.wordBreak(str,dict);
    }
    {
        vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        assert(!s.wordBreak(str,dict));
    }
    {
        vector<string> dict = {"pie","pear","apple","peach"};
        assert(s.wordBreak("applepie",dict));
    }
    {
        vector<string> dict = {"leet","code"};
        assert(s.wordBreak("leetcode",dict));

    }
    
}
