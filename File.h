#ifndef FILE_H
#define FILE_H

#include "data.h"

/* ذخیره جدول */
void save(table *t, const char *name);

/* خواندن جدول */
void load(table *t, const char *name);

#endif

