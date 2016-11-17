#include "clusterNode.h"

template <class T>
ClusterNode<T>::ClusterNode(T data)
{
    point = data;
}

template <class T>
ClusterNode<T>::ClusterNode(T data, double dist)
{
    point = data;
    distance = dist;
}

template <class T>
ClusterNode<T>::~ClusterNode()
{

}

template <class T>
T ClusterNode<T>::getPoint()
{
    return point;
}

template <class T>
double ClusterNode<T>::getDistance()
{
    return distance;
}

template <class T>
double ClusterNode<T>::getSecDistance()
{
    return secDistance;
}

template <class T>
T ClusterNode<T>::getSecCentroid()
{
    return secondCentroid;
}

template <class T>
void ClusterNode<T>::setDistance(double dist)
{
    distance = dist;
}

template <class T>
void ClusterNode<T>::setSecDistance(double secDist)
{
    secDistance = secDist;
}

template <class T>
void ClusterNode<T>::setSecCentroid(T centroid2)
{
    secondCentroid = centroid2;
}
