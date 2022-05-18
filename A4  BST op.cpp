#include <iostream>
using namespace std;
class BTNODE
{
    int data;
    BTNODE *left;
    BTNODE *right;

public:
    BTNODE()
    {
        left = right = NULL;
        data = -1;
    }
    friend class BST;
};
class BST
{
    BTNODE *root;
    BST()
    {
        root = NULL;
    }
    void create();
    void inorder(BTNODE *);
    void insert(BTNODE *);
    BTNODE *mirror(BTNODE *T);
    int height(BTNODE *);
    void minvalue(BTNODE *);
    void maxvalue(BTNODE *);
    BTNODE *search(BTNODE *T, int key)
    {
        while (T != NULL)
        {
            if (T->data == key)
                return T;
            if (key < T->data)
                T = T->left;
            else
                T = T->right;
        }
        return NULL;
    }
    friend int main();
};
void BST::minvalue(BTNODE *T)
{
    while (T->left != NULL)
    {
        T = T->left;
    }
    cout << T->data;
}
int BST::height(BTNODE *T)
{
    int hl, hr;
    if (T == NULL)
    {
        return 0;
    }
    if (T->left == NULL && T->right == NULL)
    {
        return 0;
    }
    hl = height(T->left);
    hr = height(T->right);
    if (hl > hr)
    {
        return hl + 1;
    }
    else
    {
        return (hr + 1);
    }
}
void BST::maxvalue(BTNODE *T)
{
    while (T->right != NULL)
    {
        T = T->right;
    }
    cout << T->data;
}
void BST::create()
{
    char ch;
    do
    {
        BTNODE *p = new BTNODE();
        cout << "Enter data " << endl;
        cin >> p->data;
        if (search(root, p->data) == NULL)
        {
            insert(p);
        }
        else
            cout << " The element is already exist" << endl;
        cout << " If u want to continue if yes press'y' or 'Y'" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
BTNODE *BST::mirror(BTNODE *T)
{
    BTNODE *p;
    if (T == NULL)
        return NULL;
    if (T != NULL)
    {
        p = new BTNODE;
        p->data = T->data;
        p->left = mirror(T->right);
        p->right = mirror(T->left);
    }
    return p;
}
void BST::insert(BTNODE *p)
{
    BTNODE *T;
    if (root == NULL)
        root = p;
    else
    {
        T = root;
        while (1)
        {
            if (p->data < T->data)
            {
                if (T->left == NULL)
                {
                    T->left = p;
                    break;
                }
                else
                    T = T->left;
            }
            else
            {
                if (p->data > T->data)
                {
                    if (T->right == NULL)
                    {
                        T->right = p;
                        break;
                    }
                    else
                        T = T->right;
                }
            }
        }
    }
}
void BST::inorder(BTNODE *T)
{
    if (T != NULL)
    {
        inorder(T->left);
        cout << " " << T->data;
        inorder(T->right);
    }
}
int main()
{
    BST o, o1;
    int choice, T;
    do
    {
        cout << " 1.Create" << endl;
        cout << " 2.To find minimum value" << endl;
        cout << " 3.To find maximum value" << endl;
        cout << " 4.Mirror the tree" << endl;
        cout << " 5.Find the no. of nodes in longest path" << endl;
        cout << " Enter your choice " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            o.create();
            cout << " The inorder of tree is:" << endl;
            o.inorder(o.root);
            break;
        case 2:
            cout << " The minimum value = " << endl;
            o.minvalue(o.root);
            break;
        case 3:
            cout << "The maximum value = " << endl;
            o.maxvalue(o.root);
            break;
        case 4:
            o1.root = o.mirror(o.root);
            cout << " The inorder of mirror tree is:" << endl;
            o1.inorder(o1.root);
            break;
        case 5:
            T = o.height(o.root);
            cout << " Longest no of nodes=" << T + 1 << endl;
            break;
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}
