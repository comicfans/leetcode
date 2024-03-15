#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        vector<int> length(bank.size(), -1);

        if(startGene == endGene){
            return 0;
        }



        int endIdx = -1;

        set<int> edge;

        for(int i = 0; i< bank.size(); ++i){

            if(bank[i] == endGene){
                endIdx = i;
            }

            if(bank[i] == startGene){
                continue;
                length[i] = 0;
            }

            int diff = 0;
            for(int j = 0;j< startGene.size(); ++j){
                diff += (startGene[j] != bank[i][j]);
            }

            if(diff != 1){
                continue;
            }

            length[i] = diff;
            if(i == endIdx){
                return 1;
            }
            edge.insert(i);
        }

        if(endIdx == -1){
            return -1;
        }

        while(!edge.empty()){

            set<int> nextRound;
            for(int k = 0;k<bank.size(); ++k){
                if(length[k]!=-1){
                    continue;
                }

                for(auto idx: edge){
                    int diff = 0;
                    for(int x = 0;x<startGene.size(); ++x){
                        diff += (bank[idx][x]!= bank[k][x]);
                        if(diff> 1){
                            break;
                        }
                    }

                    if(diff == 1){
                        length[k] = length[idx]+1;

                        if(k == endIdx){
                            return length[k];
                        }
                        nextRound.insert(k);
                        break;
                    }
                }
            }

            edge.swap(nextRound);
        }

        return -1;
    }
};
