#include <cmath>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int numberOfWays(string corridor) {

        vector<int> distance;

        int seatNumber = 0;
        int prevSeatEnd = -1;

        int oneReach = false;
        for(int i =0;i< corridor.size();++i){
            if(corridor[i] != 'S'){
                continue;
            }
                ++seatNumber;

                if(seatNumber == 2){
                    oneReach  = true;
                    prevSeatEnd = i;
                    seatNumber = 0;
                }else if (seatNumber==1){


                    int dis = i  - prevSeatEnd;
                    if(dis != 0){
                        if(oneReach){
                            distance.push_back(dis);
                        }
                    }
                }else{
                    assert(false);
                }
        }

        //mul 

        if(!oneReach){
            return 0;
        }

        if(seatNumber != 0){
            return 0;
        }

        int64_t res = 1;

        for(auto v: distance){

            res*= v;
            res = res % ((int64_t)pow(10,9)+7);

        }

        return res;
        
    }
};

int main(){
    Solution s;
    {
        assert(s.numberOfWays("SSPPSPS") == 3);
        assert(s.numberOfWays("PPSPSP") == 1);
        assert(s.numberOfWays("S") == 0);
    }
    {

        string str = "SPPPPPPPSPPPSPSSSPPPPPPPPPPPPPPPPPSPPPPPPPPPPPPPPPPSPPPPPSPSPPPPPPSPSPPSPSPPPSPSPPSSPPPPPSPPSSPP";
        assert(s.numberOfWays(str) == 0);
    }
}
