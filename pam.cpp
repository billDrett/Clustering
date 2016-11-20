#include "pam.h"

template <class T>
Pam<T>::Pam(List<T>* Points, int numberOfClusters)
{
    noClusters = numberOfClusters;
    clusters = new Cluster<T>*[noClusters];
    for(int i =0; i < noClusters; i++)
    {
        clusters[i] = new Cluster<T>();
    }

    points = Points; //lista simeiwn tou dataset, mporei na mhn thn xreiazomai
}

template <class T>
Pam<T>::~Pam()
{
    for(int i =0; i< noClusters; i++)
    {
        delete clusters[i];
    }

    delete[] clusters;
}

template <class T>
void Pam<T>::initializationPP() //prepei na vrw kai ta kontinotera kentra ???
{

}

template <class T>
void Pam<T>::initializationConcetrate()
{

}

template <class T>
void Pam<T>::runPam()
{
    initializationPP();
    for(int i =0; i< noClusters; i++)
    {
        for(Node<T>* j = clusters[i]->getPoints(); j != NULL; j=j->get_next()) //update state
        {

        }

        //for(int j = 0; clusters[i]->getPoints(); j++)
    }
}

template <class T>
void Pam<T>::clean() //svinei ola ta clusters, mporei apla na kanw delete thn domh kai ksana create
{

}
