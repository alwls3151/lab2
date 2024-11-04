#include "no1.h"
#include <stdio.h>

int add (int a, int b){
	return a+b;
}

int subtract (int a, int b) {
	return a-b;
}

int multiply (int a, int b) {
	return a*b;
}

double divide (int a, int b) {
	if (b!=0)
		return (double)a/b;
	else {
		printf ("error");
		return 0.0;
	}
}
