
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {



public:
    vector<vector<string> > partition(string s) {

        vector<vector<string>> result;

        vector<string> existing_chain;
        recursiveTest(s.cbegin(),s.cend(),existing_chain,result);

        return result;
        
    }

    void recursiveTest(string::const_iterator begin_pos,string::const_iterator end_pos, vector<string>& existing_chain ,vector<vector<string> >& result){

		if (begin_pos == end_pos) {
			result.push_back(existing_chain);
			return;
		}

        if (begin_pos == end_pos-1){

            vector<string> only_one(existing_chain);

            result.push_back(existing_chain);
            result.back().push_back(string(begin_pos,end_pos));
			return;

        }


		for (string::const_iterator split_pos = begin_pos + 1; split_pos <= end_pos; ++split_pos) {

            if (!is_palindrome(begin_pos,split_pos)){
                continue;
            }

            existing_chain.push_back(string(begin_pos,split_pos));

            vector<vector<string> > following_result;

            recursiveTest(split_pos,end_pos,existing_chain,following_result);

            existing_chain.pop_back();

            if (following_result.empty()){
                continue;
            }

            copy(following_result.begin(),following_result.end(),back_inserter(result));

        }

    }


    bool is_palindrome(string::const_iterator begin_pos ,string::const_iterator end_pos){

        while(begin_pos<end_pos){

            if (*begin_pos != *(end_pos-1)){
                return false;
            }

            ++begin_pos;
            --end_pos;
        }

        return true;
    }

};



int main(int argc, char *argv[])
{
    Solution a;

    auto result = a.partition("aab");



    cout<<"[\n";
    for(auto &v:result){

        cout<<"[";

        for(auto &k:v){
            cout<<"\""<<k<<"\",";
        }

        cout<<"]\n";
    }
    cout<<"]\n";

    return 0;
}
