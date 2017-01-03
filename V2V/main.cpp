#include<iostream>
#include"matrix.h"

using namespace std;

int main() {
	matrix m{ {{1,2},{3 ,4},{5,6}},
	{{6,5},{4,3}, {2,1} } ,
	{ { 5,6 },{ 7 ,8 },{ 9,0 } } };

	matrix b = matrix::horizon_merge(m, m);
	b.print();
	b.pseudo_inverse().print();
	
	system("pause");
}