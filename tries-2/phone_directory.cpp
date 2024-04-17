class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data=ch;
            for(int i=0; i<26; i++) children[i]=NULL;
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode* root= new TrieNode('@');

        void insertUtil(TrieNode *root, string word, int i){
            if(i==word.size()){
                root->isTerminal=true;
                return;
            }

            int index=word[i]-'a';
            TrieNode *newroot;
            if(root->children[index]){
                newroot=root->children[index];
            }
            else{
                newroot=new TrieNode(word[i]);
                root->children[index]=newroot;
            }

            insertUtil(newroot, word, i+1);
        }

        void insertWord(string word){
            insertUtil(root, word, 0);
        }

};
class Solution{
public:
    void solve(TrieNode *root, vector<vector<string>> &ans, string &temp, int i){
        if(root->isTerminal) {
            ans[i].push_back(temp);
        }    
        
        for(int j=0; j<26; j++){
            if(root->children[j]){
                temp.push_back(root->children[j]->data);
                solve(root->children[j], ans, temp, i);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> displayContacts(int n, string contactList[], string str)
    {
        vector<vector<string>> ans(str.size());
        
        Trie t;
        for(int i=0; i<n; i++) t.insertWord(contactList[i]);
        
        TrieNode *root=t.root;
        string temp="";
        for(int i=0; i<str.size(); i++){
            temp.push_back(str[i]);
            if(root->children[str[i]-'a']){
                root=root->children[str[i]-'a'];
                solve(root, ans, temp, i);
            }
            else{
                while(i<str.size()) ans[i++].push_back("0");
                break;
            }
        }
        return ans;
    }
};