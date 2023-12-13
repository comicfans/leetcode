#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class MagicDictionary {
public:
    MagicDictionary() {
        
    }
    
    vector<string> sorted;

    void buildDict(vector<string> dictionary) {

        swap(sorted, dictionary);

        sort(sorted.begin(),sorted.end(),[](auto& lhs, auto& rhs){
            return lhs.size() < rhs.size();
        });
        
    }
    
    bool search(string searchWord) {

        auto eq = equal_range(sorted.begin(),sorted.end(),searchWord,[](auto& lhs, auto& rhs){
            return lhs.size() < rhs.size();
        });

        for(auto it = eq.first; it != eq.second;++it){

            int dis = 0;

            for(int i = 0;i< searchWord.size();++i){
                if(searchWord[i] == (*it)[i]){
                    continue;
                }
                ++dis;
                if(dis > 1){
                    break;
                }
            }
            if(dis == 1){
                return true;
            }

        }

        return false;
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
