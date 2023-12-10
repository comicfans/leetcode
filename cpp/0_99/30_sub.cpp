#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        set<int> appear;

        set<int> index;
        recTry(s, 0, words, appear, index, -1);
        
        return vector<int>(appear.begin(),appear.end());
    }

    void recTry(const string& s, int matchPos, const vector<string>& words,
                set<int>& appear,set<int> index, int thisHead){

        if(index.size() == words.size()){
            appear.insert(thisHead);
            index.clear();
            return;
        }

        bool firstTry = index.empty();

        set<int> newTry;

        int leftTry = words.size() - index.size();
        if(s.size() - matchPos < words[0].size() * leftTry){
            return;
        }
        

        set<int> tried;
        for(int tryIdx = 0;tryIdx < words.size(); ++ tryIdx){
            if(index.count(tryIdx)){
                continue;
            }



            bool skip = false;
            for(auto k: tried){
                if(words[tryIdx] == words[k]){
                    skip= true;
                    break;
                }
            }

            if(skip){
                continue;
            }

            tried.insert(tryIdx);



            string::size_type pos = matchPos;
            while(true){


                if(firstTry){
                    pos = s.find(words[tryIdx], pos);
                }else{
                    if(!equal(s.begin()+matchPos, s.begin()+matchPos + words[0].size(),
                             words[tryIdx].begin(),words[tryIdx].end())){
                        break;
                    }else{
                        pos = matchPos;
                    }
                }

                if(pos == string::npos){
                    break;
                }

                set<int> existing = index;
                existing.insert(tryIdx);
                
                recTry(s, pos + words[0].size(), words, appear, existing, firstTry? pos: thisHead);
                if(firstTry){
                    ++pos;
                }else{
                    break;
                }
            }
        }

    }
};

int main(){
    Solution s;
    {
        std::string str ="aaaaaaaaaaaaaa";
        vector<string> words = {"aa","aa"};

        vector<int> expect = {0,1,2,3,4,5,6,7,8,9,10};
        auto res = s.findSubstring(str, words);
        sort(res.begin(),res.end());
        assert(res == expect);
    }
    {
        std::string str = "barfoofoobarthefoobarman";
        vector<string> words = {"bar","foo","the"};
        vector<int> expect = {6,9,12};
        auto res = s.findSubstring(str, words);
        sort(res.begin(),res.end());
        assert(res == expect);
    }
    {
        std::string str = "barfoothefoobarman";
        vector<string> words = {"foo","bar"};
        auto res = s.findSubstring(str,words);
        vector<int> expect = {0,9};
        sort(res.begin(),res.end());
        assert(res == expect);
    }
    

}
