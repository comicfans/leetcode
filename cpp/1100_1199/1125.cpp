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

        map<int, set<int>> skill_people;

        vector<vector<int>> int_people;

        for(auto v_idx = 0;v_idx < people.size();++v_idx){
            const auto& v= people[v_idx];
            int_people.push_back({});
            int_people.back().reserve(v.size());
            for(const auto s: v){

                int idx = lower_bound(req_skills.begin(),req_skills.end(), s) - req_skills.begin();

                int_people.back().push_back(idx);

                skill_people[idx].insert(v_idx);

                sort(int_people.back().begin(),int_people.back().end());
            }
        }

        set<int> existing;

        vector<int> best;
        for(int i = 0;i<int_people.size();++i){
            best.push_back(i);
        }

        set<int> req;
        for(int i=0;i<req_skills.size();++i){
            req.insert(i);
        }

        //first pick out must pick people
        for(auto s_p = skill_people.begin();s_p!=skill_people.end();){
            if(s_p->second.size() == 1){
                existing.insert(*s_p->second.begin());
                auto erase = s_p;
                req.erase(s_p->first);
                ++s_p;
                skill_people.erase(erase);
            }else{
                ++s_p;

            }
        }

        //remove skill of existing people
        for(auto p : existing){
            for(auto sk: int_people[p]){
                req.erase(sk);
            }
        }

        recFind(req, int_people, existing,best,0);

        return best;
    }

    void recFind(set<int>& req, vector<vector<int>>& people, set<int>& existing,vector<int>& best, int thisBegin){
        if(req.empty()){
            if(existing.size() < best.size()){
                best = vector<int>(existing.begin(),existing.end());
            }
            return;
        }

        if(existing.size()>= best.size()){
            return;
        }

        //try to take one

        for(int tryBegin = thisBegin; tryBegin < people.size(); ++ tryBegin){

            if(existing.count(tryBegin)){
                continue;
            }

            set<int> more;
            set_intersection(people[tryBegin].begin(),people[tryBegin].end(),req.begin(),req.end(),inserter(more,more.end()));

            

            if(more.empty()){
                continue;
            }

            for(auto v:more){
                req.erase(v);
            }

            auto insertPos = existing.insert(tryBegin);
            recFind(req,people,existing,best,tryBegin + 1);

            existing.erase(insertPos.first);
            for(auto v:more){
                req.insert(v);
            }

        }
    }
};

#include "parse.h"
int main(){
    Solution s;
    {

        vector<string> req_skills ={"java","nodejs","reactjs"};
        vector<vector<string>>people = {{"java"},{"nodejs"},{"nodejs","reactjs"}};

        auto res = s.smallestSufficientTeam(req_skills,people);
        vector<int> expect = {0,2};
        assert(res == expect);

    }
    {
        vector<string> req_skills = {"algorithms","math","java","reactjs","csharp","aws"}; 
        vector<vector<string>> people = {{"algorithms","math","java"},{"algorithms","math","reactjs"},{"java","csharp","aws"},{"reactjs","csharp"},{"csharp","math"},{"aws","java"}};
        auto res = s.smallestSufficientTeam(req_skills, people);
        vector<int> expect = {1,2};
        assert(res == expect);
    }
    {
        auto req_skills = pvs("1125_case.txt",0);
        auto people = pvvs("1125_case.txt",1);
        s.smallestSufficientTeam(req_skills,people);
    }
}
