#include "file.h"
#include <stdio.h>


void save(table *t, const char *name) {

    FILE *f;
    int i;
    int j;

    f = fopen(name, "w");
    if (f == NULL) {
        printf("error\n");
        return;
    }



    
    for (i = 0; i < (*t).r; i++) {
        for (j = 0; j < (*t).c; j++) {

            /* آدرس سلول */
            fprintf(f, "%s ", (*t).a[i][j].addr);

            /* مقدار سلول */
            fprintf(f, "%lf ", (*t).a[i][j].val);

            /* فرمول سلول */
            fprintf(f, "%s ", (*t).a[i][j].form);

            /* خطا */
            fprintf(f, "%d\n", (*t).a[i][j].err);
        }
    }

    fclose(f);
}


void load(table *t, const char *name) {

    FILE *f;
    int i;
    int j;


    f = fopen(name, "r");
    if (f == NULL) {
        printf("file peyda nashod\n");
        return;
    }

    for (i = 0; i < (*t).r; i++) {
        for (j = 0; j < (*t).c; j++) {

            /* آدرس سلول */
            fscanf(f, "%s", (*t).a[i][j].addr);

            /* مقدار سلول */
            fscanf(f, "%lf", &((*t).a[i][j].val));

            /* فرمول سلول */
            fscanf(f, "%s", (*t).a[i][j].form);

            /* خطا */
            fscanf(f, "%d", &((*t).a[i][j].err));
        }
    }


    fclose(f);
}
