#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator
{
private:
    Node<T> *current;

public:
    /*  Iterator()
    {
        // TODO
    }

    Iterator(Node<T> *node)
    {
        // TODO
    }

    Iterator<T> operator=(Iterator<T> other)
    {
        // TODO
    }

    bool operator!=(Iterator<T> other)
    {
        // TODO
    }

     Iterator<T> operator++(Iterator *nodo)
    {
        if (nodo->left)
        {
            return nodo->left;
        }
        else if (nodo->right)
        {
            return nodo->right;
        }
        else if (nodo->left == nullptr && nodo->right == nullptr)
        {
            return nullptr;
        }
    }

    Iterator<T> operator--()
    {
        // TODO
    }

    T operator*()
    {
        // TODO
    }*/
};

#endif
