#include <limits>
#include <set>
#include <cassert>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {

        std::sort(processorTime.begin(),processorTime.end());

        std::sort(tasks.begin(),tasks.end());
        //put long task to earlier processor 

        int currentMax = 0;

        for(int i=0; i< processorTime.size();++i){

            currentMax = max(currentMax, processorTime[i] +  tasks[(processorTime.size() - i) * 4-1]);

        }
        
        return currentMax;

    }

    
};

int main(){

    {
    std::vector<int> pt1 = {8,10};
    std::vector<int> tk1= {2,2,3,1,8,7,4,5};

    Solution s;
    int res = s.minProcessingTime(pt1, tk1);

    assert(res == 16);
}

{
    std::vector<int> pt1 = {10,20};
    std::vector<int> tk1= {2,3,1,2,5,8,4,3};

    Solution s;
    int res = s.minProcessingTime(pt1, tk1);

    assert(res == 23);
}
{
    std::vector<int> pt1 = {143,228,349,231,392};
    std::vector<int> tk1= {102,365,363,211,38,96,98,79,365,289,252,201,259,346,21,68,128,56,167,183};

    Solution s;
    int res = s.minProcessingTime(pt1, tk1);

    assert(res == 517);
}

}
