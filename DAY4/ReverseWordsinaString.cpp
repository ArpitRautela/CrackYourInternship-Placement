class Solution {
public:
    string reverseWords(string s) {
        int length = s.size();
        vector<pair<int, int>> wordPositions;

        int i = 0;
        while (i < length) {
            while (i < length && s[i] == ' ')
                i++;
            if (i == length)
                break;

            int start = i;

            while (i < length && s[i] != ' ')
                i++;
            int end = i - 1;

            wordPositions.push_back({start, end});
        }

        string result = "";
        for (int j = wordPositions.size() - 1; j >= 0; --j) {
            string word =
                s.substr(wordPositions[j].first,
                         wordPositions[j].second - wordPositions[j].first + 1);
            result += word;
            if (j != 0)
                result += " ";
        }

        return result;
    }
};
