class Solution {
    unordered_set<string> words;
    queue<pair<string, int>> q; // word, steps to create that word
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (int i=0;i<wordList.size();i++)
        {
            words.insert(wordList[i]);
        }
        q.push({beginWord, 1});
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;
            string temp=word;
            for (int i = 0; i < word.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c; //replace each position A-Z
                    if (words.find(word)!= words.end()) {
                        q.push({word, steps + 1});
                        words.erase(word); //remove word from set to avoid repetition
                    }
                    word=temp; //reset word for next position
                }    
            }
        }
        return 0;
    }
};
