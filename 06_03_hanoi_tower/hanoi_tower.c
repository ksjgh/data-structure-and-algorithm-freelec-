#include <stdio.h>

void hanoi_tower(int n, char from, char temp, char to) {
	if (n == 1) {
		printf("Disk 1 moved from %c to %c\n", from, to);
	}
	else {
		hanoi_tower(n - 1, from, to, temp);
		printf("Disk %i moved from %c to %c\n", n, from, to);
		hanoi_tower(n - 1, temp, from, to);
	}
}

void main(int argc, char** argv) {
	char from = 'A';
	char temp = 'B';
	char to   = 'C';

	hanoi_tower(4, from, temp, to);
}