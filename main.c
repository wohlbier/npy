#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *f;
    f = fopen("./test.npy", "r");

    char b[1000]; // read buffer
    // skip first 6 bytes. NUMPY
    fread(b, 6, 1, f);
    // read major version byte
    char V;
    fread(&V, 1, 1, f);
    printf("%d\n", V);
    //skip minor version byte
    fread(b, 1, 1, f);
    unsigned short int HEADER_LEN;
    int HL_bytes = 2;
    if (V == 2) { HL_bytes = 4; } // 4 bytes if major version is true
    fread(&HEADER_LEN, HL_bytes, 1, f);
    // skip the header
    fread(b, HEADER_LEN, 1, f);

    // read the data
    size_t N = 1000;
    float *a = (float *)malloc(N*sizeof(float));
    fread(a, N*sizeof(float), 1, f);
    for (int i=0; i<N; i++)
    {
        printf("%f\t", a[i]);
    }
    printf("\n");

    fclose(f);
    return 0;
}
