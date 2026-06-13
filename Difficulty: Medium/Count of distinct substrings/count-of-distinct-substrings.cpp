struct Node {
    Node* links[26];  
    // Array of pointers to child nodes,
    // each corresponding to a letter
    // of the alphabet
    bool flag = false;  
    // Flag indicating if the current
    // node represents the end of a substring

    // Method to check if a specific character key
    // exists in the children of the current node
    bool containsKey(char ch) {  
        // Check if the current node has a child node
        // corresponding to character 'ch'
        return (links[ch - 'a'] != NULL);
    }

    // Method to get the child node corresponding
    // to a specific character key
    Node* get(char ch) {  
        // Get the child node
        // corresponding to character 'ch'
        return links[ch - 'a'];
    }

    // Method to insert a new child
    // node with a specific character key
    void put(char ch, Node* node) {  
        // Insert a new child
        // node for character 'ch'
        links[ch - 'a'] = node;
    }

    // Method to mark the current
    // node as the end of a substring
    void setEnd() {  
        // Mark the current node
        // as the end of a substring
        flag = true;
    }

    // Method to check if the current
    // node marks the end of a substring
    bool isEnd() {  
        // Check if the current node
        // marks the end of a substring
        return flag;
    }
};
class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Node* root=new Node();
        int cnt=0;
        for(int i=0; i<s.length();i++){
            Node* node=root;
            for(int j=i; j<s.length(); j++){
                if(! node->containsKey(s[j])){
                    cnt++;
                    node->put(s[j],new Node());
                }
                node=node->get(s[j]);
            }
        }return cnt;
    }
};