#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {

        vector<char> states;
        //croak

        int number = 0;
        for(auto c: croakOfFrogs){

            int currentIdx = -1;
            switch(c){
                case 'c':{
                    currentIdx = 0;
                    break;
                };
                case 'r':{
                    currentIdx = 1;
                    break;
                };
                case 'o':{
                    currentIdx = 2;
                    break;
                };
                case 'a':{
                    currentIdx = 3;
                    break;
                }
                case 'k':{
                    currentIdx = 4;
                    break;
                }
                default:{
                    return -1;
                }
            }

            if(states.empty() && currentIdx != 0){
                return -1;
            }


            if(currentIdx == 0){
                states.push_back(currentIdx);
                number = max<int>(number, states.size());
                continue;
            }
            

            //reverse search any state which can be concate with this

            bool find = false;
            for(int search = states.size()-1;search>=0;--search){

                if(states[search]==currentIdx -1){
                    states[search]++;
                    find = true;

                    if(currentIdx == 4){
                        states.erase(states.begin()+search);
                    }

                    break;
                }
            }

            if(!find){
                return -1;
            }

        }

        if(states.empty()){
            return number;
        }
        
        return -1;
    }
};
