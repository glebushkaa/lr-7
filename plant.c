#include "plant.h"
#include "utils.h"

Plant *addPlant(Plant *plants, int *size, Plant plant) {
    realloc(plants, (*size + 1) * sizeof(Plant));
    plants[*size] = plant;
    (*size)++;
    return plants;
}

void sortByPlant(Plant *plants, int size) {
    int left = 0;
    int right = size - 1;
    bool swapped;

    do {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (plants[i].plant[0] <= plants[i + 1].plant[0]) continue;
            swap(&plants[i], &plants[i + 1]);
            swapped = true;
        }
        right--;
        if (!swapped) break;
        swapped = false;
        for (int i = right; i > left; i--) {
            if (plants[i - 1].plant[0] <= plants[i].plant[0]) continue;
            swap(&plants[i], &plants[i - 1]);
            swapped = true;
        }
        left++;
    } while (swapped);
}

void sortByFlowersCount(Plant *plants, int size) {
    int left = 0;
    int right = size - 1;
    bool swapped;

    do {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (plants[i].flowersCount <= plants[i + 1].flowersCount) continue;
            swap(&plants[i], &plants[i + 1]);
            swapped = true;
        }
        right--;
        if (!swapped) break;
        swapped = false;
        for (int i = right; i > left; i--) {
            if (plants[i - 1].flowersCount <= plants[i].flowersCount) continue;
            swap(&plants[i], &plants[i - 1]);
            swapped = true;
        }
        left++;
    } while (swapped);
}



Plant getPlantFromInput() {
    char *plant = malloc(sizeof(char) * 30);
    float height;
    int flowersCount;
    printf("Enter plant data: \nPlant name: ");
    scanf("%s", plant);
    printf("Height: ");
    scanf("%f", &height);
    FlowerColor flowerColor = askFlowerColor();
    FlowerType flowerType = askFlowerType();
    printf("Flower count: ");
    scanf("%i", &flowersCount);
    return (Plant){plant, height, flowerType, flowerColor, flowersCount};
}

void displayFlowers(Plant *plants, int size) {
    for (int i = 0; i < size; i++) {
        char *flowerColorText = getFlowerColorText(plants[i].color);
        char *flowerTypeText = getFlowerTypeText(plants[i].type);
        printf("Flower: %s, height: %0.2f, type: %s,color: %s, count: %i\n",
               plants[i].plant, plants[i].height, flowerTypeText,
               flowerColorText, plants[i].flowersCount);
    }
}