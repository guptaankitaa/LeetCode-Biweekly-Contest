class Solution {
public:
    std::string lastNonEmptyString(std::string s) {
        std::string result;
        std::unordered_map<char, int> charCountMap;

        // Count occurrences of each character in the input string
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];
            charCountMap[currentChar] = charCountMap[currentChar] + 1;
        }

        // Find the maximum occurrence count
        int maxCount = 0;
        std::unordered_set<char> processedChars;
        for (auto& entry : charCountMap) {
            int charCount = entry.second;
            if (charCount > maxCount) {
                maxCount = charCount;
            }
        }

        // Append characters with the maximum occurrence count in reverse order
        for (int i = s.length() - 1; i >= 0; i--) {
            char currentChar = s[i];
            if (charCountMap[currentChar] == maxCount && processedChars.find(currentChar) == processedChars.end()) {
                result.push_back(currentChar);
            }
            processedChars.insert(currentChar);
        }

        // Reverse the result string
        std::reverse(result.begin(), result.end());

        return result;
    }
};
