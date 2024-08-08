#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void dfs(Node* copy, const vector<Node*>& nodes, map<Node*,Node*>& h) {
    if (nodes.empty()) return;

    Node* curr;
    for (int i = 0; i < nodes.size(); i++) {
        auto it = h.find(nodes[i]);
        if (it == h.end()) {
            Node* root = new Node(nodes[i]->val);
            h[nodes[i]] = root;
            copy->neighbors.push_back(root);
            if (!nodes[i]->neighbors.empty()) {
                dfs(root, nodes[i]->neighbors, h);
            }
        } else {
            copy->neighbors.push_back(it->second);
        }
    }
    return;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node) {
            Node* root = new Node(node->val);
            map<Node*,Node*> h = {{node, root}};
            dfs(root, node->neighbors, h);
            return root;
        }
        return nullptr;
    }
};