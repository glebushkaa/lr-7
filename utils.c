#include "utils.h"

FlowerColor colors[] = {RED, YELLOW, BLUE, PINK, WHITE};
FlowerType types[] = {ROSE, IRIS, CARNATION, PEONY, DAFFODIL, LILY};

void swap(Plant *a, Plant *b) {
    Plant temp = *a;
    *a = *b;
    *b = temp;
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
    switch (color) {
        case RED:
            return "red";
        case PINK:
            return "pink";
        case YELLOW:
            return "yellow";
        case WHITE:
            return "white";
        case BLUE:
            return "blue";
        default:
            return "unknown";
    }
}
char *getFlowerTypeText(FlowerType type) {
    switch (type) {
        case ROSE:
            return "rose";
        case IRIS:
            return "iris";
        case CARNATION:
            return "carnation";
        case PEONY:
            return "peony";
        case DAFFODIL:
            return "daffodil";
        case LILY:
            return "lily";
        default:
            return "unknown";
    }
}

FlowerType askFlowerType() {
    int type;
    bool valid = false;
    printf(
        "Flower type: "
        "\n1.Rose\n2.Iris\n3.Carnation\n4.Peony\n5.Daffodil\n6.Lily\nEnter: ");
    do {
        scanf("%i", &type);
        valid = validateTypeInput(type);
        if (!valid) {
            printf("Unknown type!\n");
        }
    } while (!valid);
    return type;
}

FlowerColor askFlowerColor() {
    int color;
    bool valid = false;
    printf(
        "Flower color: "
        "\n31.Red\n33.Yellow\n34.Blue\n35.Pink\n37.White\nEnter: ");
    do {
        scanf("%i", &color);
        valid = validateColorInput(color);
        if (!valid) {
            printf("Unknown color!\n");
        }
    } while (!valid);
    return color;
}
