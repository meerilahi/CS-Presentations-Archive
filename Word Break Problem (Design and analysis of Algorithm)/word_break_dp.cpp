#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

bool wordBreakHelper(const string& s, const unordered_set<string>& wordDict,
                  unordered_map<string, bool>& memo) {

    if (memo.find(s) != memo.end()) {
        return memo[s];
    }
    if (wordDict.find(s) != wordDict.end()) {
        memo[s] = true;
        return true;
    }
    for (int i = 1; i < s.length(); ++i) {
        string prefix = s.substr(0, i);
        string suffix = s.substr(i);
        if (wordDict.find(prefix) != wordDict.end() && wordBreakHelper(suffix, wordDict, memo)) {
            memo[s] = true;
            return true;
        }
    }
    memo[s] = false;
    return false;
}

bool wordBreak(const string& s, const unordered_set<string>& wordDict) {
    unordered_map<string, bool> memo;
    return wordBreakHelper(s, wordDict, memo);
}

int main() {
    string s = "mypencil";
    unordered_set<string> wordDict = {"my", "pen", "pencil"};
    
    if (wordBreak(s, wordDict)) {
        cout << "String can be segmented." << endl;
    } else {
        cout << "String cannot be segmented." << endl;
    }
    
    return 0;
}
