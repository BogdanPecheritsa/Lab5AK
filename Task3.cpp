#include <iostream>
#include <stdio.h>
#include <cstdlib>
int main()
{
	int a, b, c, e, f, res_c, res_asm, res_asm1, res_asm2, res_c1, res_c2;
	printf("(b/a+4*c+e)/(c-b+1-f)\n");
	printf("Enter the values of the range [-2147483648...2147483647]\n");
	printf("a = "); scanf_s("%d", &a);
	printf("b = "); scanf_s("%d", &b);
	printf("c = "); scanf_s("%d", &c);
	printf("e = "); scanf_s("%d", &e);
	printf("f = "); scanf_s("%d", &f);
	res_c = (b / a + 4 * c + e) / (c - b + 1 - f);
	res_c1 = (c - b + 1 - f);
	res_c2 = (b / a + 4 * c + e);
	printf("Result C = %d\n", res_c);
	printf("Result C(first) = %d\n", res_c1);
	printf("Result C(second) = %d\n", res_c2);
	__asm {
		mov eax, b
		cdq
		idiv a
		mov ebx, c
		mov esi, 4
		imul esi
		add eax, esi
		add eax, e
		mov res_asm2, eax

		mov eax, c
		sub eax, b
		inc eax
		sub eax, f
		mov res_asm1, eax

		mov eax, res_asm2
		cdq
		idiv res_asm1
		mov res_asm, eax
	}
	printf("\n");
	printf("Result ASM = %d\n", res_asm);
	printf("Result ASM1 = %d\n", res_asm1);
	printf("Result ASM2 = %d\n", res_asm2);
	system("Pause");
	return 0;
}