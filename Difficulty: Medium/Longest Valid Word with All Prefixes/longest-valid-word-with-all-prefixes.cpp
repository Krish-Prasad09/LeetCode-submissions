struct Node{
    Node* links[26];
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0; i<word.length();i++){
            if(! node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
};

class Solution {
    public:
    bool checkifPrefixExists(string word,Trie &trie){
        bool f1=true;
        Node* node=trie.root;
        for(int i=0; i<word.length();i++){
            if(node->containsKey(word[i])){
                node=node->get(word[i]);
                if(node->isEnd()==false) return false;
            }
            else return false;
        }
        return true;
    }
    string longestValidWord(vector<string>& words) {
        // code here
        int n=words.size();
        Trie trie;
        for(auto &it:words){
            trie.insert(it);
        }
        string longest="";
        for(auto &it:words){
            if(checkifPrefixExists(it,trie)){
            if(it.length() > longest.length())
                longest = it;
            else if(it.length() == longest.length() && it < longest)
                longest = it;
            }
        }
        return longest;
    }
};
