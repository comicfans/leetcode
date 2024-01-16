#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> player(n);
        for(int i = 0;i < n; ++i){
            player[i] = i + 1;
        }

        int current = 0;
        for(int i = 0;i <n-1 ; ++i){
            auto leaveIdx = (current + k -1) % player.size();
            player.erase(player.begin() + leaveIdx);
            current = (leaveIdx== player.size()?0:leaveIdx);
        }

        
        return player.front();
    }
};

int main(){
    Solution s;
    {
        assert(s.findTheWinner(5,2) == 3);
    }
}
