class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result;
        int i = 0, j = 0;
        int n1 = word1.length(), n2 = word2.length();

        // Merge characters alternately
        while (i < n1 && j < n2) {
            result += word1[i++];
            result += word2[j++];
        }

        // Append remaining characters from word1 (if any)
        while (i < n1) {
            result += word1[i++];
        }

        // Append remaining characters from word2 (if any)
        while (j < n2) {
            result += word2[j++];
        }

        return result;
    }
};
