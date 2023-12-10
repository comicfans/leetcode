#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int maxInterval = 1;

        int prev = -1;

        int firstPeople = -1;
        int lastPeople = -1;
        
        for(int i =0;i<seats.size();++i){
            if(seats[i]){

                if(firstPeople == -1){
                    firstPeople = i;
                }

                int thisInterval = i - prev -1;
                maxInterval = max(maxInterval, thisInterval);
                prev = i;
                lastPeople = i;
                continue;
            }
            continue;
        }

        return max<int>(max((maxInterval - 1)/ 2 + 1, firstPeople), seats.size() - 1-lastPeople);
        
    }
};

int main(){
    Solution s;
    {
        vector<int> seats = {1,0,0,1};
        assert(s.maxDistToClosest(seats) == 1);
    }
    {
        vector<int> seats = {1,0,0,0};
        assert(s.maxDistToClosest(seats) == 3);
    }
    {
        vector<int> seats = {1,0,0,0,1,0,1};
        assert(s.maxDistToClosest(seats) == 2);
    }
{
        vector<int> seats = {0,1};
        assert(s.maxDistToClosest(seats) == 1);
    }

}
