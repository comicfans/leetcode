#include <numeric>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;


struct Pick{
    Pick(int m,int n):total(m){
        assert(m>=n);
        idx.resize(n);
        for(int i = 0;i<n;++i){
            idx[i] = i;
        }
    }
    bool next(){
        for(int i=(int)idx.size()-1;i>=0;--i){
            if(idx[i]==total - (idx.size()-i)){
                    continue;
            }

           idx[i]++;
            
           for(int j = i+1; j< idx.size();++j){
               idx[j]= idx[j-1]+1;
           }

           return true;

        }

        return false;
    }

    const int total;
    vector<int> idx;
};
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {

        vector<int> hour  = {1,2,4,8};

        vector<int> minute  = {1,2,4,8,16,32};

        vector<string> ret;

        for(int hourUse = max(0,turnedOn - (int)minute.size()); hourUse <= min(4,turnedOn); ++ hourUse){
            //assin n to 4 possible position
            // 4! / n! / (4-n)!

            Pick hourPick (4, hourUse);

            vector<int> validHours;
            while(true){

                int hourSum = 0;
                for(auto v: hourPick.idx){
                    hourSum += hour[v];
                }

                if(hourSum >= 12){
                    break;
                }
                validHours.push_back(hourSum);
                if(!hourPick.next()){
                    break;
                }
            }

            int minuteUse = turnedOn - hourUse;
            vector<int> validMinutes;
            Pick minPick(minute.size(),minuteUse);
            while(true){

                    int minSum = 0;
                    for(auto v: minPick.idx){
                        minSum += minute[v];
                    }

                    if(minSum >= 60){
                        break;
                    }
                validMinutes.push_back(minSum);
                if(!minPick.next()){
                    break;
                }
            }

            for(auto h: validHours){

                string hh = to_string(h);
                for(auto m: validMinutes){
                    string mm = to_string(m);
                    if(mm.size()!=2){
                        mm = "0"+mm;
                    }

                    ret.push_back(hh+":"+mm);
                }
            }
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        auto res = s.readBinaryWatch(3);
        vector<string> expect = {"0:07","0:11","0:13","0:14","0:19","0:21","0:22","0:25","0:26","0:28","0:35","0:37","0:38","0:41","0:42","0:44","0:49","0:50","0:52","0:56","1:03","1:05","1:06","1:09","1:10","1:12","1:17","1:18","1:20","1:24","1:33","1:34","1:36","1:40","1:48","2:03","2:05","2:06","2:09","2:10","2:12","2:17","2:18","2:20","2:24","2:33","2:34","2:36","2:40","2:48","3:01","3:02","3:04","3:08","3:16","3:32","4:03","4:05","4:06","4:09","4:10","4:12","4:17","4:18","4:20","4:24","4:33","4:34","4:36","4:40","4:48","5:01","5:02","5:04","5:08","5:16","5:32","6:01","6:02","6:04","6:08","6:16","6:32","7:00","8:03","8:05","8:06","8:09","8:10","8:12","8:17","8:18","8:20","8:24","8:33","8:34","8:36","8:40","8:48","9:01","9:02","9:04","9:08","9:16","9:32","10:01","10:02","10:04","10:08","10:16","10:32","11:00"};

        sort(expect.begin(),expect.end());
        sort(res.begin(),res.end());
        assert(expect == res);
    }
    {

        auto res = s.readBinaryWatch(2);

        vector<string> expect = {"0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24","0:33","0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01","2:02","2:04","2:08","2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32","5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00"};
        sort(expect.begin(),expect.end());
        sort(res.begin(),res.end());
        assert(expect == res);
    }
    {
        auto res = s.readBinaryWatch(1);
        vector<string> expect = {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"};
        assert(res == expect);
    }
    {
        auto res = s.readBinaryWatch(9);
        assert(res.empty());
    }
}
