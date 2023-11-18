#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main()
{
    short int a, b, c, e, f, res_c, res_asm, res_asm1, res_asm2, res_c1, res_c2;
    printf("(b/a+4*c+e)/(c-b+1-f)\n");
    printf("Enter the values of the range [-32768...32767]\n");
    printf("a = "); scanf_s("%hd", &a);
    printf("b = "); scanf_s("%hd", &b);
    printf("c = "); scanf_s("%hd", &c);
    printf("e = "); scanf_s("%hd", &e);
    printf("f = "); scanf_s("%hd", &f);
    res_c = (b / a + 4 * c + e) / (c - b + 1 - f);
    res_c1 = (c - b + 1 - f);
    res_c2 = (b / a + 4 * c + e);
    printf("Result C = %d\n", res_c);
    printf("Result C(first) = %d\n", res_c1);
    printf("Result C(second) = %d\n", res_c2);

    __asm {
        mov ax, b
        idiv a
        mov bx, 4
        imul bx, c
        add ax, bx
        add ax, e
        mov res_asm2, ax

        mov ax, c
        sub ax, b
        inc ax
        sub ax, f
        mov res_asm1, ax

        mov ax, res_asm2
        cwd
        idiv res_asm1
        mov res_asm, ax
    }
    printf("\n");
    printf("Result ASM = %d\n", res_asm);
    printf("Result ASM1 = %d\n", res_asm1);
    printf("Result ASM2 = %d\n", res_asm2);
    system("Pause");
    return 0;
}