#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {

        sort(chars.begin(),chars.end());

        int ret = 0;
        for(auto str:words){
            sort(str.begin(),str.end());
            string intersect;
            set_intersection(str.begin(),str.end(),chars.begin(),chars.end(),back_inserter(intersect));

            if(intersect == str){
                ret+= intersect.size();
            }

        }

        return ret;

        
    }
};

int main(){
    Solution s;
    {
        vector<string> input = {"cat","bt","hat","tree"};
        assert(s.countCharacters(input,"atach"));
    }
}
