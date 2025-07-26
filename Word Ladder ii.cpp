class Solution {
    unordered_set<string> words;
    unordered_map<string, int> mp; //maps each word to the minimum number of steps (distance from beginWord) it takes to reach it.
    queue<pair<string, int>> q; // word, steps to create that word
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        for (int i = 0; i < wordList.size(); i++) {
            words.insert(wordList[i]);
        }
        if (!words.count(endWord)) //there's no way to reach it
            return ans;
        q.push({beginWord, 1});
        mp[beginWord] = 1;
        if (words.find(beginWord) != words.end()) {
            words.erase(beginWord); //remove it to avoid revisiting.
        }
        while (!q.empty()) {
            int sz = q.size(); //the current BFS level
            unordered_set<string> visitedThisLevel; //keeps track of all words visited in this BFS level to avoid deleting prematurely.
            while (sz--) {
                string word = q.front().first;
                int steps = q.front().second;
                q.pop();
                string temp = word;
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c; //For each position i in the word, try replacing it with every lowercase letter from 'a' to 'z'
                        if (words.count(word) && !mp.count(word)) {
                            q.push({word, steps + 1});
                            mp[word] = steps + 1;
                            visitedThisLevel.insert(word); //Track it to erase after the level ends.
                        }
                    }
                    word[i] = original;
                }
            }
            for (auto w : visitedThisLevel) //Only after the whole level is processed, erase visited words to prevent longer paths from overwriting correct shorter paths.
                words.erase(w);
        }
        if (mp.find(endWord) != mp.end()) 
        { //Now we want to find all paths from beginWord to endWord that use only these 5 steps. we start DFS from endWord (like going backward from destination to start).
            vector<string> ans1 = {endWord}; // the path being built.
            dfs(ans1, ans, endWord, beginWord);
        }
        return ans;
    }
    void dfs(vector<string>& ans1, vector<vector<string>>& ans, string endWord, string& beginWord) 
    { 
      if (endWord == beginWord) { //When we finally reach beginWord
            reverse(ans1.begin(), ans1.end());
            ans.push_back(ans1);
            reverse(ans1.begin(), ans1.end());
            return;
        }
        int steps = mp[endWord];
        string temp = endWord;
        for (int i = 0; i < endWord.size(); i++) {
            char original = temp[i];
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c; //try changing each character of endWord
                if (mp.find(temp) != mp.end() && mp[temp] + 1 == steps) 
                { //if prev comes just before endWord in a shortest path.
                    ans1.push_back(temp);
                    dfs(ans1, ans, temp, beginWord);
                    ans1.pop_back(); //backtrack
                }
            }
            temp[i] = original;
        }
    }
};
