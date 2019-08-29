#include<stdio.h>
#include<iostream>
#include <fstream>
#include<string>
#include<ctype.h>
#include<stdlib.h>
#include<map>
#include<list>
using namespace::std;

class LRUCache {
int _unsync_stdio = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
	}();
public:
    LRUCache(int capacity) {
        this->cache = map<int, list<pair<int, int>>::iterator>();
        this->linkedlist = list<pair<int, int>>();
        this->cap = capacity;
    }
    int get(int key) {
        //cout<<key<<endl;
        auto it = cache.find(key);
        if(it != cache.end()){
            linkedlist.splice(linkedlist.begin(), linkedlist, it->second);
            return it->second->second;
        } else return -1;
    }
    
    void put(int key, int value) {
        //cout<<key<<" "<<value<<endl;
        auto it = cache.find(key);
        if(it != cache.end())
            linkedlist.erase(it->second);
        linkedlist.push_front({key, value});
        cache[key] = linkedlist.begin();
        if(cache.size() > cap){
            int key_recent = linkedlist.back().first;
            cache.erase(key_recent);
            linkedlist.pop_back();
        }
    }
private:
    map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> linkedlist;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 int main(){
 	int cap = 0;
 	cout<<"input the capacity of LRU: ";
 	cin>>cap;
 	LRUCache* obj = new LRUCache(cap);
 	cout<<"input operations, one integer for get and two integers for put. "<<endl;
 	while(true){
 		int op1 = 0;
 		cin>>op1;
 		if(cin.get() != '\n'){
 			int op2 = 0;
 			cin>>op2;
 			obj->put(op1, op2);
 			cout<<"put successfully. "<<endl;
		 } else{
		 	int res = obj->get(op1);
		 	if(res == -1) cout<<"get nothing"<<endl;
		 	else cout<<"get "<<res<<endl;
		 }
	 }
 }
