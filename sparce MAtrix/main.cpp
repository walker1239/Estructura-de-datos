#include "sp_mat.h"
int main()
{
	int s1;
	sp_mat<int> s(10,10);
	cout<<"hoola";
	s.insert(3,3,19);
	cout<<"hoola";
	s.insert(4,4,19);
	cout<<"hoola";
	s.insert(5,5,19);
	cout<<"hoola";
	s.insert(6,6,19);
	cout<<"hoola";
//s(1,1)=5;

	s.print();

	

	return 0;
}