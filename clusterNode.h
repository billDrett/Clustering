#ifndef Included_ClusterNode_H
#define Included_ClusterNode_H

template<class T>
class ClusterNode
{
    private:
        T point;
        T secondCentroid; //xreiazetai sto pam
        double distance; //apo to centroid
		double secDistance; //distance apo to deutero centroid, an 8umamai kala xreiazetai kai h apostash.

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
   		void setSecDistance(double secDist);

};

#endif
