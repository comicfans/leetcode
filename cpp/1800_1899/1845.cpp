#include <cwctype>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class SeatManager {
public:
    SeatManager(int n) {
        
        empty.push_back({1,n});
    }

    vector<pair<int,int>> empty;
    
    int reserve() {
        
        auto &first = empty.front();

        int ret = first.first;
        ++first.first;
        if(first.first > first.second){
            empty.erase(empty.begin());
        }
        return ret;

    }
    
    void unreserve(int seatNumber) {

        if(empty.empty()){
            empty.push_back({seatNumber,seatNumber});
            return;
        }
        
        auto pos = lower_bound(empty.begin(),empty.end(),pair<int,int>{seatNumber,seatNumber}, [](auto& lhs,auto& rhs){
            return lhs.first < rhs.first;
        }) - empty.begin();

        if(pos > 0){
            //test if it can be merged with previous

            if(empty[pos - 1].second == seatNumber - 1){
                empty[pos-1].second ++;
            }else{
                empty.insert(empty.begin()+pos,pair<int,int> {seatNumber,seatNumber});
                ++pos;
            }
        }else{
            empty.insert(empty.begin()+pos,pair<int,int> {seatNumber,seatNumber});
            ++pos;
        }

        if(pos == empty.size()){
            return;
        }

        if(seatNumber == empty[pos].first - 1){
            assert(pos > 0);
            empty[pos-1].second = empty[pos].second;
            empty.erase(empty.begin() + pos);
        }
        return;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

#include "../parse.h"
int main(){
    
    {
        auto calls = pvs("1845_case1.txt",0);
        auto args = pvvi("1845_case1.txt",1);
        auto expects = pvi("1845_case1.txt",2);

        assert(calls.size() == args.size());
        assert(calls.size() == expects.size());

        SeatManager m(args[0][0]);
        for(int i = 1;i<calls.size(); ++i){
            if(calls[i]=="reserve"){
                auto expect = expects[i];
                assert(m.reserve() == expect);
                continue;
            }
            m.unreserve(args[i][0]);
        }

    }
    {
        SeatManager m(5);
        assert(m.reserve()==1);
        assert(m.reserve()==2);
        m.unreserve(2);
        assert(m.reserve()==2);
        assert(m.reserve()==3);
        assert(m.reserve()==4);
        assert(m.reserve()==5);
        m.unreserve(5);
        assert(m.reserve()==5);

    }
}
//[null,1,null,1,null,1,null,1,2,3,4,5,null,null,null,2,null,4,5,null,null,1,null,null,null,1,null,1,2,3,4,null,1,2,3,null,null,null,1,null,2,3,4,null,5,null,null,null,null,1,null,null,2,null,null,1,2,3,4,null,2]
//[null,1,null,1,null,1,null,1,2,3,4,5,null,null,null,2,null,3,4,null,null,1,null,null,null,1,null,1,2,3,4,null,1,5,6,null,null,null,1,null,2,3,5,null,5,null,null,null,null,1,null,null,2,null,null,1,2,3,4,null,2]
