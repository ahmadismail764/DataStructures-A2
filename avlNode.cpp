#include "avlNode.hpp"
template <class T>
AVLNode<T>::AVLNode() { left = right = 0; }

template <class T>
AVLNode<T>::AVLNode(const T &el, AVLNode *l, AVLNode *r) : key(el), left(l), right(r) {}
