#include <iostream>

struct Node {
    int val;                           
    Node* l;
    Node* r;

    Node() : Node(0) {}
    Node(int val) : val(val), l(nullptr), r(nullptr) {}
    ~Node() { delete l, delete r; }
};                    

void push(int val, Node*& node) {
    if (node == nullptr)
    {
        node = new Node(val);
        return;
    }

    if (val > node->val) push(val, node->r);
    else push(val, node->l);
}


void print(Node* t, int u = 0) {
    if (t == nullptr) return;
    else {
        print(t->l, ++u);
        for (int i = 0; i < u; ++i) std::cout << "|";
        std::cout << t->val << std::endl;
        u--;
    }
    print(t->r, ++u);
}

Node* findComPar(Node* root, int fst, int scd) {
    if (root == nullptr) return nullptr;
    if (root->val > fst && root->val > scd) return findComPar(root->l, fst, scd);
    if (root->val < fst && root->val < scd) return findComPar(root->r, fst, scd);
    return root;
}

int main() {
    Node* tree = nullptr;

    int treeSize = 7;
    int inputArr[] = { 5, 3, 8, 2, 4, 7, 9 };
    for (int i = 0; i < treeSize; i++) push(inputArr[i], tree);

    std::cout << "Your tree: \n";
    print(tree);
    std::cout << std::endl;

    std::cout << findComPar(tree, 3, 7)->val << " is the least common parent of 3 and 7" << std::endl;
    std::cout << findComPar(tree, 7, 9)->val << " is the least common parent of 7 and 9" << std::endl;
}
