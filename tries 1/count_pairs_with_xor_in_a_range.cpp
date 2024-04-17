class Solution {
private:    
    const int level = 16; 
public:
    struct TrieNode {
        int count;
        TrieNode* child[2];

        TrieNode() {
            count = 0;
            child[0] = nullptr;
            child[1] = nullptr;
        }
    };
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (int num: nums) {
            ans += countPairs(root, num, high + 1) - countPairs(root, num, low);
            insertInTrie(root, num);
        }
        return ans;
    }

    int countPairs(TrieNode* root, int num, int k) {
        int res = 0;

        for (int i = level; i >= 0; --i) {
            bool kbit = (k) & (1 << i);
            bool bit = (num) & (1 << i);

            if (kbit) {
                if (bit) {
                    if (root->child[bit] != nullptr) {
                        res += root->child[bit]->count;
                    }

                    if (root->child[bit - 1] != nullptr) {
                        root = root->child[bit - 1];
                    } else {
                        return res;
                    }
                } else {
                    if (root->child[bit] != nullptr) {
                        res += root->child[bit]->count;
                    }

                    if (root->child[1] != nullptr) {
                        root = root->child[1];
                    } else {
                        return res;
                    }
                }
            } else {
                if (root->child[bit] != nullptr) {
                    root = root->child[bit];
                } else {
                    return res;
                }
            }
        }

        return res;
    }
    void insertInTrie(TrieNode* root, int num) {
        for (int i = level; i >= 0; --i) {
            bool childBit = (num) & (1 << i);
            if (!root->child[childBit]) {
                root->child[childBit] = new TrieNode();
            }

            root = root->child[childBit];
            root->count++;
        }
    }
};