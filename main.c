#include "plant.h"

void main()
{
    int size = 0;
    Plant *plants = malloc(sizeof(Plant) * size);

    Plant redRose = {"Red rose", 1.72, ROSE, RED, 4};
    Plant yellowDaffodil = {"Yellow daffodil", 1.65, DAFFODIL, YELLOW, 12};
    Plant pinkLily = {"Pink lily", 1.12, LILY, PINK, 6};

    addPlant(plants, &size, redRose);
    addPlant(plants, &size, yellowDaffodil);
    addPlant(plants, &size, pinkLily);

    Plant plant = getPlantFromInput();
    // addPlant(plants, &size, plant);

    displayFlowers(plants, size);
    printf("\n\n");

    sortByFlowersCount(plants, size);
    displayFlowers(plants, size);
    printf("\n\n");

    sortByPlant(plants, size);
    displayFlowers(plants, size);
    printf("\n\n");
}