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
    unsigned int counter = 0;

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
            counter++;
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
                        counter++;
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
                        counter++;
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

    Node<T> *FindMin(T node)
    {
        Node<T> *current = node;

        while (current->left != nullptr)
        {
            current = current->left;
        }
        return (current->data);
    }
    /*
    bool remove(T data)
    {
        Node<T> *newData = new Node<T>(data);
        if (root == nullptr)
            return false;

        else
        {
            if (data < root->data)
            {
                root->left = delete root->left;
            }
            else if (data > root->data)
            {
                root->right = delete root->right;
            }
            else
            {
                if (root->left == nullptr && root->right == nullptr)
                {
                    delete root;
                    counter--;
                    root = nullptr;
                    return true;
                }
                else if (root->left == nullptr)
                {
                    Node<T> *temp = root;
                    root = root->right;
                    counter--;
                    delete temp;
                    return true;
                }
                else if (root->right == nullptr)
                {
                    Node<T> *temp = root;
                    root = root->left;
                    counter--;
                    delete temp;
                    return true;
                }
                else
                {
                    Node<T> *temp = FindMin(root->right);
                    root->data = temp->data;
                    root->right = delete temp->data;
                }
            }
            return root;
        }
    }*/
    unsigned int size()
    {
        //cout << counter << " ";
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

            printPostorder(root);
        }
    }

    Iterator<T> begin()
    {
        return Iterator<T>(root);
    }

    Iterator<T> end()
    {
        return Iterator<T>(root);
    }
    /*
    ~BSTree() {
            // TODO
         }*/
};

#endif
