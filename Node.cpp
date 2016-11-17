#include <cstdlib>
#include "Node.h"
#include "dataTypes.h"
#include "euclideanNode.h"
#include "clusterNode.h"

template <class T>
Node<T>::Node(T Data)
{
    data = Data;
    next = NULL;
    prev = NULL;
}

template <class T>
Node<T>::~Node()
{

}

template <class T>
Node<T>* Node<T>::get_next()
{
    return next;
}
template <class T>
Node<T>* Node<T>::get_prev()
{
    return prev;
}
template <class T>
T Node<T>::get_data()
{
    return data;
}

template <class T>
void Node<T>::set_next(Node<T>* next1)
{
    next = next1;
}

template <class T>
void Node<T>::set_prev(Node<T>* prev1)
{
    prev = prev1;
}

template <class T>
void Node<T>::set_data(T Data)
{
    data = Data;
}

template class Node<int>;
template class Node<double>;
template class Node<std::string>;
template class Node<Vector* >;
template class Node<Hamming* >;
template class Node<EuclideanNode* >;
template class Node<MatrixPoint* >;
template class Node<ClusterNode<Vector*>*>;
template class Node<ClusterNode<Hamming*>*>;
template class Node<ClusterNode<EuclideanNode*>*>;
template class Node<ClusterNode<MatrixPoint*>*>;


