#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {

        sort(req_skills.begin(),req_skills.end());

        vector<vector<int>> int_people;

        for(const auto& v: people){
            int_people.push_back({});
            int_people.back().reserve(v.size());
            for(const auto s: v){

                int idx = lower_bound(req_skills.begin(),req_skills.end(), s) - req_skills.begin();

                int_people.back().push_back(idx);

                sort(int_people.back().begin(),int_people.back().end());
            }
        }

        vector<int> existing;

        vector<int> best;
        for(int i = 0;i<int_people.size();++i){
            best.push_back(i);
        }

        set<int> req;
        for(int i=0;i<req_skills.size();++i){
            req.insert(i);
        }

        recFind(req, int_people, existing,best);

        return best;
    }

    void recFind(set<int>& req, vector<vector<int>>& people, vector<int>& existing,vector<int>& best){
        if(req.empty()){
            if(existing.size() < best.size()){
                best = existing;
            }
            return;
        }

        if(existing.size()>= best.size()){
            return;
        }

        //try to take one

        for(int tryBegin = existing.empty()?0:existing.back();tryBegin < people.size(); ++ tryBegin){

            set<int> more;
            set_intersection(people[tryBegin].begin(),people[tryBegin].end(),req.begin(),req.end(),inserter(more,more.end()));

            

            if(more.empty()){
                continue;
            }

            for(auto v:more){
                req.erase(v);
            }

            existing.push_back(tryBegin);
            recFind(req,people,existing,best);

            existing.pop_back();
            for(auto v:more){
                req.insert(v);
            }

        }
    }
};

int main(){
    Solution s;
    {

        vector<string> req_skills ={"java","nodejs","reactjs"};
        vector<vector<string>>people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};

        auto res = s.smallestSufficientTeam(req_skills,people);
        vector<int> expect = {0,2};
        assert(res == expect);

    }
}
