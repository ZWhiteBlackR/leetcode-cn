#include<bits/stdc++.h>
using namespace std;


/*
 * 题目描述：最近最少使用算法
 * 设计和构建一个“最近最少使用”缓存，该缓存会删除最近最少使用的项目。缓存应该
 * 从键映射到值(允许你插入和检索特定键对应的值)，并在初始化时指定最大容量。当
 * 缓存被填满时，它应该删除最近最少使用的项目。

 * 它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正* 数），否则返回 -1。
 * 写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达* 到上限时，它应该在写入新数据之前删除最近最少使用的数据值，从而为新的数据值* 留出空间。
 */


/*
 * 解题思路：
 * 1. 用一个链表来记录每一个key-value
 * 2. 用一个哈希表来记录每一个key值的位置，用空间来换时间，可以在O(1)时间来* 找到每一个key的位置
 */
class LRUCache {
public:
    LRUCache(int capacity):capacity_(capacity) {

    }
    int get(int key) {
        if(!mp.count(key)){
            return -1;
        }
        mylist.splice(mylist.begin(),mylist,mp[key]);
        mp[key] = mylist.begin();
        return mylist.front().second;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            mylist.splice(mylist.begin(),mylist,mp[key]);
            mp[key] = mylist.begin();
            mylist.front().second = value;
            return ;
        }
        if(mylist.size() >= capacity_){
            mp.erase(mylist.back().first);
            mylist.pop_back();
        }
        mylist.push_front(make_pair(key,value));
        mp[key] = mylist.begin();
    }
private:
    int capacity_;
    list<pair<int,int>>mylist;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
};