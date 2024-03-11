#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {


        multimap<int,pair<int,int>> valueRow;
        for(int i = 0;i< matrix.size();++i){
            valueRow.insert({matrix[i][0],{i,0}});
        }

        //
        // 1,  5,  9
        // 10, 11, 13
        // 12, 13, 15
        //

        int value = -1;
        for(int i=0;i<k;++i){
            auto first = valueRow.begin();

            value = first->first;
            first->second.second ++;
            if(first->second.second == matrix[0].size()){
                valueRow.erase(first);
                continue;
            }

            int nextValue = matrix[first->second.first][first->second.second];
            pair<int,int> rowPos = first->second;

            valueRow.erase(first);
            valueRow.insert({nextValue, rowPos});
        }

        return value;
        
    }
};
