// https://leetcode.com/problems/implement-trie-prefix-tree/description/

// Approach: First was my own, but brute force using map and stuff
//         : Second was by striver -> optimal using trie data structure (which we define ourself, having links and boolean flag)
          
// Approach1:

class Trie {
public:
    map<string, bool> mpp;
    Trie() {
        
    }
    
    void insert(string word) {
        mpp[word] = true;
    }
    
    bool search(string word) {
        if(mpp.find(word) != mpp.end()) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        for(auto it: mpp){
            string temp = it.first;
            int i=0, j=0;
            int n=temp.length(), m=prefix.length();
            while(i<n && j<m){
                if(temp[i] != prefix[j]){
                    break;
                }
                else{
                    i++, j++;
                }
            }

            if(i==n && j==m) return true;
            else if(i<n && j==m) return true;
        }
        return false;
    }
};

// Approach2:

struct Node {
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch){
        return (links[ch-'a'] != nullptr);
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    //tc: O(Word Length)
    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            } 

            //moves to the reference node
            node = node->get(word[i]);    
        }
        // now standing at last reference guy
        node->setEnd();
    }
    
    //TC: O(word Len)
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return (node->isEnd() == true);
    }
    
    // TC: O(Prefix Len)
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        //now no need to check for flag's value as if loop ends that means poori string matched hi hai
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
