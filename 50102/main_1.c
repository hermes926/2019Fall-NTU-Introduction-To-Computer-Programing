#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    char a[32], b[32], out[32];
    //uint8_t f1[100000] = {0}, f2[100000] = {0};
    scanf("%s%s", a, b);
    scanf("%s", out);
    FILE *fp1 = fopen(a, "rb");
    assert(fp1 != NULL);
    FILE *fp2 = fopen(b, "rb");
    assert(fp2 != NULL);
    FILE *fp3 = fopen(out, "wb");
    assert(fp3 != NULL);
    uint8_t x[2] = {0}, y[2] = {0};
    int carry = 0;
    long int cpos1 = ftell(fp1), cpos2 = ftell(fp2);
    fseek(fp1, -2, SEEK_END);
    fseek(fp2, -2, SEEK_END);
    long int pos1 = ftell(fp1);
    long int pos2 = ftell(fp2);
    pos1 > pos2 ? fseek(fp3, pos1, SEEK_SET) : fseek(fp3, pos2, SEEK_SET);
    long int pos3 = ftell(fp3);
    //printf("%ld %ld %ld\n%ld %ld\n", pos1, pos2, pos3, cpos1, cpos2);
    uint8_t z[2] = {0};
    while (pos1 >= -1 || pos2 >= -1)
    {
        if (pos1 < -1)
        {
            x[0] = 0, x[1] = 0;
        }
        else if (pos1 == -1)
        {
            fread(&x[1], sizeof(uint8_t), 1, fp1);
            x[0] = 0;
        }
        else
            fread(x, sizeof(uint8_t), 2, fp1);
        if (pos2 < -1)
        {
            y[0] = 0;
            y[1] = 0;
        }
        else if (pos2 == -1)
        {
            fread(&y[1], sizeof(uint8_t), 1, fp2);
            y[0] = 0;
        }
        else
            fread(y, sizeof(uint8_t), 2, fp2);

        z[1] = (x[1] + y[1] + carry) % 256;
        carry = x[1] + y[1] + carry >= 256 ? 1 : 0;
        //printf("%d %d %d %d\n", x[1], y[1],z[1], carry);
        z[0] = (x[0] + y[0] + carry) % 256;
        carry = x[0] + y[0] + carry >= 256 ? 1 : 0;
        //printf("%d %d\n", z[0], z[1]);
        if(pos3 != -1)
            fwrite(z, sizeof(uint8_t), 2, fp3);
        else
            fwrite(&z[1], sizeof(uint8_t), 1, fp3);

        if (pos1 == 1)
            fseek(fp1, -3, SEEK_CUR);
        else
            fseek(fp1, -4, SEEK_CUR);
        if (pos2 == 1)
            fseek(fp2, -3, SEEK_CUR);
        else
            fseek(fp2, -4, SEEK_CUR);
        if (pos3 == 1)
            fseek(fp3, -3, SEEK_CUR);
        else
            fseek(fp3, -4, SEEK_CUR);
        pos1 -= 2;
        pos2 -= 2;
        pos3 -= 2;
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    //fputc(final, sizeof(uint8_t), c-1, fp3);
    return 0;
}