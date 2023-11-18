#include <iostream>
#include <stdio.h>
#include <cstdlib>
int main()
{
	signed char a, b, c, e, f, res_c, res_asm, res_asm1, res_asm2, res_c1, res_c2;
	printf("(b/a+4*c+e)/(c-b+1-f)\n");
	printf("Enter the values of the range [-128...127]\n");
	printf("a = "); scanf_s("%hhd", &a);
	printf("b = "); scanf_s("%hhd", &b);
	printf("c = "); scanf_s("%hhd", &c);
	printf("e = "); scanf_s("%hhd", &e);
	printf("f = "); scanf_s("%hhd", &f);
	res_c = (b / a + 4 * c + e) / (c - b + 1 - f);
	res_c1 = (c - b + 1 - f);
	res_c2 = (b / a + 4 * c + e);
	printf("Result C = %d\n", res_c);
	printf("Result C(first) = %d\n", res_c1);
	printf("Result C(second) = %d\n", res_c2);
	__asm {
		mov al, b
		idiv a
		mov bl, 4
		imul bl, c
		add al, bl
		add al, e
		mov res_asm2, al

		mov al, c
		sub al, b
		inc al
		sub al, f
		mov res_asm1, al

		mov al, res_asm2
		cbw
		idiv res_asm1
		mov res_asm, al
	}
	printf("\n");
	printf("Result ASM = %d\n", res_asm);
	printf("Result ASM1 = %d\n", res_asm1);
	printf("Result ASM2 = %d\n", res_asm2);
	system("Pause");
	return 0;
}