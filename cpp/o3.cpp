#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {


        vector<vector<char>> reach;
        reach.resize(nums.size());

        set<int> newConn = {};
        for(int i = 0;i<nums.size();++i){
            reach[i].resize(nums.size(),' ');
            newConn.insert(i);
        }


        while(!newConn.empty()){

            for(auto to: newConn){
                for(int i = 0;i<nums.size();++i){
                    if(reach[to][i] != ' '){
                        continue;
                    }
                    if(i == to){
                        continue;
                    }

                    if(abs(nums[i] - nums[to]) > limit){
                        reach[to][i] = 'n';
                        reach[i][to] = 'n';
                        continue;
                    }

                    reach[to][i] = 'y';
                    reach[i][to] = 'y';
                    newConn.insert(i);
                }
            }
        }

        multiset<int> pick(nums.begin(),nums.end());
        map<int,set<int>> possible;

        for(int i = 0;i< nums.size();++i){
            set<int> newReach = {0};
            set<int> reached = {};
            while(!newReach.empty()){
                for(j = 0;j<nums.size();++j){
                    if((j == i) ||(reached.count(j))){
                        continue;
                    }
                }
            }
        }


        return nums;
    }
};

int main(){
    Solution s;
    {
        vector<int> input={1,5,3,9,8};
        s.lexicographicallySmallestArray(input,2);
    }
    {
        vector<int> input = {4,52,38,59,71,27,31,83,88,10};
14
    }
}
