#ifndef _UTILS_H
#define _UTILS_H

#include "plant.h"

bool validateColorInput(int color);
bool validateTypeInput(int type);

char *getFlowerColorText(FlowerColor color);
char *getFlowerTypeText(FlowerType type);

FlowerType askFlowerType();
FlowerColor askFlowerColor();

void swap(Plant *a, Plant *b);

void printColored(int color, const char *__format, ...);

#endif