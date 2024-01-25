#include <limits>
#include <array>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {

        array<vector<int>,3> cache;
        cache[0].resize(obstacles.size(),-1);
        cache[1].resize(obstacles.size(),-1);
        cache[2].resize(obstacles.size(),-1);
        int res = recFind(obstacles,1,0,0,cache);
        return res;
    }
    int recFind(const vector<int>& obs, int lane,int pos, int current, array<vector<int>,3>& cache){

        assert(pos != obs.size()-1);

        if(current >= best){
            return ;
        }

        if(obs[pos]== lane+1){
            return;
        }

        if(cache[lane][pos]!=-1){
            int total = current + cache[lane][pos];
            best = min(total, best);
            return;
        }

        auto nextBlock = find(obs.begin()+pos, obs.end(),lane+1);

        if(nextBlock == obs.end()){

            best = min(best,current);
            return;
        }

        int nextPos = nextBlock - obs.begin() - 1;
        assert(nextPos >= pos);

        recFind(obs, (lane+1)%3, nextPos, current+1, best);
        recFind(obs, (lane+2)%3, nextPos, current+1, best);

    }
};

int main(){
    Solution s;
    
    {
        vector<int> blocks = {0,0,0,3,0,1,3,2,3,2,0};

        s.minSideJumps(blocks) ;
    }
    {
        vector<int> blocks = {0,2,2,1,0,3,0,3,0,1,0};
        //   B     B
        // BB
        //_   _B_B_ _
        assert(s.minSideJumps(blocks) == 2);
    }
    {
        vector<int> blocks = {0,1,2,3,0};
        assert(s.minSideJumps(blocks) == 2);
    }
    {
        vector<int> blocks = {0,1,1,3,3,0};
        assert(s.minSideJumps(blocks) == 0);
    }
{
        vector<int> blocks = {0,2,1,0,3,0};
        assert(s.minSideJumps(blocks) == 2);
    }
{
        vector<int> blocks = {0,2,2,1,0,3,0,3,0,1,3,1,1,0,1,3,1,1,1,0,2,0,0,3,3,0,3,2,2,0,0,3,3,3,0,0,2,0,0,3,3,0,3,3,0,0,3,1,0,1,0,2,3,1,1,0,3,3,0,3,1,3,0,2,2,0,1,3,0,1,0,3,0,1,3,1,2,2,0,0,3,0,1,3,2,3,2,1,0,3,2,2,0,3,3,0,3,0,0,1,0};

        assert(s.minSideJumps(blocks) == 14);
    }
}
