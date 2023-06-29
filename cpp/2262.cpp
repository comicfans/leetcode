#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdint>
#include <map>
using namespace std;

not passed

class Solution {
public:


    long long appealSum(string s) {

        std::map<char, int> last_appear_pos;
        std::map<char, std::vector<int>> no_dup_length;

        for(int i=0;i<s.size();++i){
            auto this_char = s[i];

            if(!last_appear_pos.count(this_char)){
                last_appear_pos[this_char] = -1;
            }

            auto this_seg = i - last_appear_pos[this_char]-1;
            no_dup_length[this_char].push_back(this_seg);
            last_appear_pos[this_char] = i;
        }

        //close all
        for(auto& kv: no_dup_length){
            auto last_seg = s.size() - last_appear_pos[kv.first]-1;
            no_dup_length[kv.first].push_back(last_seg);
        }

        long long ret = 0;
        for(const auto& kv: no_dup_length){

            // 0, 3, 0 should gives 
            // (0+1) * (3+1) + (3+1) * (0+1) + 
            // (0+1) * (0+1) = 9

            const auto& no_dup = kv.second;
            for(int i=1;i<no_dup.size(); ++i){
                for(int pick_start = 0; pick_start +i < no_dup.size();++pick_start){
                    auto this_contrib = (no_dup[pick_start]+1) * (no_dup[pick_start+i]+1);
                    ret += this_contrib;
                }
            }
        }

        
        return ret;
    }


    long long appealSumSlow(string s) {
    long long ret = 0;

    std::set<std::pair<int,int>> begin_end;
    for(int begin_idx = 0;begin_idx< s.size();++begin_idx){
        for(int end_idx = begin_idx+1; end_idx < s.size()+1;++end_idx){
            begin_end.insert({begin_idx,end_idx});
        }
    }

    std::set<char> searched;

    for(int i=0; i < s.size();++i){
        char to_find = s[i];
        if(searched.count(to_find)){
            continue;
        }


        for(auto it = begin_end.begin(); it!= begin_end.end(); ++it){
            auto in_substr = std::find(s.begin()+it->first,
                                       s.begin()+it->second,
                                       to_find);

            if(in_substr == s.begin()+it->second){
                continue;
            }

            searched.insert(to_find);
            ++ ret;

            
        }
    }
    return ret;

    }
};

long long slow (const std::string& str){

    long long ret = 0;
    cout<<str<<":begin--"<<endl;

    std::set<std::pair<int,int>> begin_end;
    for(int begin_idx = 0;begin_idx< str.size();++begin_idx){
        for(int end_idx = begin_idx+1; end_idx < str.size()+1;++end_idx){
            begin_end.insert({begin_idx,end_idx});
        }
    }

    std::map<char,
             std::map<std::pair<int,int>,
                      std::string>
            > contrib;

    for(int i=0; i < str.size();++i){
        char to_find = str[i];
        if(contrib.count(to_find)){
            continue;
        }


        for(auto it = begin_end.begin(); it!= begin_end.end(); ++it){
            auto in_substr = std::find(str.begin()+it->first,
                                       str.begin()+it->second,
                                       to_find);

            if(in_substr == str.begin()+it->second){
                continue;
            }

            std::pair<int,int> pos_key{it->first,
                                       it->second};

            contrib[to_find][pos_key] = str.substr(it->first,
                                                        it->second-it->first);
        }
    }

    for(const auto& kv: contrib){

        cout<<kv.first<<":";

        for(const auto& pos_str: kv.second){
            cout<<"("<<pos_str.first.first<<"~"<<pos_str.first.second<<")"<<pos_str.second<<",";
        }

        cout<<endl;
    }
    cout<<"---end"<<endl;
    return 0;
}

int main(){



    //slow("abb");
    //slow("abba");
    //slow("abbb");
    //slow("abbc");

    Solution s;
    cout<<s.appealSum("abbca")<<endl;
    cout<<s.appealSum("code")<<endl;
       
}
