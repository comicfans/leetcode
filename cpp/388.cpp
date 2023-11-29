#include <regex>
#include <vector>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <algorithm>




using namespace std;

class Solution {
public:

    

    int lengthLongestPath(string input) {

        regex re(".{1,}\\.[a-zA-Z0-9 ]{1,}");


        input.push_back('\n');
        std::vector<int> parentLength;
        int parentTotalLength = 0;
        int longest = 0;
        
        auto idx = -1;
        while(idx != input.size()){

            // \n create new line
            // \t create stack

            auto sep = input.find('\n', idx +1);
            if(sep == string::npos){
                break;
            }

            //find leading tab
            auto noTab = input.find_first_not_of("\t",idx+1);

            int stackDepth = noTab - (idx+1);
            int subStrLength = sep - noTab;

            auto fileName = input.substr(noTab,subStrLength);

            //test if it is file

            bool isFile = regex_match(input.begin()+noTab, input.begin()+noTab + subStrLength, re);
            if(stackDepth == parentLength.size()){
                // this string is under parent
                int thisLong = subStrLength + parentTotalLength;
                parentLength.push_back(subStrLength);

                
                if(isFile){
                
                    int sepLength = parentLength.size()-1;
                    int thisRes = thisLong + sepLength;
                    longest = max(longest, thisRes);
                }

                
                parentTotalLength += subStrLength;
                idx = sep ;
                continue;
            }


            //how many to pop
            int popLength = parentLength.size() - stackDepth ;
            for(int i = 0;i< popLength;++i){
                parentTotalLength -= parentLength.back();
                parentLength.pop_back();
            }

            int thisLong = parentTotalLength + subStrLength;
            parentLength.push_back(subStrLength);
            parentTotalLength += subStrLength;
            if(isFile){
                int sepLength = parentLength.size()-1;
                int thisRes = thisLong + sepLength;
                longest = max(longest, thisRes);
            }
            idx = sep;
        }

        return longest;
    }
};

int main(){
    Solution s;
    {
         //assert(s.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20);
        //assert(s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") == 32);
        //assert(s.lengthLongestPath("a") == 0);
//assert(s.lengthLongestPath("file1.txt\nfile2.txt\nlongfile.txt")==12);
        assert(s.lengthLongestPath("sladjf\n\tlkjlkv\n\t\tlkjlakjlert\n\t\t\tlaskjglaksjf\n\t\t\t\tlakjgfljrtlj\n\t\t\t\t\tlskajflakjsvlj\n\t\t\t\t\t\tlskgjflkjrtlrjt\n\t\t\t\t\t\t\tlkjglkjlvkjdlvkj\n\t\t\t\t\t\t\t\tlfjkglkjfljdlv\n\t\t\t\t\t\t\t\t\tlkdfjglerjtkrjkljsd.lkvjlkajlfk\n\t\t\t\t\t\t\tlskfjlksjljslvjxjlvkzjljajoiwjejlskjslfj.slkjflskjldfkjoietruioskljfkljf\n\t\t\t\t\tlkasjfljsaljlxkcjzljvl.asljlksaj\n\t\t\t\tasldjflksajf\n\t\t\t\talskjflkasjlvkja\n\t\t\t\twioeuoiwutrljsgfjlskfg\n\t\t\t\taslkjvlksjvlkjsflgj\n\t\t\t\t\tlkvnlksfgk.salfkjaslfjskljfv\n\t\t\tlksdjflsajlkfj\n\t\t\tlasjflaskjlk\n\t\tlsakjflkasjfkljas\n\t\tlskjvljvlkjlsjfkgljfg\n\tsaljkglksajvlkjvkljlkjvksdj\n\tlsakjglksajkvjlkjdklvj\n\tlskjflksjglkdjbkljdbkjslkj\n\t\tlkjglkfjkljsdflj\n\t\t\tlskjfglkjdfgkljsdflj\n\t\t\t\tlkfjglksdjlkjbsdlkjbk\n\t\t\t\t\tlkfgjlejrtljkljsdflgjl\n\t\t\t\t\tsalgkfjlksfjgkljsgfjl\n\t\t\t\t\tsalkflajwoieu\n\t\t\t\t\t\tlaskjfglsjfgljkkvjsdlkjbklds\n\t\t\t\t\t\t\tlasjglriotuojgkjsldfgjsklfgjl\n\t\t\t\t\t\t\t\tlkajglkjskljsdljblkdfjblfjlbjs\n\t\t\t\t\t\t\t\t\tlkajgljroituksfglkjslkjgoi\n\t\t\t\t\t\t\t\t\t\tlkjglkjkljkljdkbljsdfljgklfdj\n\t\t\t\t\t\t\t\t\t\t\tlkjlgkjljgslkdkldjblkj\n\t\t\t\t\t\t\t\t\t\t\t\tlkjfglkjlkjbsdklj.slgfjalksjglkfjglf\n\t\t\t\t\t\t\t\t\t\t\t\tlkasjrlkjwlrjljsl\n\t\t\t\t\t\t\t\t\t\t\t\t\tlksjgflkjfklgjljbljls\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsglkjlkjfkljdklbjkldf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjglkjdlsfjdglsdjgjlxljjlrjsgjsjlk\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjsgkllksjfgjljdslfkjlkasjdflkjxcljvlkjsgkljsfg\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlaskjlkjsakljglsdjfgksdjlkgjdlskjb\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkajsgfljfklgjlkdjgfklsdjklj\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjfglkjlkgjlkjl.aslkjflasjlajglkjaf\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tlkjasflgjlskjglkfjgklgsdjflkbjsdklfjskldfjgklsfdjgklfdjgl\n\tlskadjlkjsldwwwwwfj\n\t\tlkjflkasjlfjlkjajslfkjlasjkdlfjlaskjalvwwwwwwwwwwwwwwwkjlsjfglkjalsjgflkjaljlkdsjslbjsljksldjlsjdlkjljvblkjlkajfljgasljfkajgfljfjgldjblkjsdljgsldjg.skljf") == 528);
    }

}
