#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// Function to check if a string can be segmented into words from the dictionary
bool wordBreakHelper(string s, unordered_set<string>& wordDict, int start) {
    // Base case: If we have processed the entire string, return true
    if (start == s.length()) {
        return true;
    }

    // Iterate over all possible substrings starting from the current position
    for (int i = start + 1; i <= s.length(); ++i) {
        // Check if the substring from start to i is in the word dictionary
        string word = s.substr(start, i - start);
        if (wordDict.find(word) != wordDict.end()) {
            // If it is, recursively check the remaining substring
            if (wordBreakHelper(s, wordDict, i)) {
                // If a valid segmentation is found, return true
                return true;
            }
        }
    }

    // If no valid segmentation is found, return false
    return false;
}

// Wrapper function to initiate the recursive process
bool wordBreak(string s, unordered_set<string>& wordDict) {
    return wordBreakHelper(s, wordDict, 0);
}

int main() {
    // Example usage
    string s = "leetcode";
    unordered_set<string> wordDict = {"leet", "code"};

    // Check if the string can be segmented
    if (wordBreak(s, wordDict)) {
        cout << "String can be segmented.\n";
    } else {
        cout << "String cannot be segmented.\n";
    }

    return 0;
}
