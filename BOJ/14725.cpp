#include <iostream>
#include <map>

using namespace std;

struct Tree {
    struct Node {
        map<string, Node *> children;

        Node *getOrCreate(string &name) {
            if (children.contains(name)) return children[name];
            return children[name] = new Node();
        }
    };

    void print(Node *cur, int depth = 0) {
        for (auto [k, v]: cur->children) {
            for (int i = 0; i < depth; i++) {
                cout << "--";
            }
            cout << k << '\n';
            print(v, depth + 1);
        }
    }

    Node *root = new Node;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    Tree *tree = new Tree();

    while (N--) {
        int K;
        cin >> K;

        Tree::Node *cur = tree->root;

        while (K--) {
            string t;
            cin >> t;
            cur = cur->getOrCreate(t);
        }
    }

    tree->print(tree->root);

    return 0;
}
