#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> cache(s.size());

        sort(wordDict.begin(),wordDict.end(),[](auto &lhs,auto &rhs){
            return lhs.front() < rhs.front();
        });

        auto res = recBreak(s, wordDict, 0, cache);
        if(res.size()==1 && res.front()==""){
            return {};
        }
        return res;
    }

    vector<string>  recBreak(const string& s, const vector<string>& wordDict, int pos, vector<vector<string>>& cache){

        

        auto &cacheEntry = cache[pos];

        if(!cacheEntry.empty()){
            return cacheEntry;
        }

        string toSearch;
        toSearch.push_back(s[pos]);
        auto eqRange = equal_range(wordDict.begin(),wordDict.end(),toSearch,[](const auto lhs,const auto rhs){
            return lhs.front() < rhs.front();
        });

        for(auto it= eqRange.first;it !=  eqRange.second;++it){

            const auto& w = *it;
            if(!equal(w.begin(),w.end(), s.begin()+pos, s.begin() + min((int)pos + (int)w.size(), (int)s.size()))){
                continue;
            }


            int newPos = pos + w.size();

            if(newPos == s.size()){
                cacheEntry.push_back(w);
                continue;
            }

            auto sub = recBreak(s,wordDict,newPos, cache);

            if(sub.size()==1 && sub.front()==""){
                continue;
            }

            for(const auto &str: sub){
                cacheEntry.push_back(w+ " " +str);
            }

        }

        if(cacheEntry.empty()){
            cacheEntry.push_back("");
        }

        return cacheEntry;
    }
};

int main(){
    Solution s;
    {
        string input = "catsanddog";
        vector<string> wordDict = {"cat","cats","and","sand","dog"};
        vector<string> expect =  {"cats and dog","cat sand dog"};
        auto res = s.wordBreak(input,wordDict);
        sort(res.begin(),res.end());
        sort(expect.begin(),expect.end());
        assert(expect == res);
    }
}
