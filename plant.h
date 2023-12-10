#ifndef _PLANT_H
#define _PLANT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum
{
    ROSE = 1,
    IRIS = 2,
    CARNATION = 3,
    PEONY = 4,
    DAFFODIL = 5,
    LILY = 6
} FlowerType;

typedef enum
{
    RED = 31,
    PINK = 35,
    YELLOW = 33,
    WHITE = 37,
    BLUE = 34
} FlowerColor;

typedef struct
{
    char *plant;
    float height;
    FlowerType type;
    FlowerColor color;
    int flowersCount;
} Plant;

Plant *addPlant(Plant *plants, int *size, Plant plant);
Plant getPlantFromInput();

void sortByPlant(Plant *plants, int size);
void sortByFlowersCount(Plant *plants, int size);

void displayFlowers(Plant *plants, int size);

#endif