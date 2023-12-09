class Solution {
public:
    int removeAlmostEqualCharacters(std::string word) {
        int count = 0;
        int n = word.length();
        
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1] || abs(word[i] - word[i - 1]) == 1) {
                word[i] = ' ';
                count++;
            }
        }
        
        return count;
    }
};
