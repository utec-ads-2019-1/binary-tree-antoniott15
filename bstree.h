#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"
#include <iostream>
using namespace std;
template <typename T>
class BSTree
{
private:
    Node<T> *root;
    int counter;

public:
    BSTree() : root(nullptr){};

    bool find(T data)
    {
        Node<T> *temp = root;
        if (root == nullptr)
        {
            return false;
        }
        while (temp)
        {
            if (temp->data == data)
            {
                return true;
            }
            else if (temp->data > data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return true;
    }

    bool insert(T data)
    {
        Node<T> *newData = new Node<T>(data);
        if (!root)
        {
            root = newData;
            return true;
        }
        else
        {
            Node<T> *temp = root;
            while (!(temp->data == data))
            {

                if (data < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newData;
                        return true;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }

                else if (data > temp->data)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newData;
                        return true;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }

            return false;
        }
    }
    /*
  bool remove(T data)
    {


    }
*/
    unsigned int size()
    {
        cout << counter;
        return counter;
    }
    /*
    void printPreorder(Node<T> *nodo)
    {
        cout << nodo->data << " ";
        if (nodo->left)
        {
            print_preorder(nodo->left);
        }

        if (nodo->right)
        {
            print_preorder(nodo->right);
        }
    }
    void traversePreOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl
                 << "Preorder: ";
            printPreorder(root);
        }
    }
    void printInorder(Node<T> *nodo)
    {
        if (nodo->left)
        {
            print_inorder(nodo->left);
        }

        cout << nodo->data << " ";

        if (nodo->right)
        {
            print_inorder(nodo->right);
        }
    }
    void traverseInOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl
                 << "Inorder: ";
            printInorder(root);
        }
    }
    void printPostorder(Node<T> *nodo)
    {
        if (nodo->left)
        {
            print_postorder(nodo->left);
        }

        if (nodo->right)
        {
            print_postorder(nodo->right);
        }

        cout << nodo->data << " ";
    }

    void traversePostOrder()
    {
        if (!root)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl
                 << "Postorder: ";
            printPostorder(root);
        }
    }

    Iterator<T> begin()
    {
        Node<T> *curr = root;
        while (curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    Iterator<T> end()
    {
        Node<T> *curr = root;
        while (curr->right)
        {
            curr = curr->right;
        }
        return curr;
    }

    ~BSTree() {
            // TODO
         }*/
};

#endif
