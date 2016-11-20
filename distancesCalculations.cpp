int distance(Hamming* point1, Hamming* point2) //ypologismos apostashs hamming
{
   	int distance=0;
   	bitset<64> str1;
   	bitset<64> str2;

   	point1->get_bitString(str1);
   	point2->get_bitString(str2);

	for(int i=0;i<point1->get_noBits();i++) //veltiwsh mexri point1 nobits
	{
		if(str1[i]!=str2[i]) //an einai diaforetika +1
		{
			distance++;
		}
	}

	return distance;
}

double distance(Vector* point1, Vector* point2) //ypologismos apostashs cosine
{
    double innerProduct = 0, lengthPoint1 = 0, lenghtPoint2 =0;

    for(int i =0; i < point1->get_dimensions(); i++)
    {
        innerProduct += point1->get_coordinance(i)*point2->get_coordinance(i); //vriskw eswteriko ginomeno

        lengthPoint1 += pow(point1->get_coordinance(i), 2); //metro tou point1
        lenghtPoint2 += pow(point2->get_coordinance(i), 2); //metro tou point2
    }
   return 1- innerProduct/(sqrt(lengthPoint1) * sqrt(lenghtPoint2));
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

double distance(MatrixPoint* point1, MatrixPoint* point2)
{//ypologizw thn apostash apo to querykey sto point1 kai oxi to anapodo giati to point1 dn exei dedomena gia to querykey
    if(point2->get_distance(point1->get_pos())  == 0) return std::numeric_limits<double>::max();

    return point2->get_distance(point1->get_pos());
}

