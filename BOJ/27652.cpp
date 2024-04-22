#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

struct Node {
    int count;
    array<Node *, 26> children;
};

int nodeCnt = 0;
vector<Node> nodes(999002);
Node *A, *B;
map<string, unordered_map<string, Node *> > cache;

Node *createNode() {
    return &nodes[nodeCnt++];
}

void init() {
    A = createNode();
    B = createNode();
}

void add(const string &target, const string &S) {
    Node *curNode = target == "A" ? A : B;

    for (int i = 0; i < static_cast<const int>(S.size()); i++) {
        const int ch = S[i] - 'a';

        if (!curNode->children[ch]) {
            curNode->children[ch] = createNode();
        }

        curNode = curNode->children[ch];
        curNode->count++;
        cache[target][S.substr(0, i + 1)] = curNode;
    }
}

void del(Node *curNode, const string &S) {
    for (char ch: S) {
        ch -= 'a';
        curNode = curNode->children[ch];
        curNode->count--;
    }
}

int find(const string &target, const string &S) {
    if (!cache[target].contains(S)) return 0;

    return cache[target][S]->count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int Q;
    cin >> Q;

    while (Q--) {
        string command;
        cin >> command;

        if (command == "add") {
            string target, S;
            cin >> target >> S;

            if (target == "B") {
                ranges::reverse(S);
            }

            add(target, S);
            continue;
        }

        if (command == "delete") {
            string target, S;
            cin >> target >> S;

            if (target == "A") {
                del(A, S);
                continue;
            }

            if (target == "B") {
                ranges::reverse(S);
                del(B, S);
            }

            continue;
        }

        if (command == "find") {
            int count = 0;

            string S;
            cin >> S;

            for (int i = 1; i < static_cast<const int>(S.size()); i++) {
                string prefix = S.substr(0, i);
                string suffix = S.substr(i);
                ranges::reverse(suffix);
                count += find("A", prefix) * find("B", suffix);
            }

            cout << count << '\n';
        }
    }

    return 0;
}
