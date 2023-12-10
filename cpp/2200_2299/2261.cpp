#include <vector>
#include <cassert>
#include <iostream>
#include <set>
#include <functional>
#include <map>
using namespace std;

struct Range{
    int begin;
    int end;
};

template<typename T> void hash_combine(size_t & seed, T const& v){
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
}

template<typename It> std::size_t hash_range(It first, It last){
    size_t seed = 0;
    for(; first != last; ++first){
        hash_combine(seed, *first);
    }
    return seed;
}

void print(vector<int>& nums, multimap<size_t, Range> ranges){
    for(auto &kv: ranges){

        for(int i = kv.second.begin; i < kv.second.end; ++i){
            cout<<nums[i]<<",";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        std::set<int> div_pos;
        for (int i=0; i< nums.size();++i){
            if(nums[i] % p == 0){
                div_pos.insert(i);
            }
        }
        //           2,3,3,2,2
        // div_pos = 0     3,4
        // 

        std::multimap<size_t, Range> unique_sets;
        for(int begin_idx = 0; begin_idx < nums.size() ; ++begin_idx){
            for(int end_idx = begin_idx + 1; end_idx <= nums.size(); ++ end_idx){
                // find how many div_pos in [begin_idx, end_idx)

                auto div_begin = div_pos.upper_bound(begin_idx-1);
                auto div_end = div_pos.lower_bound(end_idx);

                //auto div_begin_offset = distance(div_pos.begin(), div_begin);
                //auto div_end_offset = distance(div_pos.begin(), div_end);

                int div_number = std::distance(div_begin, div_end);

                assert (div_number >= 0);
                assert (div_number <= div_pos.size());

                if (div_number > k){
                    break;
                }

                Range this_range = {begin_idx, end_idx};

                auto this_hash = hash_range(nums.begin()+ begin_idx, nums.begin() + end_idx);

                auto existing_range = unique_sets.equal_range(this_hash);
               
                auto new_size = end_idx - begin_idx;

                bool equal_set = false;
                for (auto it = existing_range.first; it != existing_range.second; ++it){
                    auto old_size = it->second.end - it->second.begin;

                    if(old_size != new_size){
                        continue;
                    }

                    //size equal, check if range is equal
                    bool range_equal = std::equal(nums.begin() + begin_idx, nums.begin() + end_idx,
                                                  nums.begin() + it->second.begin);

                    if (range_equal){
                        equal_set = true;
                        break;
                    }
                }

                if(!equal_set){
                    unique_sets.insert({this_hash, this_range});
                }
            }
        }

        //print(nums, unique_sets);
        return unique_sets.size();
    }
};

int main(){
    Solution s;
    std::vector<int> nums = {2,3,3,2,2};
    cout<<s.countDistinct(nums, 2,2) <<endl;

    nums = {1,2,3,4};
    cout<<s.countDistinct(nums, 4,1) <<endl;
}


