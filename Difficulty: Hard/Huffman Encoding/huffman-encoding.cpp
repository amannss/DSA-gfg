class node {
public:
    int data, idx;
    node* left;
    node* right;

    node(int d, int i) {
        data = d;
        idx = i;
        left = NULL;
        right = NULL;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        if (a->data == b->data) {
            return a->idx > b->idx;
        }
        return a->data > b->data;
    }
};

void solve(vector<string>& ans, string s, node* head) {
    if (!head) return;

    // leaf node
    if (!head->left && !head->right) {
        if (s == "") s = "0";
        ans.push_back(s);
        return;
    }

    solve(ans, s + '0', head->left);
    solve(ans, s + '1', head->right);
}

class Solution {
public:
    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = f.size();

        priority_queue<node*, vector<node*>, compare> pq;

        for (int i = 0; i < n; i++) {
            pq.push(new node(f[i], i));
        }

        while (pq.size() > 1) {
            node* left = pq.top(); pq.pop();
            node* right = pq.top(); pq.pop();

            node* newNode = new node(left->data + right->data,
                                     min(left->idx, right->idx));

            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        node* head = pq.top();

        vector<string> ans;
        string temp = "";

        solve(ans, temp, head);

        return ans;
    }
};