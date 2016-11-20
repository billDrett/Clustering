#include <iostream>

#include "List.h"
#include "dataTypes.h"
#include "Node.h"
#include "centroid.h"
#include "clusterNode.h"
#include "Initialazation.h"
#include "euclideanNode.h"

using namespace std;
/*update allagi centroid me allo*/


int main()
{
    double x =12;
    Vector* v1 = new Vector("name1", 1, &x);
//    ClusterNode<Vector*> t(v1);
    //Cluster<T>** clusters, List<T>* points, int k
    List<EuclideanNode*>* myList = new List<EuclideanNode*>();
    Cluster<EuclideanNode*>** clusters = new Cluster<EuclideanNode*>*[5];
    for(int i =0; i < 5; i++)
    {
        clusters[i] = new Cluster<EuclideanNode*>();
    }
   // cout<<t.getPoint()->get_coordinance(0)<<endl;

    for(int i =0; i < 100; i++)
    {
        v1=new Vector("name1", 1, &(x *=i+1));
      //  myList.insertEnd(v1);
        myList->insertEnd(new EuclideanNode(v1));
    }

    for(Node<EuclideanNode*>* i = myList->get_begin(); i != NULL; i = i->get_next())
    {
        cout<<i->get_data()->get_vector()->get_coordinance(0)<<endl;
    }
    cout<<endl;


    initialization(clusters, myList, 5);

    cout<<"END"<<endl<<endl;
    for(int i =0; i < 5; i++)
    {
        cout<<clusters[i]->getCentroid()->get_vector()->get_coordinance(0)<<endl;
    }

    /*double distanc[]={1,2,3,4,5,6,7,8,9};

    cout<<distanc[binarySearch(distanc, 5.5, 0, 9)];*/

}
