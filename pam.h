#ifndef Included_Pam_H
#define Included_Pam_H

#include "centroid.h"
#include "List.h"

//mexri 2^16 clusters mporw na to kanw unsinged int gia 2^32
template <class T>
class Pam
{
    private:
        Cluster<T>** clusters;
        int noClusters;
        List<T>* points; //krataw ta shmeia pou dn einai centroid

    public:
        Pam(List<T>* Points, int numberOfClusters);
        ~Pam();

        void initializationPP();
        void initializationConcetrate();

        void runPam();

        void clean();
        //update
        //assign vres kontinotera kendra kai kane anathesh
        void assignPam();
        //Cluster<T>* getCluster(int pos);
};

#endif
