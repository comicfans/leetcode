#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {

        vector<int> ret;
        for(int i = 0;i<mountain.size()-1;++i){

            if(mountain[i]> mountain[i-1] && mountain[i] < mountain[i+1]){
                ret.push_back(i);
            }
        }
        return ret;
    }
};



int main(){
    Solution s;
    {

        //vector<int>
        //vector<vector<int>>
        //assert(s.());
    }
    {
        //vector<int>
        //vector<vector<int>>
        //assert(s.());
    }
}

