#include <iostream>
#include <string> 
using namespace std;

struct liga
{
	int i = 0;
};

int main()
{
	int i = 0;
	liga dato[9];
	do
	{
		int* a;
		for (int i = 0; i < 1; i++)
		{
			 a = new int;
			*a = dato[i].i;
			cout << "\t La direccion de memoria de a es: " << a << "\n";
			int* b = new int;
			*b = dato[i].i;
			cout << "\t La direccion de memoria de b es: " << b << "\n";;
			delete a;
			//delete b;
			dato[i].i = dato[i].i + 1;
			cout << "------------------------------------\n";

		}
	} while (dato[i].i < 9);
}