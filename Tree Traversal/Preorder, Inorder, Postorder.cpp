#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *right;
    Node *left;
};

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}
Node *Insert(Node *root, char data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root = Insert(root, 'E');
    root = Insert(root, 'R');
    root = Insert(root, 'U');
    root = Insert(root, 'M');
//    root = Insert(root, 'C');
//    root = Insert(root, 'Z');
    cout << "Pre-order: ";
    Preorder(root);
    cout << endl;
    cout << "In-order: ";
    Inorder(root);
    cout << endl;
    cout << "Post-order: ";
    Postorder(root);
    cout << endl;
}
