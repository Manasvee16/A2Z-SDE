class LFUCache {
    int cap, minfreq;// cap = max capacity; minfreq = smallest frequency currently present
    unordered_map<int, pair<int, int>> mp; // key -> {value, freq}
    unordered_map<int, list<int>> frequency;// freq -> list of keys with this freq (list keeps LRU order within same freq)
    unordered_map<int, list<int>::iterator> mp1; // key -> iterator pointing to its position inside frequency[freq] list
public:
    LFUCache(int capacity) {
        cap = capacity; // set capacity
        minfreq = 0; // no keys yet, so min frequency is 0
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {  // If key exists in cache
            auto [val, freq] = mp[key]; // read current {value, freq}
            frequency[freq].erase(mp1[key]); // Remove key from its current frequency list in O(1) using the stored iterator
            mp[key].second++; // Increase the key's frequency
            frequency[freq + 1].push_front(key); // Add key to the front (MRU position) of the new frequency list
            mp1[key] = frequency[freq + 1].begin();  // Update iterator mapping to the new list position
            if (frequency[freq].empty() && freq == minfreq) {
                minfreq += 1; // If the old frequency list is now empty and it was the minfreq, bump minfreq
            }
            return val;  // return stored value
        }
        return -1; // Miss: key not present
    }
    void put(int key, int value) {
        if (cap == 0) 
          return;
        // If key already exists, update value and treat it like a get (to bump its freq)
        if (mp.find(key) != mp.end()) {
            mp[key].first = value; // update value
            get(key); // reuse get() to update frequency and recency
            return;
        }
        if (mp.size() == cap) {
            // minfreq holds the smallest frequency currently in cache. Evict the LRU key among that frequency bucket (the list's back).
            int lfu = frequency[minfreq].back();
            mp.erase(lfu); // remove from key->{value,freq}
            mp1.erase(lfu); // remove iterator mapping
            frequency[minfreq].pop_back();// remove from frequency list
        }
        mp[key] = {value, 1}; // store {value, freq=1}
        frequency[1].push_front(key); // add to freq=1 list at MRU position
        mp1[key] = frequency[1].begin(); // store iterator into the list
        minfreq = 1; // new min frequency becomes 1 (since a fresh key was added)
    }
};
//TC O(1)
//SC O(N)
