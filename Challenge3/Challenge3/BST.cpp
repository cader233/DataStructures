#include "BST.h"
#include <iostream>  
using namespace std;

int Node::degree() const 
{
    int deg = 0;
    if (left) deg++;
    if (right) deg++;
    return deg;
}

void BST::dup(Node* node) 
{
    if (node == nullptr) 
    {
        return;
    }

    insert(node->data);
    dup(node->left);
    dup(node->right);

} 

bool BST::insert(Node*& node, int val) 
{
    if (node == nullptr) 
    {
        node = new Node(val);
        return true;
    }

    if (val < node->data) 
    {
        return insert(node->left, val);
    }

    if (val > node->data)
    {
        return insert(node->right, val);
    }

    return false;
}

bool BST::remove(Node*& node, int val) 
{
    if (node == nullptr) 
    {
        return false;
    }

    if (val < node->data) 
    {
        return remove(node->left, val);
    }

    if (val > node->data) 
    {
        return remove(node->right, val);
    }


    int deg = node->degree();
    Node* temp = node->left;

    switch (deg)
    {
    case 0:
        delete node;
        node = nullptr;
        break;
    case 1:
        if (node->right)
        {
            temp = node->right;
        }
        delete node;
        node = temp;
        break;
    case 2:
        while (temp->right)
        {
            temp = temp->right;
        }
        node->data = temp->data;
        remove(node->left, node->data);
        break;
    }
    return true;
}

bool BST::find(Node* node, int val) 
{
    if (node == nullptr) 
    {
        return false;
    }

    if (val < node->data) 
    {
        return find(node->left, val);
    }

    if (val > node->data)
    {
        return find(node->right, val);
    }

    return true;
}

void BST::inorder(Node* node, std::ostream& os) 
{

    if (node == nullptr)
    {
        return;
    }

    if (node == root)
    {
        os << "inOrder: ";
    }

    inorder(node->left, os);   // L
    os << node->data << " ";   // N
    inorder(node->right, os);  // R

    if (node == root)
    {
        os << endl;
    }
}

void BST::preorder(Node* node, std::ostream& os) 
{
    if (node == nullptr)
    {
            return;
    }

    if (node == root)
    {
        os << "preOrder: ";
    }

    os << node->data << " ";    // N
    preorder(node->left, os);   // L
    preorder(node->right, os);  // R

    if (node == root)
    {
        os << endl;
    }
}

void BST::postorder(Node* node, std::ostream& os)
{
    if (node == nullptr) 
    {
        return;
    }

    if (node == root)
    {
        os << "postOrder: ";
    }

    postorder(node->left, os);  // L
    postorder(node->right, os); // R
    os << node->data << " ";    // N

    if (node == root)
    {
        os << endl;
    }
}