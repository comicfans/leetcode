#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        map<string, int> number;

        for(int begin = 0; begin <= (int)s.size()-10; ++begin){

            number[s.substr(begin,10)]++;
        }

        vector<string> ret;

        for(const auto& keyValue:number){
            if(keyValue.second > 1){
                ret.push_back(keyValue.first);
            }
        }
        return ret;
        

    }
};

int main(){
    Solution s;
    {

    }
}
