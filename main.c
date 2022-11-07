#include <stdio.h>
#include <string.h>

#include "functions.h"

int main()
{
    Product p[MAX_PRODUCT_NUMBER];
    Result  r[MAX_PRODUCT_NUMBER];

    int numProducts = getProducts(INPUT_FILE, p);

    if(numProducts <= 0) {
        printf("No products found in file %s");
        return -1;
    }

    float money = getMoney("Enter money: ");

    calculateResults(money, numProducts, p, r);
    outputResults(OUTPUT_FILE, numProducts, r);
   
    return 0;
}
