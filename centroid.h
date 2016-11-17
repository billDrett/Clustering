#ifndef Included_Cluster_H
#define Included_Cluster_H

#include "List.h"
#include "Node.h"
#include "clusterNode.h"

//gia na pareis ta stoixeia tou cluster kaneis
/*
Cluster* myCluster; //prepei na arxikopoihthei
for(Node<ClusterNode<T>*>* i = myCluster->getPoints(); i != NULL; i = i->get_next())
{
            i->get_data(); //tha epistrefei to ClusterNode
            i->get_data()->getPoint(); //epistefei to shmeio

            i->get_data()->getDistance(); //epistrfei thn apostash apo kentro
            myCluster(i) //diagrafei to point apo to cluster
}

*/

/*
template<class T>
class ClusterNode
{
    private:
        T point;
        T secondCentroid; //xreiazetai sto pam
        double distance; //apo to centroid
		double secDistance; //distance apo to deutero centroid, an 8umamai kala xreiazetai kai h apostash. // <----------------------

    public:
        ClusterNode(T data);
        ClusterNode(T data, double dist);
        ~ClusterNode();

        T getPoint();
        double getDistance();
        T getSecCentroid();
		double getSecDistance();
        void setDistance(double dist);
        void setSecCentroid(T centroid2);
		void setSecDistance(double secdist);
};*/

template <class T>
class Cluster
{
    private:
        T Centroid;
        List<ClusterNode<T>>* points;

    public:
        Cluster();
        Cluster(T centr);
        ~Cluster();

        ClusterNode<T>* getPoints(); //epistrefei thn lista me ta shmeia
        T getCentroid();

        ClusterNode<T>* insertPoint(T point); //epistrefei to node pou dhmiourgithike gia na kanoume set to distance kai to secondCentroid
        deletePoint(ClusterNode<T>* delPoint); //diagrafh tou shmeiou

        /*
        isws thelei kai alles
        */

};



#endif
