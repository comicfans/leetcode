#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<pair<int,int>> locs(locations.size());

        for(int i = 0;i<locations.size();++i){
            locs[i] = {locations[i], i};
        }

        sort(locs.begin(),locs.end());

        int startMapped = -1;
        int endMapped = -1;

        for(int i =0;i<locs.size();++i){
            if(locs[i].second == start){
                startMapped = i;

            }
            if(locs[i].second == finish){
                endMapped = i;

            }

            if(startMapped!=-1 && endMapped != -1){
                break;
            }
        }

        int from = min(startMapped, endMapped);
        int to = max(startMapped, endMapped);
        
        
    }
};
