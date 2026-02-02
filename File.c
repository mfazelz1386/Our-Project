#include "file.h"
#include <stdio.h>

/* ذخیره اطلاعات در فایل */
void save(table *t, const char *name) {

    FILE *fp = fopen(name, "w");
    int i, j;

    if (fp == NULL)
        return;

    /* نوشتن همه سلول‌ها */
    for (i = 0; i < (*t).r; i++) {
        for (j = 0; j < (*t).c; j++) {
            fprintf(fp, "%s %lf %s %d\n",
                (*t).a[i][j].addr,
                (*t).a[i][j].val,
                (*t).a[i][j].form,
                (*t).a[i][j].err);
        }
    }

    fclose(fp);
}

/* خواندن اطلاعات از فایل */
void load(table *t, const char *name) {

    FILE *fp = fopen(name, "r");
    int i, j;

    if (fp == NULL)
        return;

    for (i = 0; i < (*t).r; i++) {
        for (j = 0; j < (*t).c; j++) {
            fscanf(fp, "%s %lf %s %d",
                (*t).a[i][j].addr,
                &((*t).a[i][j].val),
                (*t).a[i][j].form,
                &((*t).a[i][j].err));
        }
    }

    fclose(fp);
}
