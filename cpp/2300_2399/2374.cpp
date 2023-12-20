#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int edgeScore(vector<int>& edges) {

        vector<long long> scores(edges.size());

        for(int i = 0; i< edges.size();++i){
            scores[edges[i]] += i;
        }

        return max_element(scores.begin(),scores.end()) - scores.begin();

        
    }
};
