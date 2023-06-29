#include<vector>
#include<set>
#include<map>
#include<cassert>
#include <iostream>
using namespace std;

class Solution {
public:

    struct Info{
        int id;
        int health;
        char dir;
    };

    struct Pack{
        char dir;
        vector<pair<int,int>> id_health;
    };
    

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {


        std::map<int, Info> pos_ordered;

        for(int id = 0; id < healths.size(); ++id){
            pos_ordered[positions[id]] = Info{ id, healths[id], directions[id]};
        }

        // regroup
        vector<Pack> regroup;
        for(const auto& kv: pos_ordered){
            if (regroup.empty()){
                    regroup.push_back(Pack{
                        kv.second.dir,
                        vector<pair<int,int>>{{kv.second.id, kv.second.health}}
                    });
                    continue;
            }

            //has left group, checking if we should merge it, or collide it

            auto last_pos = regroup.end();
            --last_pos;

            if(last_pos->dir == kv.second.dir){
                //do merge
                last_pos->id_health.push_back({kv.second.id, kv.second.health});
                continue;
            }

            if(kv.second.dir== 'R'){
                //create new group
                regroup.push_back(Pack{
                        kv.second.dir,
                        vector<pair<int,int>>{{kv.second.id, kv.second.health}}
                });
                continue;
            }

            //do collide until no left no more ,or right no more

            
            int right_hp = kv.second.health;
            do{
                auto &to_collide = last_pos->id_health.back();

                int collide_health = to_collide.second;

                if(collide_health > right_hp){
                    to_collide.second -= 1;
                    assert(to_collide.second != 0);
                    right_hp = 0;
                    break;
                }

                if(collide_health == right_hp){
                    right_hp = 0;
                }else{
                    right_hp -= 1;
                }

                //old collide remove
                last_pos->id_health.pop_back();
                if(last_pos->id_health.empty()){
                    regroup.pop_back();
                    break;
                }
            }while(right_hp > 0);

            if(right_hp > 0){
                regroup.push_back(Pack{
                    kv.second.dir,
                    vector<pair<int,int>>{{kv.second.id, right_hp}}
                });
            }
        }

        // now reorder by id
        std::map<int, int> id_health;

        for(const auto& v: regroup){

            for(const auto &left: v.id_health){
                id_health[left.first] = left.second;
            }
        }

        std::vector<int> health;
        for(auto &kv: id_health){
            health.push_back(kv.second);
        }

        return health;
    }
};

int main(){
    Solution s;
    {
    vector<int> positions = {5,4,3,2,1};
    vector<int> healths = {2,17,9,15,10};
    string directions = "RRRRR";

    auto ret = s.survivedRobotsHealths(positions, healths, directions);

    for(auto &r: ret){
        std::cout << r <<",";
    }
    cout<<endl;
    }

    {
    vector<int> positions = {3,5,2,6};
    vector<int> healths = {10,10,15,12};
    string directions = "RLRL";

    auto ret = s.survivedRobotsHealths(positions, healths, directions);

    for(auto &r: ret){
        std::cout << r <<",";
    }
    cout<<endl;
    }

    {
    vector<int> positions = {1,2,5,6};
    vector<int> healths = {10,10,11,11};
    string directions = "RLRL";

    auto ret = s.survivedRobotsHealths(positions, healths, directions);

    for(auto &r: ret){
        std::cout << r <<",";
    }
    cout<<endl;
    }


    {
    vector<int> positions = {11,44,16};
    vector<int> healths = {1,20,17};
    string directions = "RLR";

    auto ret = s.survivedRobotsHealths(positions, healths, directions);

    for(auto &r: ret){
        std::cout << r <<",";
    }
    cout<<endl;
    }

    return 0;
}
