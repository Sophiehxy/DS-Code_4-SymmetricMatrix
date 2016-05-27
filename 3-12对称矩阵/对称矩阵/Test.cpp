#include<iostream>
using namespace std;
#include"Matrix.h"

void Test()
{
	int a[5][5] = {
					{ 0, 1, 2, 3, 4 },
					{ 1, 0, 1, 2, 4 },
					{ 2, 1, 0, 1, 2 },
					{ 3, 2, 1, 0, 1 },
					{ 4, 3, 2, 1, 0 } 
				};
	SymmetricMatrix <int> sm((int*)a, 5);
	sm.Display();
	cout << sm.AccessNum(3, 0) << endl;

}

int main()
{
	Test();
	return 0;
}