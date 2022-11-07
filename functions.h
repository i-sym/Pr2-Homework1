#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define MAX_NAME_SIZE 40
#define MAX_PRODUCT_NUMBER 15

#define INPUT_FILE "F1.txt"
#define OUTPUT_FILE "F2.txt"

typedef struct Product {
    char name[MAX_NAME_SIZE];
    float price;
    int amount;
} Product;

typedef struct Result {
    char name[MAX_NAME_SIZE];
    float price;
    int amount;
} Result;

int getProducts(char *, Product[]);
float getMoney(char *);
void calculateResults(float, int, Product [], Result []);
void outputResults(char *, int, Result []);

#endif // FUNCTIONS_H