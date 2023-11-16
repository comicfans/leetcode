#include <set>
#include <cassert>
#include <limits>
#include <string>
using namespace std;


template <class S, class C>
//first reached is best
struct Dfs{

    static bool RecRun(S& state){

        if(C::StopSearch(state)){
            return true;
        }

        return C::MoreSearch(state);
    }
};




struct State{

    const int ijCost;
    const int strLen;
    int slowest;
    std::set<int> diffPos;
    int current = 0;
    int best = std::numeric_limits<int>::max();

    State(const State& rhs) = default;

    State(
          const std::string& s0,
          const std::string& s1,const int cost):
        ijCost(cost),
        strLen(s0.size()){
        for(int i=0;i<s0.length();++i){
            if(s0[i] != s1[i]){
                diffPos.insert(i);
            }
        }
        slowest = diffPos.size() /2 * ijCost;
    }
};


struct Dfs1: public Dfs<State, Dfs1>{

static bool StopSearch(State& state){

    if (state.diffPos.size() == 0){
        state.best = state.current;
        return true;
    }



    return (state.diffPos.size() %2 != 0) || 
           (state.current >= state.best) || (state.current >= state.slowest);
}


static bool MoreSearch(State& state){
    //must pick at least one of diff pos,otherwise meaningless
    //
    //
    assert (!state.diffPos.empty());

        auto firstIdx = *state.diffPos.begin();
    assert (!state.diffPos.empty());
    state.diffPos.erase(state.diffPos.begin());

    auto secondPos = state.diffPos.begin();
    for(;;){

        State newState(state); 
        auto bestCost = min(state.ijCost, *secondPos - firstIdx);

        auto adv = secondPos;
        ++adv;
        newState.diffPos.erase(*secondPos);

        newState.current+= bestCost;


        if(RecRun(newState)){
                    state.best = min(newState.best, state.best);
                    break;
        }

                if(adv == state.diffPos.end()){
                    break;
                }else{
                    //++adv;
                }
            secondPos = adv;
        }
            
        return state.best != std::numeric_limits<int>::max();
    }
};

class Solution {
public:
    int minOperations(string s1, string s2, int x) {


        State state(s1,s2,x);

        Dfs1 dfs;

        dfs.RecRun(state);
            
        return state.best == std::numeric_limits<int>::max()? -1:state.best;

    }

};


int main(){

    Solution s;
    {
        std::string s1 = "1100011000";
        std::string s2 = "0101001010";
        int x = 2;

        int res =s.minOperations(s1,s2,x) ;
        assert(res == 4);
    }
    {

        std::string s1 = "10110";
        std::string s2 = "00011";
        int x = 4;

        int res =s.minOperations(s1,s2,x) ;
        assert(res == -1);
    }
    {

        std::string s1 = "101101";
        std::string s2 = "000000";
        int x = 6;

        int res =s.minOperations(s1,s2,x) ;
        assert(res == 4);
    }
    {

        std::string s1 = "01111101010100110100";
        std::string s2 = "10010011011001011000";
        int x = 21;

        int res =s.minOperations(s1,s2,x) ;
    }
    {

        std::string s1 = "00001100011000100101";
        std::string s2 = "11111000101111001110";
        int x = 14;

        int res =s.minOperations(s1,s2,x) ;
    }
    {

        std::string s1 = "11001011111";
        std::string s2 = "01111000110";
        int x = 2;

        int res =s.minOperations(s1,s2,x) ;
        assert (res == 4);
    }
    {

        std::string s1 = "11111001100111101010101010100000010000000010110100111000001100101100000010000011100";
        std::string s2 = "11101101001010101001000110010101011001100110011011001101100100101101100101100000010";
        int x = 50;

        int res =s.minOperations(s1,s2,x) ;
    }
    too slow
}
