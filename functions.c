#include "functions.h"

Product parseLine(char *);
void printResult(Result);
void saveResult(Result, FILE *);


int getProducts(char *fileName, Product p[]) {
    FILE *fp;
    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
        printf("Cannot open file %s", fileName);
        return -1;
    }

    int i = 0;
    while (!feof(fp)) {
        char lineBuffer[100];
        fgets(lineBuffer, sizeof(lineBuffer), fp); // read one line to buffer
        p[i] = parseLine(lineBuffer);
        i++;
    }
    fclose(fp);
    return i;
}

Product parseLine(char *line) {
    Product p;
    sscanf(line, "%s %f %d", p.name, &p.price, &p.amount);
    return p;
}

float getMoney(char *message) {
    float money;
    do {
        printf("%s", message);
        scanf("%f", &money);
    } while (money <= 0);
    return money;
}

void calculateResults(float money, int numProducts, Product p[], Result r[]) {
    int i = 0;
    for(i = 0; i < numProducts; i++) {
        r[i].price = p[i].price;
        r[i].amount = money / p[i].price;
        if(r[i].amount > p[i].amount) {
            r[i].amount = p[i].amount;
        }
        strcpy(r[i].name, p[i].name);
    }
}

void outputResults(char * filename, int numResults,  Result r[]) {
    for (int i = 0; i < numResults; i++) {
        printResult(r[i]);
    }

    FILE *fp;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed saving the results to %s", filename);
        return;
    }

    for (int i = 0; i < numResults; i++) {
        saveResult(r[i], fp);
    }

    fclose(fp);
    printf("Results saved to %s", filename);
}

void printResult(Result r) {
    if(r.amount == 0) {
        printf("%-8s - No products can be purchased \n", r.name);
    } else {
        printf("%-8s - %.2f x %d\n", r.name, r.price, r.amount);
    }

}

void saveResult(Result t, FILE *fp) {
    if(t.amount == 0) {
        fprintf(fp, "%-8s - No products can be purchased \n", t.name);
    } else {
        fprintf(fp, "%-8s - %.2f x %d\n", t.name, t.price, t.amount);
    }
}
