#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const string& lhs, const string& rhs)
{

            int lp = lhs.size()-1,rp = rhs.size()-1;

            while(lp>=0 && rp >=0){

                if(lhs[lp] < rhs[rp]){
                    return true;
                }

                if(lhs[lp] > rhs[rp]){
                    return false;
                }
                --lp;
        --rp;

            }

            //all equal
            if(lp == 0 && rp == 0){
                return true;
            }

            auto lfirst = lhs+rhs;
            auto rfirst = rhs + lhs;
            return lexicographical_compare(rfirst.rbegin(),rfirst.rend(),lfirst.rbegin(),lfirst.rend());
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {

        // 21 211
        // 211 21
        //
        // 9 93
        // 93 9
        vector<string> revStr;
        transform(nums.begin(),nums.end(),back_inserter(revStr),[](int v){
            string ret;
            do{
                ret.push_back(v%10+'0');
                v/=10;
            }while(v>0);
            return ret;
        });

        sort(revStr.begin(),revStr.end(),cmp);

        string ret;
        for(auto it = revStr.rbegin();it!=revStr.rend();++it){
            for(auto rc=it->rbegin();rc!=it->rend();++rc ){

                if(ret.size()==1 && ret[0] == '0' && *rc =='0'){
                    continue;
                }

                ret.push_back(*rc);
            }

        }
        
        return ret;
    }
};

int main() {
  Solution s;
    
{
        string small= "32343";
        string big = "2343";
        assert(cmp(small,big));
    }
   {
        string big = "93";
        string small= "3";
        assert(cmp(small, big));
   }
    {
        string big = "3";
        string small= "03";
        assert(cmp(small, big));
   }
    {
        string big = "5";
        string small= "34";
        assert(cmp(small,big));
   }
    {
        vector<int> nums={34323,3432};
        assert(s.largestNumber(nums)=="343234323");
    }
  {

    vector<int> nums = {10, 2};
    assert(s.largestNumber(nums) == "210");
  }
  {

    vector<int> nums = {3, 30, 34, 5, 9};
    assert(s.largestNumber(nums) == "9534330");
  }
{

    vector<int> nums = {0,0};
    assert(s.largestNumber(nums) == "0");
  }
{

    vector<int> nums = {1,0,0};
    assert(s.largestNumber(nums) == "100");
  }
}
