#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



        map<int,set<int>> fromToEdges;


        for(const auto& fromTo : prerequisites ){
            fromToEdges[fromTo[1]].insert(fromTo[0]);
        }

        set<int> ok;

        for(auto fromTos: fromToEdges){

            if(ok.count(fromTos.first)){
                continue;
            }

            set<int> walked;

            bool hasCircle = recFind(fromToEdges,walked,fromTos.first,ok);

            if(hasCircle){
                return false;
            }

        }


        return true;
        
    }

    bool recFind(const map<int,set<int>>& fromToEdges, set<int>& walked, int from,set<int>& ok){
        assert(!walked.count(from));


        auto pos = fromToEdges.find(from);
        if(pos == fromToEdges.end()){
            return false;
        }
        auto insPos = walked.insert(from);
        assert(insPos.second);

        for(auto to : pos->second){

            if(ok.count(to)){
                continue;
            }

            if(walked.count(to)){
                return true;
            }
            if(recFind(fromToEdges, walked, to, ok)){
                return true;
            }
        }
        //all sub ok

        ok.insert(from);

        walked.erase(insPos.first);

        return false;
    }
};

int main(){
    Solution s;
    {
        vector<vector<int>> input={{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
        assert(s.canFinish(7,input));
    }
    {
        vector<vector<int>> input= {{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
        assert(s.canFinish(8,input));
    }
    {
        vector<vector<int>> input = {{1,4},{2,4},{3,1},{3,2}};
        assert(s.canFinish(5,input));
    }
    {
        vector<vector<int>> input = {{1,0}};
        assert(s.canFinish(2,input));
    }
    {
        vector<vector<int>> input = {{1,0},{0,1}};
        assert(!s.canFinish(2,input));
    }
}
