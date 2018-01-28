// A simple application for LSB steganography
// Matthew DiBello

#include<stdio.h>

int masks[8] = {1, 2, 4, 8, 16, 32, 48, 64};

int main(int argc, char* argv[]) {

    FILE* orig = fopen("connor.png", "w+");
    char c;
    int i;

    c = getc(orig);
    while (c != EOF) {

        printf("%c\n", c);

        for (i = 7; i >= 0; i--) {

            printf("Hello?\n");

            if (c & masks[i] == 1)
                printf("1");
            else
                printf("0");

        }

        c = getc(orig);

    }

    return 0;
}
