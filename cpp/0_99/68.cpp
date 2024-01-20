#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> ret;


        int total = 0;
        for(const auto &w:words){
            total += w.size();
        }

        int left = total;
        int current = 0;

        bool isNewline = true;
        vector<string> line;
        for(int i = 0;i < words.size(); ){
            if(isNewline){
                if(left + (words.size()-i-1) <= maxWidth){
                    string last ;
                    for(int j = i;j<words.size();++j){
                        last = last + words[j];
                        last += ' ';
                    }
                    last.resize(maxWidth,' ');
                    ret.push_back(last);
                    break;
                }

                line.push_back(words[i]);
                current = words[i].size();
                left -= words[i].size();
                isNewline = false;
                ++i;
                continue;
            }

            //is not newLine, must complete it
            if(current + line.size() + words[i].size() > maxWidth){
                auto thisLine =oneLine(line,maxWidth - current); 
                thisLine.resize(maxWidth,' ');
                ret.push_back(thisLine);
                line.clear();
                isNewline  = true;
                current =  0;
                continue;
            }


            line.push_back(words[i]);
            current += words[i].size();
            left -= words[i].size();
            isNewline = false;
            ++i;
        }



        return ret;

    }

    string oneLine(const vector<string>& line, int spaces){

        //how many space to be used
        int small = line.size()==1?spaces: (spaces / (line.size() - 1));

        int smallConsume = small * (line.size()-1);
        int left = spaces - smallConsume;

        string res;

        string empty;
        empty.resize(small,' ');
        for(int i = 0; i<line.size();++i){
            if(i==0){
                res= line[i];
                continue;
            }

            if(left > 0){
                res.push_back(' ');
                --left;
            }

            res+=(empty);
            res+= line[i];
        }
        return res;

    }
};

int main(){
    Solution s;
    {

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> expect = 
    {
   "This    is    an",
   "example  of text",
   "justification.  "
};
        auto output = s.fullJustify(words,maxWidth);
        assert(output == expect);
}
    {

vector<string> words = {"What","must","be","acknowledgment","shall","be"};
        int maxWidth = 16;
vector<string> expect = 
            {
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
        };

        auto output = s.fullJustify(words,maxWidth);
        assert(output == expect);
    }
    {


vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
        int maxWidth = 20;
            vector<string> expect = {
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
};
        auto output = s.fullJustify(words,maxWidth);
        assert(output == expect);
    }
}
