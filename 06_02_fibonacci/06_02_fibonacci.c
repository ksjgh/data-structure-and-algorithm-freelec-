#include <stdio.h>

int fib_recur(int n) {
	int ret = 0;

	if (n == 0) {
		ret = 0;
	}
	else if(n == 1){
		ret = 1;
	}
	else {
		ret = fib_recur(n - 1) + fib_recur(n - 2);
	}

	return ret;
}

int fib_iter(int n) {
	int ret = 0;

	if (n < 2) {
		ret = 1;
	}
	else {
		int i = 0, temp = 0, current = 1, last = 0;

		for (i = 2; i <= n; i++) {
			temp = current;
			current += last;
			last = temp;
		}

		ret = current;
	}

	return ret;
}

// ToDo : measure processing time fib_recur vs. fib_iter
void main(int arc, char** argv) {
	int i = 0, input_value = 10;
	int	result = 0;

	for (i = 0; i < input_value; i++) {
		result = fib_recur(i);
		printf("fib_recur( %d ) = %d\n", i, result);
	}

	for (i = 0; i < input_value; i++) {
		result = fib_iter(i);
		printf("fib_iter( %d ) = %d\n", i, result);
	}
}
