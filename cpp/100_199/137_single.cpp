class Solution {
public:
    int singleNumber(vector<int>& nums) {

        map<int,int> n;
        for(auto v: nums){
            n[v]++;
           
        }
        for(const auto& kv: n){
            if(kv.second==1){
                return kv.first;
            }
        }
return 0;
        
    }
};
