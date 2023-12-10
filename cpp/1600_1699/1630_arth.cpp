#include <iostream>
#include <limits>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        vector<bool> res;
        res.resize(l.size());


        for(int q = 0; q< l.size(); ++q){
            if(q == 268){
                int a= 3;
            }

            int begin = l[q];
            int end = r[q];

            if(end - begin <= 1){
                res[q] = true;
                continue;
            }

            // testing if it has overlap with previous result
            
            //bool quickTest = false;
            //for(int check = 0; check < q;++check){
            //    int checkBegin = l[check];
            //    int checkEnd = r[check];

            //    //test overlap
            //    if((begin <= checkBegin) && (end >= checkEnd)){
            //        //is subset
            //        if(!res[check]){
            //            res[q] = false;
            //            quickTest = true;
            //            break;
            //        }
            //    }
            //}

            //if(quickTest){
            //    continue;
            //}

            // check from begin

            vector<int> copy(nums.begin()+begin, nums.begin()+end+1);
            sort(copy.begin(),copy.end());
            int delta = copy[1] - copy[0];
            res[q] = true;
            for(int i=2;i<copy.size();++i){
                if(copy[i] - copy[i-1] != delta) {
                    res[q] = false;
                    break;
                }
            }

        }
        return res;
        
    }
};

int main(){
    Solution s;
    {
        vector<int> nums={4,6,5,9,3,7};
        vector<int> l = {0,0,2};
        vector<int> r = {2,3,5};
        vector<bool> expect = {true,false,true};

        auto res = s.checkArithmeticSubarrays(nums,l,r);
        assert(res == expect);

    }
    {
        vector<int> nums={-532,-741,132,504,2700,1500,60,180,1740,2880,-1155,-1705,-825,-220,-660,-1595,-990,2752,3776,256,1408,4224,3264,2432,4352,960,704,2880,3136,3712,2688,4416,1920,3968,2304,1984,3072,1152,4160,3008,2240,2560,3648,1088,3840,2816,64,1216,1024,832,4096,1792,-159,-53,-106,-52,-40,-23,-9,-65,-57,-10,-2,-15,-29,-12,-31,-45,-28,-46,-38,-49,-24,-13,-36,-17,-25,-37,-21,-55,-1,-42,-39,-50,-20,-26,-53,-60,-66,-22,-41,-34,-43,-14,-54,-59,-8,-51,-62,-4,-56,-32,-35,-6,-3,-69,-33,-64,-68,-58,-18,-61,-70,-19,-7,-11,-44,-48,-67,-47,-5,-30,-63,-27,-16,648,1440,1908,2052,972,288,684,1512,1008,360,1620,1296,2088,1872,1764,144,576,180,1800,108,1656,1836,396,900,2124,1116,432,756,-623,891,99,1683};
        vector<int> l = {13,79,111,43,31,52,0,93,15,112,94,87,98,62,17,17,114,137,48,24,94,101,111,77,4,38,7,9,35,22,60,18,93,22,11,80,49,44,110,24,45,106,69,33,47,68,49,21,49,8,45,32,129,28,95,71,104,79,60,40,49,26,15,82,24,59,6,100,73,59,61,88,60,5,11,6,37,16,149,23,45,54,101,84,2,65,56,118,113,8,24,68,59,57,13,67,4,95,94,75,28,42,33,2,68,32,132,105,53,28,31,129,16,18,53,46,71,49,66,36,62,52,58,22,25,45,75,38,83,88,114,93,3,51,124,22,35,82,6,51,56,97,47,56,52,45,69,63,69,93,56,73,17,19,76,66,100,133,28,11,19,54,50,62,81,85,74,55,38,40,74,122,114,94,131,39,15,47,48,28,42,41,29,34,75,0,31,103,61,3,104,31,14,33,117,4,44,2,8,63,44,4,65,83,71,19,60,66,101,84,50,2,86,107,33,17,37,29,12,31,69,2,40,17,107,56,114,96,24,128,82,111,0,39,10,131,77,29,41,137,16,18,59,3,84,40,11,74,51,54,90,9,2,58,93,18,26,33,91,35,98,13,40,64,59,69,33,93,55,23,79,26,9,41,39,36,67,19,59,18,23,12,129,39,88,5,59,108,83,93,10,87,8,99,54,117,51,53,24,6,87,10,27,66,50,34,62,58,70,6,20,44,96,17,117,35,50,57,53,1,78,60,40,9,45,106,63,84,21,46,67,4,52,6,43,66,90,45,33,10,62,33,4,57,60,52,7,0,49,141,90,39,38,125,8,47,65,126,125,91,101,75,41,20,33,19,132,27,30,34,93,90,0,5,21,15,13,82,83,52,21,21,96,9,79,87,14,97,85,101,57,28,3,63,8,126,28,109,72,132,84,17,48,63,42,27,19,31,116,7,69,31,34,45};
        vector<int> r = {15,132,131,112,100,121,69,122,33,142,106,96,133,75,46,34,130,141,91,93,150,140,155,100,73,106,76,36,57,79,122,88,143,24,28,149,75,51,117,54,114,141,78,43,116,125,98,71,72,69,111,101,141,97,109,140,125,148,99,69,110,95,30,151,77,128,15,122,142,98,130,153,129,25,80,75,71,51,154,92,80,77,125,153,71,126,92,137,138,59,37,137,128,88,44,137,73,136,104,77,83,111,62,33,85,101,134,143,62,97,100,131,41,74,105,91,140,118,135,105,84,58,127,83,41,114,144,97,152,126,137,95,70,77,156,91,104,93,25,97,125,124,116,64,121,114,133,132,118,119,125,107,39,88,136,123,138,155,97,80,88,98,119,75,150,123,112,123,78,42,143,151,153,155,141,80,84,95,117,76,95,80,48,103,144,69,100,146,130,37,109,72,28,55,152,13,113,57,77,109,57,47,85,103,127,88,100,112,149,119,84,71,131,136,50,60,76,41,18,60,100,5,100,86,145,87,121,119,55,130,151,149,69,63,45,142,143,98,110,155,45,87,95,35,126,110,80,143,59,102,112,45,59,123,103,48,93,78,138,88,105,77,80,133,106,138,48,152,124,92,122,95,52,83,68,77,136,70,113,48,92,66,131,109,152,58,99,153,139,150,29,150,77,131,56,138,120,83,29,75,156,38,31,69,94,59,131,68,93,75,32,113,113,64,145,84,84,123,80,70,147,109,75,66,114,125,77,153,80,115,92,60,121,44,52,135,104,97,102,79,118,67,65,122,121,55,31,69,53,152,147,108,107,149,68,56,134,153,145,105,149,132,110,89,102,71,152,83,99,46,155,137,33,43,90,54,82,123,152,121,78,90,103,76,148,156,83,129,127,111,90,60,72,132,77,151,97,136,89,156,153,57,100,89,102,61,50,100,128,19,138,100,62,98};

        vector<bool> expect = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,true,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};

        auto res = s.checkArithmeticSubarrays(nums,l,r);
        for(int i =0;i<res.size();++i){
            if(res[i]!= expect[i]){
                cout<<i<<endl;
            }
        }
        assert(res == expect);


    }
}
