struct Node {
    Node* links[26] = {nullptr};
    int prefs = 0, ends = 0;
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!node->links[idx]) {
                node->links[idx] = new Node();
            }
            node = node->links[idx];
            node->prefs++;
        }
        node->ends++;
    }

    vector<string> find(const string& prefix) {
        vector<string> ans;
        Node* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->links[idx]) return ans;
            node = node->links[idx];
        }
        dfs(node, prefix, ans);
        return ans;
    }

private:
    void dfs(Node* node, string path, vector<string>& res) {
        if (res.size() >= 3) return;
        if (node->ends > 0) res.push_back(path);

        for (int i = 0; i < 26; ++i) {
            if (node->links[i]) {
                dfs(node->links[i], path + char('a' + i), res);
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for (const auto& p : products) {
            t.insert(p);
        }

        vector<vector<string>> ans;
        string prefix;
        for (char c : searchWord) {
            prefix += c;
            ans.push_back(t.find(prefix));
        }
        return ans;
    }
};