typedef struct TrieNode {
    TrieNode* children[26];
    TrieNode* space;
    bool end;
    TrieNode() {
        for(int i = 0; i < 26; i++) children[i] = NULL;
        space = NULL;
        end = false;
    }
}TrieNode;

void insert(TrieNode* root, string &str) {
    TrieNode *node = root;
    for(char c : str) {
        if(c == ' ') {
            if(node->space == NULL) node->space = new TrieNode();
            node = node->space;
        }
        else {
            if(node->children[c - 'a'] == NULL) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
    }
    node->end = true;
}

less<string> strless;
greater<int> intgreater;

struct cmp {
    bool operator()(pair<int, string> &a, pair<int, string> &b) {
        if(a.first == b.first) {
            return a.second.compare(b.second) < 0;
        }
        return intgreater(a.first, b.first);
    }
};

priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
// priority_queue<pair<int, string>> pq;

void getTops(TrieNode *root, unordered_map<string, int> &freq, string builder) {
    if(root->end) {
        pq.push({freq[builder], builder});
        if(pq.size() > 3) pq.pop();
    }
    for(int i = 0; i < 26; i++) {
        if(root->children[i] != NULL) {
            getTops(root->children[i], freq, builder + (char)(i + 'a'));
        }
    }
    if(root->space != NULL) {
        getTops(root->space, freq, builder + ' ');
    }
}


class AutoCompleteSystem {
public:
    TrieNode *root, *node;
    string str;
    unordered_map<string, int> freq;
    bool isNull;
    
    AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        node = root;
        str = "";
        isNull = false;
        int n = times.size();
        for(int i = 0; i < n; i++) {
            insert(root, sentences[i]);
            freq[sentences[i]] = times[i];
        }
    }
    
    vector<string> input(char c) {
        str.push_back(c);
        if(c == '#') {
            str.pop_back();
            insert(root, str);
            freq[str]++;
            node = root;
            str = "";
            isNull = false;
            return {};
        }
        else if(isNull) {
            return {};
        }
        else if(c != ' ') {
            if(node->children[c - 'a'] == NULL) {
                isNull = true;
                return {};
            }
            node = node->children[c - 'a'];
        }
        else {
            if(node->space == NULL) {
                isNull = true;
                return {};
            }
            node = node->space;
        }
        getTops(node, freq, str);
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
