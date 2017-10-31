#include<iostream>
#include<stdlib.h>
#include<fstream>
#include"matrix.h"
#include"vue.h"
#include"system_control.h"
#include"context.h"

using namespace std;

ofstream debug;

int main() {
	srand(1);

	debug.open("log/debug.txt");

	context *__context = context::get_context();

	system_control *__system_control = __context->get_system_control();

	__system_control->process();

	debug.close();
	
	system("pause");
}
