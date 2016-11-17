#ifndef Included_ClusterNode_H
#define Included_ClusterNode_H

template<class T>
class ClusterNode
{
    private:
        T point;
        T secondCentroid; //xreiazetai sto pam
        double distance; //apo to centroid

    public:
        ClusterNode(T data);
        ClusterNode(T data, double dist);
        ~ClusterNode();

        T getPoint();
        double getDistance();
        T getSecCentroid();

        void setDistance(double dist);
        void setSecCentroid(T centroid2);
};

#endif
