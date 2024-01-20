#include <vector>
#include <array>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> all;


        for(int i = 0;i< m; ++i){
            all.push_back(vector<int>(n));
        }

        all[m-1][n-1] = 1;

        return recWalk(all,0,0);
        
    }

    int recWalk(vector<vector<int>>& all,int y,int x){
        if(y >= all.size() || x >= all[y].size()){
            return 0;
        }

        if(all[y][x]!=0){
            return all[y][x];
        }

        //walk right
        int walkRight = recWalk(all, y,x+1);
        int walkDown = recWalk(all, y+1, x);

        int total = walkRight+walkDown;

        all[y][x] = total;
        return total;
    }
};

int main(){
    Solution s;
    {
    assert(s.uniquePaths(3,7) == 28);
    }
}
