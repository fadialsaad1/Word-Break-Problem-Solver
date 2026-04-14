https://youtu.be/xc51juvFPaY

Fadi Alsaad
fadialsaad@oakland.edu
Word Break Problem Solver (Dynamic Programming)

-Description:
The goal of this project is to determine whether a given string can be segmented into a sequence of valid words from a provided dictionary.
For example:
Input: "applepie"
Dictionary: ["apple", "pie", "app"]
Output: "apple pie"
If no valid segmentation exists, the program reports that the string cannot be segmented.

-how to run your program:
This project uses a Dynamic Programming (DP) approach.
We create a DP array where:
dp[i] = true means the substring from index 0 to i-1 can be segmented into valid dictionary words.
Steps:
  Initialize dp[0] = true (empty string is valid).
  For each position i from 1 to n:
  Check all possible split points j from 0 to i
  If:
  dp[j] == true, and
  substring s[j:i] exists in the dictionary → then mark dp[i] = true
  Store split positions in a parent array to reconstruct the solution.
  If dp[n] == true, reconstruct and print one valid segmentation.

-Pseudocode:
  dp[0] = true

for i from 1 to n:
    for j from 0 to i:
        if dp[j] == true AND substring(j, i) in dictionary:
            dp[i] = true
            parent[i] = j
            break

Time Complexity: O(n²)
We check all substrings using two nested loops
Space Complexity: O(n)
DP array and parent array


-Test Cases
  Test Case 1
  Input: "applepie"
  Output: "apple pie"
  
  Test Case 2
  Input: "leetcode"
  Output: "leet code"

  Test Case 3 (Edge Case - Not Possible)
  Input: "catsandog"
  Output: Cannot be segmented
  
  Test Case 4 (Edge Case - Empty String)
  Input: ""
  Output: Valid (empty string)



  -AI Usage Declaration:
  Generate explanations for the README
  debugging and adding comments
