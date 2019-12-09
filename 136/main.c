#include<stdio.h>
#include<assert.h>
int main(){
    char in[80], out[80];
    scanf("%s%s", in, out);
    FILE *fp = fopen(in, "rb");
    FILE *outf = fopen(out, "w");
    fprintf(outf, "<table border=\"1\">\n<tbody>\n");
    assert(fp != NULL);
    assert(outf != NULL);
    char name[20];int id;char phone[12];
    float score[4];int day, month, year;
    while(fread(name, sizeof(char), 20, fp) == 20){
        fprintf(outf,"<tr>\n");
        fprintf(outf,"<td>%s</td>\n", name);
        fread(&id, sizeof(int), 1, fp);
        fprintf(outf, "<td>%d</td>\n", id);
        fread(phone, sizeof(char), 12, fp);
        fprintf(outf, "<td>%s</td>\n", phone);
        //fscanf(fp, "%f%f%f%f", &score[0], &score[1], &score[2], &score[3] );
        fread(&score[0], sizeof(float), 1, fp);
        fread(&score[1], sizeof(float), 1, fp);
        fread(&score[2], sizeof(float), 1, fp);
        fread(&score[3], sizeof(float), 1, fp);
        fprintf(outf, "<td>%f, %f, %f, %f</td>\n", score[0], score[1], score[2], score[3]);
        //fscanf(fp, "%d%d%d", &day, &month, &year);
        fread(&day, sizeof(int), 1, fp);
        fread(&month, sizeof(int), 1, fp);
        fread(&year, sizeof(int), 1, fp);
        fprintf(outf, "<td>%d, %d, %d</td>\n</tr>\n", day, month, year);
    }
    fprintf(outf, "</tbody>\n</table>\n");
    fclose(fp);fclose(outf);
    return 0;
}