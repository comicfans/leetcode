#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string left;

        for(auto v: word1){
            left+=v;
        }

        string right;
        for(auto v: word2){
            right+=v;
        }

        return left == right;
        
    }
};
