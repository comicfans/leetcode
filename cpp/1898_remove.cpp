#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> matchIndex;
        return recMatch(s,0,p,0,removable,0,matchIndex);
    }

    int recMatch(const string& s,
                 const int sBegin,
                 const string& p,
                 const int pBegin,
                 const vector<int>& removable,
                 const int removeBegin,
                 vector<int>& matchedIndex){

        if(pBegin == p.size()){
            // all matched

        }
        


    }
};
