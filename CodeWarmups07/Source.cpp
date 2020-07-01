#include <cstddef>
#include <iostream>
#define COUNT 10
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {}
};
void PrintTree(Node* root, int space)
{
    // TODO: print all nodes in the tree
    if (root == NULL)
        return;
    // Increase distance more of a visual thing
    space += COUNT;

    //Process the right child first  
    PrintTree(root->right, space);

    //Print current node after space
    //count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->data << "\n";

    //Process left child
    PrintTree(root->left, space);
    //whew
}
void DeleteTree(Node* root)
{
    // TODO: delete all nodes in the tree
    if (root == NULL) return;
    /* first delete both subtree*/
    DeleteTree(root->left);
    DeleteTree(root->right);
    /* then */
    std::cout << "\n Deleting Node : " << root->data;
    delete root;
}
int main(int argc, char** argv)
{
    /************************
               50
       20             70
     10   30        60  80
    ************************/
    Node* root = new Node(50,
        new Node(20, new Node(10), new Node(30)),
        new Node(70, new Node(60), new Node(80))
    );
    PrintTree(root, 0);
    // pre - 50, 20, 10, 30, 70, 60, 80
    // post - 10, 30, 20, 60, 80, 70, 50
    DeleteTree(root);
    return 0;
}