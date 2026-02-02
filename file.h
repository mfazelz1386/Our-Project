#ifndef FILE_H
#define FILE_H

#include "data.h"

/* ذخیره کردن جدول تو فایل */
void save(table *t, const char *name);

/* خواندن جدول از فایل */
void load(table *t, const char *name);

#endif
