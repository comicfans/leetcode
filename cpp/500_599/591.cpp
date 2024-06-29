#include <algorithm>
#include <cassert>
#include <map>
#include <regex>
#include <set>
#include <string>
#include <vector>

using namespace std;

#ifdef LEETCODE
#include "../parse.h"
#endif

// jj
class Solution {
public:
  // const regex tag_start_reg = regex("<[A-Z]+>");
  // const regex tag_end_reg = regex("</[A-Z]+>");
  // const string cdata_head = "<![CDATA[";

  const regex mixed_reg = regex("<([A-Z]+)>|</([A-Z]+)>|<!\\[CDATA\\[");

  bool isValid(string code) {
    std::vector<string> tag_stack;

    return rec(code, 0, tag_stack);
  }

  bool rec(const string &xml, const int pos, vector<string> stack) {

    if (pos == xml.size()) {
      return stack.empty();
    }

    auto next = sregex_iterator(xml.begin() + pos, xml.end(), mixed_reg);
    if (next == sregex_iterator()) {
      // left must be all space
      return std::all_of(xml.begin() + pos, xml.end(),
                         [](auto c) { return c == ' '; });
    }

    auto match = *next;
    auto match_start = match.position(0);

    const int tag_start_pos = pos + match_start;
    auto match_length = match.length(0);
    string whole = match.str(0);

    // from pos up to tag_start_pos, can't be any "<"
    auto search_end = xml.begin() + pos + match_start;
    auto unmatched_pos = find(xml.begin() + pos, search_end, '<');
    if (unmatched_pos != search_end) {
      return false;
    }

    if (whole[1] == '!') {
      // cdata
      auto cdata_end = xml.find("]]>", tag_start_pos + match_length);
      if (cdata_end == string::npos) {
        return false;
      }

      if (stack.empty()) {
        return false;
      }

      return rec(xml, cdata_end + 3, stack);
    }

    if (whole[1] == '/') {
      auto tag_name = match.str(2);
      // close tag, must match prev open

      if (stack.empty() || stack.back() != tag_name) {
        return false;
      }
      stack.pop_back();

      return rec(xml, tag_start_pos + match_length, stack);
    }

    auto tag_name = match.str(1);
    if (tag_name.size() > 9) {
      return false;
    }
    // open tag
    if (stack.empty() && tag_start_pos != 0) {
      return false;
    }
    stack.push_back(tag_name);
    return rec(xml, tag_start_pos + match_length, stack);
  }
};
#ifdef LEETCODE
int main() {
  Solution s;
  {
    string valid = "<DIV>This is the first line <![CDATA[<div>]]></DIV>";
    assert(s.isValid(valid));
  }
  {

    string valid = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>";
    assert(s.isValid(valid));
  }
  {

    string valid = "<A>  <B> </A>   </B>";
    assert(!s.isValid(valid));
  }
  {
    string invalid = "<DIV>  unmatched <  </DIV>";

    assert(!s.isValid(invalid));
  }
  {
    string bad = "<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>";

    assert(!s.isValid(bad));
  }
  {
    string bad = "<AAAAAAAAAA></AAAAAAAAAA>";

    assert(!s.isValid(bad));
  }

  {
    string bad = "<A><A></A></A>";

    assert(!s.isValid(bad));
  }
}
#endif
