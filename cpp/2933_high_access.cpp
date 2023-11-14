#include <string>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    static int parseTime(const std::string& t){

        stringstream hh_str(t.substr(0,2));
        int hh ;
        hh_str >> hh;

        stringstream mm_str(t.substr(2));
        int mm;
        mm_str >> mm;

        return hh * 60 + mm;

        return 1;
    }

    bool isHigh(const vector<int>& times){

        int win_begin = 0;
        
        for(int i = 0;i < times.size();++i){

            auto end_time = times[i]+59;
            auto end_pos = upper_bound(times.begin()+i,times.end(), end_time);


            auto end_idx = end_pos - times.begin();

            auto how_many = end_idx - i ;

            if(end_idx != times.size() && (times[end_idx] == end_time)){
                ++how_many;
            }

            

            if (how_many >= 3){
                return true;
            }
        }

        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

        map<string,vector<int>> all;


        for(const auto& v: access_times ){
                all[v[0]].push_back(parseTime(v[1]));
        }

        vector<string> ret;

        for(auto& kv: all){
            sort(kv.second.begin(),kv.second.end());
            if(isHigh(kv.second)){
                ret.push_back(kv.first);
            }
        }

        return ret;
        
    }
};

int main(int, char**){

    Solution s;


    std::vector<int> input0 = {0};
    assert(!s.isHigh(input0));

    std::vector<int> input1 = {0,1,2,60};
    assert(s.isHigh(input1));


    std::vector<int> input2 = {0,1,60};
    assert(!s.isHigh(input2));

    std::vector<int> input3 = {0,1,59};
    assert(s.isHigh(input3));

    std::vector<int> input4 = {0,1,2,59};
    assert(s.isHigh(input4));

    {

        vector<vector<string>> access_times = {{"aywtqh","0523"},{"aywtqh","0530"},{"aywtqh","0419"}};
        auto ret = s.findHighAccessEmployees(access_times);
        assert(ret.empty());
    }

    {
        vector<vector<string>> access_times = {{"a","0549"},{"b","0457"},{"a","0532"},{"a","0621"},{"b","0540"}};

        auto ret = s.findHighAccessEmployees(access_times);

        assert(ret == vector<string>{"a"});

    }
    {
        vector<vector<string>> access_times = {{"akuhmu","0454"},
                                               {"aywtqh","0523"},{"aywtqh","0530"},{"aywtqh","0419"},
                                               {"akuhmu","0518"},
                                               {"ihhkc","0439"},{"ihhkc","0508"},{"akuhmu","0529"}};

        auto ret = s.findHighAccessEmployees(access_times);

        assert(ret == vector<string>{"akuhmu"});

    }
}
