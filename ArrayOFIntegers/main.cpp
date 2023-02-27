#include<iostream>
using namespace std;
int main(const int& Argc, const char* Argv[])
{
	setlocale(0, "rus");

	const int Nelem = 10;
	int Arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int* begAr = &Arr[0];
	int* endAr = &Arr[Nelem];
	int* itrAr = begAr;
	int* tmpValAr = new int(0);

	cout << "Задан\t1 2 3 4 5 6 7 8 9 10" << endl;

	while (itrAr < endAr)
	{
		*tmpValAr = *itrAr;
		*itrAr = *(itrAr + 1);
		*(itrAr + 1) = *tmpValAr;
		itrAr += 2;
	}

	cout << "Получен\t";

	for (int i = 0; i < Nelem; ++i)cout << Arr[i] << " ";

	cout << endl;

	system("pause");

	return 0;
}