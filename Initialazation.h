
#include "centroid.h"

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

    for(int i =0; i < k; i++) //arxikopoihsh toy pinaka
    {
        distances[i] = std::numeric_limits<double>::max();
    }


    for(int i=0; i < k-1; i++)
    {
        node = points->get_begin();
        for(int j = 0; j < points->getSize(); j++) //vima 2
        {
            tmpDist = distance(node, clusters[i]->getCentroid())

            if(tmpDist ==0) continue;//to simeio einai kentro, opote to agnow

            if(tmpDist < distances[j])
            {
                distances[j] = tmpDist;
            }
            node->get_next();
        }

        //vhma 3
        /*for(int j=0; j< k; j++) //arxikopoihsh PMertric
        {
            PMetric[j] = 0;
        }*/

        for(int j=0; j< points->getSize(); j++)
        {
            PMetric[j] = sumP(distances, j);
        }
        do
        {
            randomX = randomNumberDouble(0, PMetric[points->getSize()-1]);
            tmp = getRandomPoint(binarySearch(distances, randomX, 0, points->getSize()-1));
        }while(exists(clusters, tmp, i+1));


        //an dn to exoyme epileksei

        clusters[i+1]->setCentroid(tmp);
    }
}

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

template <class T>
double distance(T point1, T point2) //diaforetiki gia hamming, euclidean, cosine
{

}
