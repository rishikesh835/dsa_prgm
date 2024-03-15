#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;
class Node{
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;
    friend class Trie;
    public:
    Node(char d) {
        data = d;
        isTerminal = false;
    }
};
class Trie{
    Node *root;
    public:
    Trie() {
        root = new Node('\0');
    }
    //insertion
    void insert(string word){
        Node *temp = root;
        for(char ch : word) {
            if(temp->m.count(ch) == 0){
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    //searching
    bool search(string word) {
        Node *temp = root;
        for(char ch: word) {
            if(temp->m.count(ch) == 0) {
                return false;
            }
            temp = temp->m[ch];
        }
        return temp->isTerminal;
    }
};
int main(){
    string words[]= {"hello","he","apple","aple","news"};
    Trie t;

    for(auto word:words) {
        t.insert(word);
    }
    string key;
    cin>>key;
    cout<<t.search(key)<<endl;
    return 0;
}