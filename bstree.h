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

    bool find(T value)
    {
        Node<T> *temp = root;
        if (!root)
            return false;

        while (temp)
        {
            if (temp->data == value)
                return true;
            else if (temp->data > value)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    bool insert(T value)
    {
        Node<T> *new_node = new Node<T>;
        new_node->data = value;
        if (find(value))
            return false;
        else if (!root)
        {
            root = new_node;
        }
        else
        {
            Node<T> *temp = root;
            while (!(temp->value == value))
            {

                if (value < temp->value)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = new_node;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }

                else if (value > temp->value)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = new_node;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
        counter++;
        return true;
    }

    /*  bool remove(T value)
    {


    }
*/
    unsigned int size()
    {
        return counter;
    }

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
        return current;
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

    /*~BSTree() {
            // TODO
         }*/
};

#endif
