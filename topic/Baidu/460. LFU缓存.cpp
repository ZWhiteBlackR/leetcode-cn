#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int value;
    int freq;
    Node(int k, int v, int f) : key(k), value(v), freq(f) {}
};
class LFUCache {
    int cap, minFreq;
    unordered_map<int, list<Node>::iterator> keys;
    unordered_map<int, list<Node>> freqs;
public:
    LFUCache(int capacity) {
        //哈希表
        cap = capacity;
        minFreq = 0;
        keys.clear();
        freqs.clear();
    }
    
    int get(int key) {
        if(cap == 0) return -1;
        auto it = keys.find(key);
        if(it == keys.end()) return -1;
        list<Node>::iterator p = it->second;
        int val = p->value, fre = p->freq;
        // 哈希表中移除
        freqs[fre].erase(p);
        if(freqs[fre].size() == 0){
            freqs.erase(fre);
            if(minFreq == fre) minFreq++;
        }
        freqs[fre + 1].push_front(Node(key, val, fre + 1));
        keys[key] = freqs[fre + 1].begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        auto it = keys.find(key);
        if(it == keys.end()){
            if(keys.size() == cap){
                auto p = freqs[minFreq].back();
                keys.erase(p.key);
                freqs[minFreq].pop_back();  
                if(freqs[minFreq].size() == 0) freqs.erase(minFreq);
            }
            freqs[1].push_front(Node(key, value, 1));
            keys[key] = freqs[1].begin();
            minFreq = 1;
        }else{
            list<Node>::iterator p = it->second;
            int fre = p->freq;
            freqs[fre].erase(p);
            if(freqs[fre].size() == 0){
                freqs.erase(fre);
                if(minFreq == fre) minFreq++;
            }
            freqs[fre + 1].push_front(Node(key, value, fre + 1));
            keys[key] = freqs[fre + 1].begin();
        }
    }
};