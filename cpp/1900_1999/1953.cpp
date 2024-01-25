#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {


        //sort(milestones.begin(),milestones.end(),[](auto lhs, auto rhs){
        sort(milestones.begin(),milestones.end());

        long long ret = 0;
        
        for(int begin = 0;begin < milestones.size();++begin){

            if(begin == milestones.size()-1){
                ++ret;
                break;
            }

            ret+= milestones[begin] * 2;
            milestones.back() -= milestones[begin];

            auto afterConsume = milestones.back();

            if(afterConsume == 0){
                milestones.pop_back();
                continue;
            }

            auto insPos = upper_bound(milestones.begin()+ begin + 1, milestones.end()-1, milestones.back());
            milestones.pop_back();
            milestones.insert(insPos, afterConsume);
        }

       

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<int> milestones = {9,3,6,8,2,1};
        assert(s.numberOfWeeks(milestones) == 29);
    }
    {
        vector<int> milestones = {1,10,7,1,7,2,10,10,355359359};

        assert(s.numberOfWeeks(milestones) == 97);
    }
    {
        vector<int> milestones = {1,2,3};

        assert(s.numberOfWeeks(milestones) == 6);
    }
    {
        vector<int> milestones = {1,2,5};

        assert(s.numberOfWeeks(milestones) == 7);
    }
    
}
