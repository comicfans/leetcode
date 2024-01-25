#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        sort(tickets.begin(),tickets.end());
        // from -1
        // to   +1
        map<string, int> cityInputOutput;

        for(const auto& fromTo: tickets ){
            cityInputOutput[fromTo[0]] --;
            cityInputOutput[fromTo[1]] ++;
        }


        //must begin from a fromTo <0 city, end fromTo > 0 city
        //if all equal 0, pick lexcical least as start

        string fromCity = "";
        int minIo = 0;

        string toCity = "";
        int maxIo = 0;

        for(const auto& kv: cityInputOutput){

            if(kv.second < minIo){
                fromCity = kv.first;
            }else if(kv.second == minIo){

                if(fromCity.empty()){
                    fromCity = kv.first;
                }else{
                    fromCity = min(fromCity, kv.first);
                }
            }

            if(kv.second > maxIo){
                toCity = kv.first;
            }else if(kv.second == maxIo){
                if(toCity.empty()){
                    toCity = kv.first;
                }else{
                    toCity = max(toCity, kv.first);
                }
            }

        }

        vector<string> ret = {fromCity};
        


        while(!tickets.empty()){

            auto eqRange = equal_range(tickets.begin(),tickets.end(),vector<string>{fromCity},[&](auto& lhs, auto& rhs){
                return lhs.front() < rhs.front();
            });

            assert(eqRange.first != eqRange.second);

            if(eqRange.second  -eqRange.first > 1 && (eqRange.first->back() == toCity)){
                eqRange.first++;
            }
            fromCity = eqRange.first->back();
            ret.push_back(fromCity);
            tickets.erase(eqRange.first);
        }

        return ret;
    }
};

int main(){
    Solution s;
    {
        vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
        vector<string> expect = {"JFK","MUC","LHR","SFO","SJC"};
        assert(s.findItinerary(tickets) == expect);
    }
    {
        vector<vector<string>>tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
        vector<string> expect =  {"JFK","ATL","JFK","SFO","ATL","SFO"};
        assert(s.findItinerary(tickets) == expect);
    }

}
