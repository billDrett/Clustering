#ifndef Included_Init_H
#define Included_Init_H

#include <iostream>
#include <limits>
#include <cmath>
#include "centroid.h"
#include "List.h"
#include "Node.h"
#include "euclideanNode.h"
#include "psedoRandomNumbers.h"

using namespace std;

double maxDistance(double* distances, int size);
//double distance(Vector* point1, Vector* point2); //ypologismos apostashs cosine
double distance(EuclideanNode* point1, EuclideanNode* point2); //ypologismos apostashs gia eukleidia
int binarySearch(double* distances,  double searchPoint, int start, int end);
double sumP(double* distances,  int size);




template <class T>
bool exists(Cluster<T>** clusters, T point, int k)
{
    for(int i = 0; i < k; i++)
    {
        if(clusters[i]->getCentroid() == point) //isws kalytera iso kapoio id
        {
            return true;
        }
    }

    return false;
}

template <class T>
T getRandomPoint(List<T>* myList, int pos) //epistrefei to tyxaio simeio
{
    int count = 0;
    for(Node<T>* i = myList->get_begin(); i != NULL; i = i->get_next())
    {
        if(count == pos) return i->get_data();

        count++;
    }
    return 0;
}


template <class T>
void initialization(Cluster<T>** clusters, List<T>* points, int k) //pernei pinaka apo clusters
{
    double distances[points->getSize()]; //D(i)
    double PMetric[points->getSize()];
    double tmpDist;
    Node<T>* node;
    T tmp;
    double randomX;
    tmp = getRandomPoint(points, randomNumberInt(0, points->getSize())); //pairnw tyxaio simeio vhma 1

    clusters[0]->setCentroid(tmp);

    for(int i =0; i < points->getSize(); i++) //arxikopoihsh toy pinaka
    {
        distances[i] = std::numeric_limits<double>::max();

    }


    for(int i=0; i < k-1; i++)
    {
        node = points->get_begin();
        for(int j = 0; j < points->getSize(); j++) //vima 2
        {
            tmpDist = distance(node->get_data(), clusters[i]->getCentroid());
            cout<<node->get_data()->get_vector()->get_coordinance(0)<<" "<<clusters[i]->getCentroid()->get_vector()->get_coordinance(0)<<endl;
            /*if(tmpDist ==0) //ama einai mhden agnoeitai sto athroisma
            {
                node = node->get_next();
                continue;//to simeio einai kentro, opote to agnow, mhden sta double dn yparxei sxedon pote opote problima
            }
            */
            if(tmpDist < distances[j])
            {
                distances[j] = tmpDist;
            }
            node = node->get_next();
        }
        cout<<endl<<endl;
        for(int j=0; j < points->getSize(); j++)
        {
            cout<<"p"<<distances[j]<<endl;
        }

        //vhma 3
        /*for(int j=0; j< k; j++) //arxikopoihsh PMertric
        {
            PMetric[j] = 0;
        }*/
        PMetric[0] = 0;
        double maxDist = maxDistance(distances, points->getSize());
        for(int j=1; j< points->getSize(); j++) //eoxume apo thn arxh n-1 P afou to prwto centroid to pairnoume tyxaia
        {
            PMetric[j] = PMetric[j-1] + distances[j]*distances[j]/maxDist; //veltiwsei thn polyplokothtas apla na mpei se loop kai na vriskei olwn twn P, anti gia o(n^2) o(n)

            cout<<"v "<<PMetric[j]<<endl;
        }
        do
        {
            randomX = randomNumberDouble(0, PMetric[points->getSize()-1]);
            cout<<"random "<< randomX<<endl;
            cout<<"pos "<<binarySearch(PMetric, randomX, 0, points->getSize()-1)<<endl;
            tmp = getRandomPoint(points, binarySearch(PMetric, randomX, 0, points->getSize()-1));
        }while(exists(clusters, tmp, i+1));


        //an dn to exoyme epileksei

        clusters[i+1]->setCentroid(tmp);
        //cout<<"done????"<<endl;
    }
}




//epistrefei to r
int binarySearch(double* distances,  double searchPoint, int start, int end)
{
    for(int i = start; i <= end; i++)
    {
        if(distances[i]> searchPoint)
        {
            return i;
        }
    }

    return -1; //sfalma
    /*
    if(end-start == 2)
    {
        return end;
    }
    int middle = (start+end)/2 + 1
    if(distances[])*/

}

double sumP(double* distances,  int size)
{
    double tmp = 0;
    double maxDist = maxDistance(distances, size);
    cout<<"max"<<maxDist<<endl;
    for(int i =0; i < size; i++)
    {
        tmp += distances[i]*distances[i]/maxDist;
    }

    return tmp;
}

double maxDistance(double* distances, int size)
{
    double maxDist = std::numeric_limits<double>::min();

    for(int i =0; i < size; i++)
    {
        if(distances[i] > maxDist)
        {
            maxDist = distances[i];
        }
    }

    return maxDist;

}

double distance(EuclideanNode* point1, EuclideanNode* point2) //ypologismos apostashs gia eukleidia
{
	double sum=0.0;

	for(int i=0;i<point1->get_vector()->get_dimensions();i++)
	{
		sum=sum + pow((point1->get_vector()->get_coordinance(i)-point2->get_vector()->get_coordinance(i)),2.0);
	}
	return sqrt(sum);
}

/*template <class T>
double distance(T point1, T point2) //diaforetiki gia hamming, euclidean, cosine
{

}
*/

#endif // Included_Init_H
