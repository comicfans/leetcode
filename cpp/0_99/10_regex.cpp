#include <cassert>
#include <string>
using namespace std;
class Solution {
public:


    string simpifyPattern(string p){


        string simple;
        for(int i=0;i<p.size();++i){
            
            bool this_is_star = (p[i] == '*');
            bool prev_input_star= (i>1 && p[i-1] == '*');
            if(this_is_star && prev_input_star){
                continue;
            }


            bool prev_is_star = ((simple.size()>2) && (simple[simple.size()-2] == '*'));

            if(this_is_star && prev_is_star && (simple[simple.size()-3] == p[i-1])){
                simple.pop_back();
                continue;
            }else{
                simple.push_back(p[i]);
            }
        }
        return simple;
    }

    bool recMatch(const string& s, const string& p, int s_i, int p_i){

        if(p_i == p.size()){
            return s_i == s.size();
        }

        //has pattern        

        //normal char match

        assert(p[p_i]!= '*');

        bool this_match = [&](){
            if (s_i == s.size()){
                return false;
            }
            return (p[p_i] == '.') || (p[p_i] == s[s_i]);
        }();

        bool next_is_star = ((p_i +1 < p.size()) && (p[p_i+1] == '*'));

        if(!next_is_star){
            return this_match && recMatch(s,p,s_i+1,p_i+1);
        }


        //try zero match first?
        //
        if (recMatch(s,p,s_i,p_i+2)){
            return true;
        }
        
        //next is star
        if(!this_match){
            return false;
        }
            
        return recMatch(s,p,s_i+1,p_i) || recMatch(s,p,s_i+1,p_i+2);
        
    }

    bool isMatch(string s, string p) {

        auto simplified = simpifyPattern(p);

        
        return recMatch(s,simplified,0,0);
    }
};

int main(int,char**){

    Solution s;
    assert(s.simpifyPattern("a*") == "a*");
    assert(s.simpifyPattern("a*a*") == "a*");

    assert(!s.isMatch("aa","a"));
    assert(s.isMatch("aa","a*"));
    assert(s.isMatch("aa","aa"));
    assert(s.isMatch("ab",".*"));
    assert(s.isMatch("aab","c*a*b"));
    assert(!s.isMatch("mississippi","mis*is*p*."));
    assert( s.isMatch("mississippi","mis*is*ip*."));
    assert(s.isMatch("a","ab*"));
    assert(!s.isMatch("aaaaaaaaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*"));
    assert(s.isMatch("abc","a***abc"));

}

