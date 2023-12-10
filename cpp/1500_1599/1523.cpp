#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int countOdds(int low, int high) {

        int lowRound = low/2+1;

        int highRound = (high+1)/2 - 1;

        return (highRound - lowRound)/2+1;
        
    }
};
