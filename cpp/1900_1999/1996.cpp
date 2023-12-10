#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {

        sort(properties.begin(),properties.end());

        for(int i = 0;i< properties.size();++i){
            properties[i].push_back(i);
        }


        auto defenseSort = properties;
        sort(defenseSort.begin(),defenseSort.end(),[](auto& lhs,auto& rhs){
            return lhs[1]<rhs[1];
        });

        int ret=0;
        for(int i =0; i < properties.size();++i){

            auto ele= properties[i];
            auto attackLower = lower_bound(properties.begin()+i+1,properties.end(),vector<int>{ele[0]+1,0});

            if(attackLower == properties.end()){
                continue;
            }

            int attackHigherIdx = attackLower- properties.begin();

            auto defenseLower = lower_bound(defenseSort.begin(),defenseSort.end(),vector<int>{0,ele[1]+1}, [](auto& lhs, auto& rhs){
                return lhs[1] < rhs[1];
            });


            if(defenseLower == defenseSort.end()){
                continue;
            }

            for(auto it = defenseLower; it!= defenseSort.end(); ++it){
                if((*it)[2] >= attackHigherIdx){
                    ++ret;
                    break;
                }
            }

        }
        
        return ret;
        
    }
};

#include "parse.h"

int main(){
    Solution s;
    {
        vector<vector<int>> input = {{1,1},{2,1},{2,2},{1,2}};
        assert(s.numberOfWeakCharacters(input) == 1);
    }
    {
        vector<vector<int>> input = {{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}};
        assert(s.numberOfWeakCharacters(input) == 6);
    }
    {
        vector<vector<int>> input = {{5,5},{6,3},{3,6}};
        assert(s.numberOfWeakCharacters(input) == 0);
    }
    {
        auto input = pvvi("1996_case.txt");
        s.numberOfWeakCharacters(input);
    }
        
}
