#include "centroid.h"
#include <stdlib.h>
#include "dataTypes.h"
#include "euclideanNode.h"


template <class T>
Cluster<T>::Cluster()
{
    points = new List<ClusterNode<T>*>();
}

template <class T>
Cluster<T>::Cluster(T centr)
{
    points = new List<ClusterNode<T>*>();
    Centroid = centr;
}

template <class T>
Cluster<T>::~Cluster()
{
    ClusterNode<T>* tmp;

    while((tmp = points->deleteFirstNode()) != NULL) //diagrafei twn clusterNode
    {
        delete tmp;
    }

    delete points;
}

template <class T>
Node<ClusterNode<T>*>* Cluster<T>::getPoints()
{
    return points->get_begin();
}

template <class T>
int Cluster<T>::getNoPoints()
{
    return points->getSize();
}

template <class T>
T Cluster<T>::getCentroid()
{
    return Centroid;
}

template <class T>
void Cluster<T>::setCentroid(T centr)
{
    Centroid = centr;
}

template <class T>
ClusterNode<T>* Cluster<T>::insertPoint(T point) //epistrefei to node pou dhmiourgithike gia na kanoume set to distance kai to secondCentroid
{
    ClusterNode<T>* tmp = new ClusterNode<T>(point);
    points->insertEnd(tmp);

    return tmp;
}

template <class T>
void Cluster<T>::deletePoint(Node<ClusterNode<T>*>* delPoint)  //diagrafh tou shmeiou
{
    points->deleteNode(delPoint);
}

template class Cluster<Vector* >;
template class Cluster<Hamming* >;
template class Cluster<EuclideanNode* >;
template class Cluster<MatrixPoint* >;
