#ifndef CONFEDERATION_CPP_AVLTREE_H
#define CONFEDERATION_CPP_AVLTREE_H
#include <iostream>

template <typename t>
struct Node {
    t data;
    int height;
    Node *left;
    Node *right;
};

template <typename t>
class AVLTree {
public:
    AVLTree() : root(nullptr) {}

    void Insert(const t& data) {
        root = Insert(root, data);
    }

    void Remove(const t& data) {
        root = Remove(root, data);
    }

    t* Search(const std::string& data) {
        return Search(root, data);
    }


    void PrintInorder() {
        PrintInorder(root);
        std::cout << std::endl;
    }

    Node<t> *root;

    int GetHeight(Node<t> *node) {
        return node ? node->height : 0;
    }

    int GetBalanceFactor(Node<t> *node) {
        return GetHeight(node->right) - GetHeight(node->left);
    }

    void UpdateHeight(Node<t> *node) {
        node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
    }

    Node<t> *RotateRight(Node<t> *node) {
        Node<t> *left = node->left;
        node->left = left->right;
        left->right = node;
        UpdateHeight(node);
        UpdateHeight(left);
        return left;
    }

    Node<t> *RotateLeft(Node<t> *node) {
        Node<t> *right = node->right;
        node->right = right->left;
        right->left = node;
        UpdateHeight(node);
        UpdateHeight(right);
        return right;
    }

    Node<t> *Balance(Node<t> *node) {
        UpdateHeight(node);
        if (GetBalanceFactor(node) == 2) {
            if (GetBalanceFactor(node->right) < 0) {
                node->right = RotateRight(node->right);
            }
            return RotateLeft(node);
        }
        if (GetBalanceFactor(node) == -2) {
            if (GetBalanceFactor(node->left) > 0) {
                node->left = RotateLeft(node->left);
            }
            return RotateRight(node);
        }
        return node;
    }

    Node<t> *Insert(Node<t> *node,const t& data) {
        if (!node) {
            return new Node<t>{data, 1, nullptr, nullptr};
        }
        if (data < node->data) {
            node->left = Insert(node->left, data);
        } else {
            node->right = Insert(node->right, data);
        }
        return Balance(node);
    }

    Node<t> *FindMinNode(Node<t> *node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    Node<t> *RemoveMinNode(Node<t> *node) {
        if (!node->left) {
            return node->right;
        }
        node->left = RemoveMinNode(node->left);
        return Balance(node);
    }

    Node<t> *Remove(Node<t> *node, const t& data) {
        if (!node) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = Remove(node->left, data);
        } else if (data > node->data) {
            node->right = Remove(node->right, data);
        } else {
            Node<t> *left = node->left;
            Node<t> *right = node->right;
            delete node;
            if (!right) {
                return left;
            }
            Node<t> *minNode = FindMinNode(right);
            minNode->right = RemoveMinNode(right);
            minNode->left = left;
            return Balance(minNode);
        }
        return Balance(node);
    }

    t* Search(Node<t>* node, const std::string& name) {
        t results;
        if (!node) {
            return nullptr;
        }

        if (node->data == name) {
            return &node->data;
        } else if (node->data > name) {
            return Search(node->left, name);
        } else {
            return Search(node->right, name);
        }
    }

    void PrintInorder(Node<t>* node) {
        if (node) {
            PrintInorder(node->left);
            std::cout << node->data << " ";
            PrintInorder(node->right);
        }
    }


};


#endif
