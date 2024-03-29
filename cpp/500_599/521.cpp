#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findLUSlength(string a, string b) {
        string& shortOne = a.size() < b.size()? a:b;
        string& longOne = a.size() < b.size()? b: a;

        if(longOne.size() > shortOne.size()){
            return longOne.size();
        }
        if(shortOne == longOne ){
            return -1;
        }
        return shortOne.size();
    }
}   
