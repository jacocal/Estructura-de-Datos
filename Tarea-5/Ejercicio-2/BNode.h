#ifndef BNode_h
#define BNode_h

#include <iostream>

template <class T> class BNode;
template <class T>
std::ostream& operator<<(std::ostream&, BNode<T>&);

template <class T>
class BNode {
    T info;
    T frecuencia;
    BNode<T> * right;
    BNode<T> * left;
public:
    BNode();
    BNode(T info, T frecuencia);
    ~BNode();
    
    T getInfo();
    void setInfo(T value);
    
    T getFrecuencia();
    void setFrecuencia();
    
    BNode<T> * getright();
    void setRight(BNode<T> * value);
    
    BNode<T> * getleft();
    void setLeft(BNode<T> * value);
    
    friend std::ostream& operator<< <>(std::ostream&, BNode<T>&);
};

template <class T>
BNode<T>::BNode() {
    this->left = this->right = NULL;
}

template <class T>
BNode<T>::BNode(T info, T frecuencia) : info(info), frecuencia(frecuencia) {
    this->right = this->left = NULL;
}

template <class T>
BNode<T>::~BNode() {
    left = right = NULL;
}

template <class T>
T BNode<T>::getInfo() {
    return info;
}

template <class T>
void BNode<T>::setInfo(T value) {
    info = value;
}

template <class T>
T BNode<T>::getFrecuencia() {
    return frecuencia;
}

template <class T>
void BNode<T>::setFrecuencia(T value) {
    frecuencia = value;
}

template <class T>
BNode<T> * BNode<T>::getright() {
    return right;
}

template <class T>
void BNode<T>::setRight(BNode<T> * value) {
    right = value;
}

template <class T>
BNode<T> * BNode<T>::getleft() {
    return left;
}

template <class T>
void BNode<T>::setLeft(BNode<T> * value) {
    left = value;
}

template <class T>
std::ostream& operator <<(std::ostream& os, BNode<T>& BNode) {
    os << BNode.info;
    return os;
}

#endif
