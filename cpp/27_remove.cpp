#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        auto pos = nums.begin();  
        auto currentEnd = nums.end();

        while(pos != currentEnd){

            auto toFind = find(pos, currentEnd, val);
            if(toFind == currentEnd){
                break;
            }

            nums.erase(toFind);
            --currentEnd ;
            pos = toFind;
        }


        return currentEnd - nums.begin();
    }
};


int main(){
    Solution s;
    {
        vector<int> nums = {3,2,2,3};
        auto res = s.removeElement(nums, 3);
    }
}
