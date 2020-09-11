#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return root;
        Node* pre = nullptr;
        treeToDoubleList(root,pre);
        Node* head = pre;
        while(head != nullptr && head->left != nullptr){
            head = head->left;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
    void treeToDoubleList(Node* root,Node*& pre){
        if(root == nullptr)
            return ;
        treeToDoubleList(root->left,pre);
        root->left = pre;
        if(pre != nullptr)
            pre->right = root;
        pre = root;
        treeToDoubleList(root->right,pre);
    }
};