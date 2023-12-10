#include <vector>
#include <cassert>

using namespace std;
class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) :_encoding(encoding){
        
    }

    
    int next(int n) {


        int left = n;
        while((left > 0) && (_groupIdx < _encoding.size())){
            if(_encoding[_groupIdx]==0){
                _groupIdx += 2;
                continue;
            }


            int thisConsume = min(_encoding[_groupIdx], left);
            left -= thisConsume;
            _encoding[_groupIdx] -= thisConsume;
            
        }
        if(_groupIdx == _encoding.size()){
            return -1;
        }
        return _encoding[_groupIdx+1];
    }

    vector<int>& _encoding;
    int _groupIdx = 0;

};

int main(int, char**){
    
    {
        vector<int> seq{3,8,0,9,2,5};
        RLEIterator it(seq);

        vector<int> inputs{2,1,1,2};
        vector<int> outputs{8,8,5,-1};

        for(int idx = 0; idx < inputs.size(); ++idx){
            assert(it.next(inputs[idx]) == outputs[idx]);
        }

    }

}
