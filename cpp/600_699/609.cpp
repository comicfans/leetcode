#include <algorithm>
#include <cassert>
#include <map>
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
  vector<vector<string>> findDuplicate(vector<string> &paths) {

    unordered_map<string, set<string>> content_path;

    for (const auto &str : paths) {

      auto space_pos = str.find(' ');
      if (space_pos == string::npos) {
        continue;
      }
      string_view root(str.begin(), str.begin() + space_pos);
      auto prev_pos = space_pos;
      while (prev_pos != string::npos && prev_pos != str.size()) {

        space_pos = str.find(' ', prev_pos + 1);
        if (space_pos == string::npos) {
          space_pos = str.size();
        }

        string_view file_content(str.begin() + prev_pos + 1,
                                 str.begin() + space_pos);
        assert(file_content.size() > 0);

        auto left = file_content.find('(');
        auto file = file_content.substr(0, left);
        auto content =
            file_content.substr(left + 1, file_content.size() - left - 2);

        string fullpath(root);
        fullpath.push_back('/');
        fullpath += file;
        content_path[string(content)].insert(fullpath);
        prev_pos = space_pos;
      }
    }
    vector<vector<string>> ret;

    for (const auto &[content, path] : content_path) {
      if (path.size() == 1) {
        continue;
      }
      ret.emplace_back();
      for (const auto &p : path) {
        ret.back().push_back(p);
      }
    }

    return ret;
  }
};

#ifdef LEETCODE
int main() {
  Solution s;
  {
    vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)",
                            "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                            "root 4.txt(efgh)"};
    auto res = s.findDuplicate(paths);
    // VI = {};
    // VVI = {};
  }
  {
    // VI = {};
    // VVI = {};
  }
}
#endif
