#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include <iostream>
#include "BNode.h"
using namespace std;

template <class T>
class BinaryTree {
    
    BNode<T> * root = NULL;
    
    std::ostream& print(std::ostream& os, BNode<T> * node);
    
public:
    BinaryTree();
    BinaryTree(BNode<T> * info);
    
    ~BinaryTree();
    
    void reflect();
    void reflect(BNode<T> * node);
    
    bool validateSymmetry();
    bool validateSymmetry(BNode<T> * nodeOne, BNode<T> * nodeTwo);
    
    void clear();
    void clear(BNode<T> * node);
    
    bool empty();
    BNode<T> * getRoot();
    
    bool insert(T value, BNode<T> * parent);
    bool insert(T value, T parent);
    
    void preOrden();
    void preOrden(BNode<T> * node);
    
    void inOrden();
    void inOrden(BNode<T> * node);
    
    void postOrden();
    void postOrden(BNode<T> * node);
    
    template <typename Tn>
    friend std::ostream& operator<<(std::ostream& os, BinaryTree<Tn> &arbol);
    
    int level(BNode<T> * node);
    
    BNode<T> * inefficientSum();
    BNode<T> * inefficientSum(BNode<T> * node);
    T sum();
    T efficientSum(BNode<T> * node);
    void efficientSum(BNode<T> * node, BNode<T> * acumulator);
    T sum(BNode<T> * node);
    
    
    BNode<T> * getParent(T info);
    BNode<T> * getParent(T info, BNode<T> * node);
    
    bool validateSiblings(T node, T n2);
    bool validateSiblings(BNode<T> * node, BNode<T> * n2);
    
    void siblings(BNode<T> * node);
    void ancestors(BNode<T> * node);
    void cousins(BNode<T> * node, BNode<T> * root);
    
    BNode<T> * search (T info);
    BNode<T> * search (T info, BNode<T> * node);
};

template <class T>
BinaryTree<T>::BinaryTree() { }

template <class T>
BinaryTree<T>::BinaryTree(BNode<T> * info) {
    root = info;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
    clear(root);
}

template <class T>
void BinaryTree<T>::reflect() {
    reflect(root);
}

template <class T>
void BinaryTree<T>::reflect(BNode<T> *node)
{
    if (node) {
        BNode<T> *aux = node->getLeft();
        node->setLeft(node->getRight());
        node->setRight(aux);
        reflect(node->getLeft());
        reflect(node->getRight());
    }
}

template <class T>
bool BinaryTree<T>::validateSymmetry()
{
    return validateSymmetry(root, root);
}

template <class T>
bool BinaryTree<T>::validateSymmetry(BNode<T> * nodeOne, BNode<T> * nodeTwo)
{
    if (nodeOne == root && nodeTwo == root)
    {
        if (nodeOne->getLeft() && nodeOne->getRight())
        {
            nodeOne = nodeOne->getLeft();
            nodeTwo = nodeTwo->getRight();
        }
        else if (!nodeOne->getLeft() && !nodeOne->getRight())
        {
            return true;
        }
        else
            return false;
    }
    
    if (nodeOne && nodeTwo)
    {
        if ((nodeOne->getLeft() && nodeTwo->getRight()) || (nodeOne->getRight() && nodeTwo->getLeft()) ||
            (!nodeOne->getLeft() && !nodeTwo->getRight()) || (!nodeOne->getRight() && !nodeTwo->getLeft()))
        {
            bool auxOne, auxTwo;
            auxOne = validateSymmetry(nodeOne->getLeft(), nodeTwo->getRight());
            auxTwo = validateSymmetry(nodeOne->getRight(), nodeTwo->getLeft());
            return (auxOne && auxTwo);
        }
        else
        {
            return false;
        }
    }
    if (!nodeOne && !nodeTwo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void BinaryTree<T>::clear() {
    clear(root);
}

template <class T>
void BinaryTree<T>::clear(BNode<T> * node)
{
    if (node)
    {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

template <class T>
bool BinaryTree<T>::empty()
{
    return (root == NULL);
}

template <class T>
BNode<T> * BinaryTree<T>::getRoot()
{
    return root;
}

template <class T>
bool BinaryTree<T>::insert(T value, T parent)
{
    BNode<T> * parent_ptr = search(parent);
    if (parent_ptr)
    {
        return insert(value, parent_ptr);
    }
    return false;
}


template <class T>
bool BinaryTree<T>::insert(T value, BNode<T> * parent)
{
    // Insertar la root
    if (!parent)
    {
        root = new BNode<T>(value);
    }
    else
    {
        if (!parent->getLeft())
        {
            parent->setLeft(new BNode<T>(value));
        }
        else if (!parent->getRight())
        {
            parent->setRight(new BNode<T>(value));
        }
        else
        {
            return false;
        }
    }
    return true;
}

template <class T>
void BinaryTree<T>::preOrden()
{
    preOrden(root);
}

template <class T>
void BinaryTree<T>::preOrden(BNode<T> * node)
{
    if (node)
    {
        std::cout << *node << " ";
        preOrden(node->getLeft());
        preOrden(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::inOrden() {
    inOrden(root);
}

template <class T>
void BinaryTree<T>::inOrden(BNode<T> * node) {
    if (node) {
        inOrden(node->getLeft());
        std::cout << *node << " ";
        inOrden(node->getRight());
    }
}

template <class T>
void BinaryTree<T>::postOrden()
{
    postOrden(root);
}

template <class T>
void BinaryTree<T>::postOrden(BNode<T> * node)
{
    if (node)
    {
        postOrden(node->getLeft());
        postOrden(node->getRight());
        std::cout << *node << " ";
    }
}

template <class T>
int BinaryTree<T>::level(BNode<T> *node)
{
    if (node == NULL)
    {
        return 0;
    }
    BNode<T> * aux = node;
    int level = 1;
    while (getParent(aux->getInfo()))
    {
        ++level;
        aux = getParent(aux->getInfo());
    }
    return level;
}

template <class T>
BNode<T> * BinaryTree<T>::search(T info)
{
    return search(info, root);
}

template <class T>
BNode<T> * BinaryTree<T>::search(T info, BNode<T> * node)
{
    BNode<T> * found = NULL;
    if (node)
    {
        if (node->getInfo() == info)
        {
            return node;
        }
        else
        {
            found = search(info, node->getLeft());
            if (found)
            {
                return found;
            }
            return search(info, node->getRight());
        }
    }
    return found;
}

template <class T>
BNode<T> * BinaryTree<T>::getParent(T info)
{
    return getParent(info, root);
}

template <class T>
BNode<T> * BinaryTree<T>::getParent(T info, BNode<T> * node)
{
    BNode<T> * parent = NULL;
    if (node)
    {
        if (node->getInfo() == info && node == root)
        {
            return NULL;
        }
        else if (node->getLeft() && node->getLeft()->getInfo() == info)
        {
            return node;
        }
        else if (node->getRight() && node->getRight()->getInfo() == info)
        {
            return node;
        }
        else
        {
            parent = getParent(info, node->getLeft());
            if (parent)
            {
                return parent;
            }
            return getParent(info, node->getRight());
        }
    }
    return parent;
}

template <class T>
bool BinaryTree<T>::validateSiblings(T node, T n2)
{
    return (getParent(node) == getParent(n2));
}

template <class T>
bool BinaryTree<T>::validateSiblings(BNode<T> * node, BNode<T> * n2)
{
    if (node == NULL || n2 == NULL)
    {
        return false;
    }
    return (getParent(node->getInfo()) == n2->getParent(n2->getInfo()));
}

template <class T>
void BinaryTree<T>::siblings(BNode<T> * node)
{
    BNode<T> * left = node->getPadre()->getLeft();
    BNode<T> * right = node->getPadre()->getRight();
    
    if (left && left != node)
    {
        cout << *left->getInfo();
    }
    if (right && right != node)
    {
        cout << *right->getInfo();
    }
}

template <class T>
void BinaryTree<T>::ancestors(BNode<T> *node)
{
    BNode<T> * parent = node->getParent();
    while (parent)
    {
        cout << *parent->getInfo() << endl;
        parent = parent->getParent();
    }
}

template <class T>
void BinaryTree<T>::cousins(BNode<T> *node, BNode<T> *root)
{
    if (root)
    {
        if (level(node) == level(root) && getParent(node->getInfo()) != getParent(root->getInfo()))
        {
            std::cout << *root << " ";
        }
        cousins(node, root->getLeft());
        cousins(node, root->getRight());
    }
}

template <class T>
BNode<T> * BinaryTree<T>::inefficientSum()
{
    return inefficientSum(root);
}

template <class T>
BNode<T> * BinaryTree<T>::inefficientSum(BNode<T> * node)
{
    T value;
    if (node)
    {
        value = node->getInfo();
        BNode<T> * inefficientSum_izq = inefficientSum(node->getLeft());
        if (inefficientSum_izq)
        {
            value += inefficientSum_izq->getInfo();
            delete inefficientSum_izq;
        }
        
        BNode<T> * inefficientSum_der = inefficientSum(node->getRight());
        if (inefficientSum_der)
        {
            value += inefficientSum_der->getInfo();
            delete inefficientSum_der;
        }
        return new BNode<T>(value);
    }
    return NULL;
}

template <class T>
T BinaryTree<T>::efficientSum(BNode<T> * node)
{
    BNode<T> * acumulator = new BNode<T>(0);
    efficientSum(node, acumulator);
    T value = acumulator->getInfo();
    delete acumulator;
    return value;
}

template <class T>
void BinaryTree<T>::efficientSum(BNode<T> * node, BNode<T> * acumulator)
{
    if (node)
    {
        acumulator->setInfo(acumulator->getInfo() + node->getInfo());
        efficientSum(node->getLeft(), acumulator);
        efficientSum(node->getRight(), acumulator);
    }
}

template <class T>
T BinaryTree<T>::sum()
{
    return sum(root);
}

template <class T>
T BinaryTree<T>::sum(BNode<T> *node)
{
    static T value;
    if (node)
    {
        value += node->getInfo();
        sum(node->getLeft());
        sum(node->getRight());
    }
    return value;
}

template <class T>
std::ostream& BinaryTree<T>::print(std::ostream& os, BNode<T> * node)
{
    if (node)
    {
        os << *node << " ";
        print(os, node->getLeft());
        print(os, node->getRight());
    }
    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, BinaryTree<T> &arbol)
{
    return arbol.print(os, arbol.root);
}

#endif
