#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

/*
    Word Break Problem

    Goal:
    - Determine if a string can be segmented into valid dictionary words
    - If yes, reconstruct ONE valid segmentation

    Approach:
    - Dynamic Programming (DP)
    - dp[i] = true if substring s[0..i-1] can be segmented
*/

class WordBreaker {
private:
    unordered_set<string> dict; // fast lookup for dictionary words

public:
    // Constructor to initialize dictionary
    WordBreaker(const vector<string>& dictionary) {
        for (const string& word : dictionary) {
            dict.insert(word);
        }
    }

    /*
        Function: canBreak
        ------------------
        Returns true if string can be segmented.
        Also fills 'parent' array to reconstruct solution.
    */
    bool canBreak(const string& s, vector<int>& parent) {
        int n = s.length();

        // DP array
        vector<bool> dp(n + 1, false);

        // Base case: empty string
        dp[0] = true;

        // Initialize parent array
        parent.assign(n + 1, -1);

        // Build DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If first part is valid and second part is in dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    parent[i] = j; // store split position
                    break; // stop early once found
                }
            }
        }

        return dp[n];
    }

    /*
        Function: reconstruct
        ---------------------
        Uses parent array to rebuild the segmented string.
    */
    string reconstruct(const string& s, const vector<int>& parent) {
        string result = "";
        int index = s.length();

        // Trace back from end
        while (index > 0) {
            int prev = parent[index];
            string word = s.substr(prev, index - prev);

            if (!result.empty()) {
                result = word + " " + result;
            }
            else {
                result = word;
            }

            index = prev;
        }

        return result;
    }

    /*
        Function: solve
        ---------------
        Main function that checks and prints result.
    */
    void solve(const string& s) {
        vector<int> parent;

        if (canBreak(s, parent)) {
            cout << "String CAN be segmented.\n";
            cout << "One valid segmentation:\n";
            cout << reconstruct(s, parent) << endl;
        }
        else {
            cout << "String CANNOT be segmented.\n";
        }
    }
};

/*
    ============================
    MAIN FUNCTION (TEST CASES)
    ============================
*/
int main() {
    // Test dictionary
    vector<string> dictionary = {
        "apple", "pie", "app", "leet", "code", "cats", "dog", "sand", "and", "cat"
    };

    WordBreaker wb(dictionary);

    // Test Case 1
    cout << "Test 1:\n";
    wb.solve("applepie");
    cout << "-------------------\n";

    // Test Case 2
    cout << "Test 2:\n";
    wb.solve("leetcode");
    cout << "-------------------\n";

    // Test Case 3 (edge case - not possible)
    cout << "Test 3:\n";
    wb.solve("catsandog");
    cout << "-------------------\n";

    // Test Case 4 (edge case - empty string)
    cout << "Test 4:\n";
    wb.solve("");
    cout << "-------------------\n";

    return 0;
}