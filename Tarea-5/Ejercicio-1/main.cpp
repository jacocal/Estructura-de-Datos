using namespace std;

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum);

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum, BNode<T> *nodo, BNode<T> * wSum);


int main()
{
    
    BinaryTree<int> * whole = new BinaryTree<int>;
    BinaryTree<int> * sumWholes = new BinaryTree<int>;
    
    whole->insert(1, nullptr);
    whole->insert(3, 1);
    whole->insert(784, 2);
    whole->insert(12, 2);
    
    
    sumTree(whole, sumWholes);
    
    cout << "Bienvenido al Sumador de Arboles T9-321890: " << *whole << endl;
    cout << "Datos: " << *whole << endl;
    cout << "Suma: " << *sumWholes << endl;
    
    return 0;
}

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum) {
    sumTree<T>(original, sum, original->getRoot(), nullptr);
}

template <typename T>
void sumTree(BinaryTree<T> * original, BinaryTree<T> * sum, BNode<T> *nOriginal, BNode<T> *wSum) {
    if (nOriginal) {
        wSum = sum->insert((original->efficientSum(nOriginal)), wSum);
        sumTree(original, sum, nOriginal->getLeft(), wSum);
        sumTree(original, sum, nOriginal->getRight(), wSum);
    }
}
