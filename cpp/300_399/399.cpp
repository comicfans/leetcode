#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> vars;

        map<string,map<string, double>> fromTo;
        for(int i = 0;i< equations.size();++i){
            const auto& eq =  equations [i];
            for(const auto& var: eq){
                vars.insert(var);
            }
            fromTo[eq[0]].insert({eq[1],values[i]});
            fromTo[eq[1]].insert({eq[0],1.0/values[i]});
        }


        vector<double> ret(queries.size());
        for(int i = 0;i< queries.size();++i){

            const auto& eq = queries[i];
            string top = eq[0];
            string bottom = eq[1];

            if(vars.count(top) == 0 || vars.count(bottom) == 0){
                ret[i] = -1;
                continue;
            }

            if(top == bottom){
                ret[i]= 1;
                continue;
            }

            set<string> path = {top};
            double res = rec(fromTo,top, bottom, path, 1.0);
            ret[i] = res;
        }
        return ret;
    }

    double rec(const map<string,map<string, double>>& fromTo,
               const string& from,
               const string& target,
               set<string>& path,
               double currentValue){
        if(from == target){
            return currentValue;
        }

        auto possible = fromTo.at(from);

        for(const auto& kv: possible){
            if(path.count(kv.first)){
                continue;
            }

            auto pos = path.insert(kv.first);
            double sub = rec(fromTo, kv.first,target,path, currentValue * kv.second);
            if(sub != -1){
                return sub;
            }
            path.erase(pos.first);
        }

        return -1;
    }
};

