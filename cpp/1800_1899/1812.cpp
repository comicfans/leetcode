#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool squareIsWhite(string coordinates) {

        return (coordinates[0]+coordinates[1] - 'a' - '1') % 2 ;
    }
};
