#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<cassert>
#include <iostream>
using namespace std;

class Solution {
public:

    struct Info{
        int id;
        int hp;
        char dir;
    };

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {

        vector<Info> infos;
        for(int i =0;i<positions.size();++i){
            infos.push_back({i, healths[i], directions[i]});
        }

        std::sort(infos.begin(),infos.end(),
             [&positions](const Info &a, const Info &b){
                return positions[a.id] < positions[b.id];
        });


        int last_survived_pos = 0;
        for(int current_pos = 1; current_pos < infos.size();){


            if(last_survived_pos < 0) {
                last_survived_pos = current_pos;
                ++current_pos;
                continue;
            }

            auto& last_survived = infos[last_survived_pos];
            if(last_survived.hp == 0){
                --last_survived_pos;
                continue;
            }

            auto& current = infos[current_pos];

            if ((current.dir == last_survived.dir) | (current.dir == 'R')){
                last_survived_pos = current_pos;
                ++current_pos;
                continue;
            }


            if (current.hp < last_survived.hp ){
                last_survived.hp -= 1;
                current.hp = 0;
                ++current_pos;
                continue;
            }

            
            if(current.hp == last_survived.hp){
                current.hp = 0;
                last_survived.hp = 0;
                ++current_pos;
            }else{
                last_survived.hp = 0;
                current.hp -= 1;
            }

            --last_survived_pos;
        }

        sort(infos.begin(),infos.end(),[](const Info &a, const Info &b){
            return a.id < b.id;
        });

        std::vector<int> ret;
        for(const auto& info: infos){
            if(info.hp){
            ret.push_back(info.hp);
            }
        }

        return ret;
    
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
