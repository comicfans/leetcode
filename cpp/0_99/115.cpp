#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {

        if(s.size() < t.size()){
            return 0;
        }

        string search = t;
        sort(search.begin(),search.end());
        search.resize(unique(search.begin(),search.end())-search.begin());

        string striped;
        for(int i = 0;i<s.size(); ++i){
            if(binary_search(search.begin(),search.end(),s[i])){
                striped.push_back(s[i]);
            }
        }


        map<pair<int,int>,int> cache;
        return recFind(striped,0,t,0,cache);
    }

    int recFind(const string& big, int is, const string& small, int it, map<pair<int,int>, int>& cache){
        if(it == small.size()){
            return 1;
        }

        auto pos = cache.find({is,it});
        if(pos!=cache.end()){
            return pos->second;
        }

        int ret = 0;
        int maxTry = min((int)big.size() - ((int)small.size()-it), (int)big.size()-1);
        for(int tryPos = is;tryPos <= maxTry;++tryPos){

            if(big[tryPos] == small[it]){
                int sub = recFind(big,tryPos+1,small,it+1,cache);
                ret+=sub;
                continue;
            }
        }

        cache[{is,it}] = ret;

        return ret;
    }
};

int main(){
    Solution so;
    {
        string s = "rabbbit", t = "rabbit";
        assert(so.numDistinct(s,t)==3);
    }
    {
        string s="babgbag", t = "bag";
        assert(so.numDistinct(s,t)==5);
    }
    {
    }
}
