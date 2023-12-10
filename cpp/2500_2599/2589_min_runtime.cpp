#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        map<int,int> possible;

        map<int, int> taskRuntime;

        for(int i =0;i<tasks.size();++i){
            const auto &v = tasks[i];
            taskRuntime[i] = v[2];

            for(int idx = v[0];idx<=v[1];++idx){
                ++possible[idx];
            }
        }

        //always choose most one of runtime
        int totalRuntime = 0;

        while(!taskRuntime.empty()){

            assert(!possible.empty());

            auto mostOverlapPos = possible.begin();
            int mostOverlapNumber = possible.begin()->second;

            for(auto pos = possible.begin(); pos != possible.end(); ++pos){
                if(pos->second > mostOverlapNumber){
                    mostOverlapNumber = pos->second;
                    mostOverlapPos= pos;
                }
            }

            int thisChooseTime = mostOverlapPos->first;
            ++totalRuntime;
            possible.erase(mostOverlapPos);
            //sub it from all tasks
            for(auto it=taskRuntime.begin();it!=taskRuntime.end();){
                assert(it->second != 0);

                auto tid = it->first;
                if((tasks[tid][1] - thisChooseTime) * (thisChooseTime - tasks[tid][0]) < 0){
                    ++it;
                    continue;
                }

                --it->second;
                if(it->second > 0){
                    ++it;
                    continue;
                }

                auto erase = it;
                ++it;
                taskRuntime.erase(erase);
            }
        }

        return totalRuntime;
    }
};

int main(){

    Solution s;
    {
        vector<vector<int>> tasks= {{2,3,1},{4,5,1},{1,5,2}};
        assert(s.findMinimumTime(tasks) == 2);
    }


}
