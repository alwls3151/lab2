#include <stdio.h>
#include "no1.h"

int main() {
	int a = 20, b=10;

	printf("add : %d\n", add(a,b));
	printf("subtract : %d\n", subtract(a,b));
	printf("multiply : %d\n", multiply(a,b));
	printf("divide : %.2f\n", divide(a,b));

	return 0;
}
