#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    FILE * save;
    FILE * load;
    int N = 10;
    int n=2;
    int i = 0;
    int a[] = {1, 3, 5, 7, 9, 0, 2, 4, 6, 8};

    save = fopen("f8", "wb");
    if (save == NULL) {
        printf("File doesn't exists!\n");
        exit(1);
    }

    if ( fwrite(a, sizeof(a), 1, save) != 1) {    //   if ( fwrite(a, sizeof(int), N, fp) != N ) will work too
        printf("Write Error\n");
        exit(1);
    }
    fclose(save);
    load = fopen("f9", "wb");
    if (load == NULL) {
        printf("File doesn't exists!\n");
        exit(1);
    }
    if ( fwrite(&n, sizeof(n), 1, load) != 1) {    //   if ( fwrite(a, sizeof(int), N, fp) != N ) will work too
        printf("Write Error\n");
        exit(1);
    }
    fclose(load);

    for (i = 0; i < N; i++) a[i] = 0;
    for (i = 0; i < N; i++) printf("%d",a[i]);

    n=3;

    save = fopen("f8", "rb");
    if (save == NULL) {
        printf("File doesn't exists!\n");
        exit(1);
    }

    if ( fread(a, sizeof(a), 1, save) != 1) {
        printf("Read Error\n");
        exit(1);
    }
    fclose(save);
    load = fopen("f9", "rb");
    if (load == NULL) {
        printf("File doesn't exists!\n");
        exit(1);
    }
    if ( fread(&n, sizeof(n), 1, load) != 1) {
        printf("Read Error\n");
        exit(1);
    }
    fclose(load);

    for (i = 0; i < N; i++) {
        printf("%d \n", a[i]);
    }
    printf("%d",n);
    printf("\n");

    return 0;
}
