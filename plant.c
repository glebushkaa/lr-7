#include "plant.h"

bool validateColorInput(int color);
bool validateTypeInput(int type);

char* getFlowerColorText(FlowerColor color);
char* getFlowerTypeText(FlowerType type);

void askFlowerType(int *type);
void askFlowerColor(int *color);

void swap(Plant* a, Plant* b);

FlowerType types[] = {ROSE, IRIS, CARNATION, PEONY, DAFFODIL, LILY};
FlowerColor colors[] = {RED, PINK, YELLOW, WHITE, BLUE};

Plant *addPlant(Plant *plants, int *size, Plant plant) {
    realloc(plants, (*size + 1));
    plants[*size] = plant;
    (*size)++;
    return plants;
}

void sortByPlant(Plant *plants, int size) {
}

void sortByFlowersCount(Plant *plants, int size) {
    int left = 0;
    int right = size - 2;
    bool swapped;

    do {
        swapped = false;
        for(int i = left; i < right; i++) {
            if(plants[i].flowersCount >= plants[i+1].flowersCount) continue;
            swap(&plants[i], &plants[i+1]);
            swapped = true;
        }
        right--;
        if(!swapped) break;
        swapped = false;
        for(int i = right; i > left; i--) {
            if(plants[i - 1].flowersCount >=  plants[i].flowersCount) continue;
            swap(&plants[i], &plants[i-1]);
            swapped = true;
        }
        left++;
    } while(swapped);
}

void swap(Plant *a, Plant *b) {
    Plant* temp = a;
    *a = *b;
    *b = *temp;
}

Plant getPlantFromInput() {
    char *plant = malloc(sizeof(char) * 30);
    float height;
    int flowerType, flowerColor, flowersCount;

    printf("Enter plant data: \nPlant name: ");
    scanf("%s", plant);
    printf("Height: ");
    scanf("%f", &height);
    askFlowerColor(&flowerColor);
    askFlowerType(&flowerType);
    printf("Flower count: ");
    scanf("%i", flowersCount);
    return (Plant){ plant, height, flowerType, flowerColor, flowersCount };
}

void displayFlowers(Plant *plants, int size) {
    for(int i = 0; i < size; i++) {
        char* flowerColorText = getFlowerColorText(plants[i].color);
        char* flowerTypeText = getFlowerColorText(plants[i].type);
        printf(
            "Flower: %s, height: %0.2f, type: %s,color: %s, count: %i\n",
            plants[i].plant,
            plants[i].height,
            flowerTypeText,
            flowerColorText,
            plants[i].flowersCount
        );
    }
}



bool validateColorInput(int color) {
    int size = sizeof(types) / sizeof(FlowerColor);
    for (int i = 0; i < size; i++) {
        if (colors[i] != color) continue;
        return true;
    }
    return false;
}

bool validateTypeInput(int type) {
    int size = sizeof(types) / sizeof(FlowerType);
    for (int i = 0; i < size; i++) {
        if (types[i] != type) continue;
        return true;
    }
    return false;
}

char *getFlowerColorText(FlowerColor color) {
    switch(color) {
        case RED: return "red";
        case PINK: return "pink";
        case YELLOW: return "yellow";
        case WHITE: return "white";
        case BLUE: return "blue";
        default: return "unknown";
    }
}
char *getFlowerTypeText(FlowerType type) {
    switch(type) {
        case ROSE: return "rose";
        case IRIS: return "iris";
        case CARNATION: return "carnation";
        case PEONY: return "peony";
        case DAFFODIL: return "daffodil";
        case LILY: return "lily";
        default: return "unknown";
    }
}

void askFlowerType(int *type) {
    bool valid = false;
    printf("Flower type: \n1.Rose\n2.Iris\n3.Carnation\n4.Peony\n5.Daffodil\n6.Lily\nEnter: ");
    do {
        scanf("%i", type);
        valid = validateTypeInput(*type);
        if(!valid) {
            printf("Unknown type!\n");
        }
    } while(!valid);
}

void askFlowerColor(int *color) {
    bool valid = false;
    printf("Flower color: \n31.Red\n33.Yellow\n34.Blue\n35.Pink\n37.White\nEnter: ");
    do {
        scanf("%i", color);
        valid = validateColorInput(*color);
        if (!valid) {
            printf("Unknown color!\n");
        }
    } while (!valid);
}