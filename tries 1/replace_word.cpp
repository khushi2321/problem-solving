struct Node{
   unordered_map<char, Node*> childs;
    string s = "";
};
class Trie{
    public :
       struct Node* root;
       Trie(){
           root = new Node();
       }
       
    void insert( string s ){
        struct Node* temp_root =root;
        for(auto it : s ){
            if(temp_root->childs.count(it)==0)
                temp_root->childs[it] = new Node();
            temp_root = temp_root->childs[it];
        }
        temp_root->s = s;
    } 
    string get_ans(string s ){
        struct Node* temp_root = root;
        int idx = 0 ;
        int n = s.length();
        string ans = "";
        while(idx < n ){
            if(temp_root->childs.count(s[idx])){
                temp_root = temp_root->childs[s[idx]];
                idx = idx + 1;
                if(temp_root->s != ""){
                    ans = temp_root->s;
                    return ans;
                }
            }
            else
                return s;
        }
        return s;
    }  
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
         Trie trie;
         for(auto it : dictionary)
             trie.insert(it);
        
        istringstream ss(sentence);
        string part;
        string ans;
        while(getline(ss, part, ' ')){
            ans += trie.get_ans(part);
            ans += " ";
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};