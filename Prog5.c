/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo:Andrei Amasilio Seabra RA> 15826294639 - Pedro Antônio Anastácio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 5 - Este programa faz o gerenciomento de produtos.
*/

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 100
#define EXPIRATION_LENGTH 10

struct product {
    char productName[NAME_LENGTH];
    float productPrice;
    int productQuantity;
    char productExpirationDate[EXPIRATION_LENGTH];
};

struct product registerProduct(char name[], float price, int quantity, char expirationDate[]) {
    struct product newProduct;

    strcpy(newProduct.productName, name);
    newProduct.productPrice = price;
    newProduct.productQuantity = quantity;
    strcpy(newProduct.productExpirationDate, expirationDate);

    return newProduct;
}

struct product searchProduct(struct product registeredProducts[], int productIndex, char name[], float price) {
    struct product searchedProduct;

    for (int i = 0; i < productIndex; i++) {
        if (strcmp(registeredProducts[i].productName, name) == 0 || registeredProducts[i].productPrice == price) {
            searchedProduct = registeredProducts[i];
            return searchedProduct;
        }
    }
}

void showProductInfo(struct product selectedProduct) {
    printf("\nInformacoes sobre %s:\nPreco: %f\nEstoque: %d\nData de validade: %s", selectedProduct.productName, selectedProduct.productPrice, selectedProduct.productQuantity, selectedProduct.productExpirationDate);
}

void updateProduct(struct product selectedProduct, struct product registeredProducts[], int productIndex) {
    char newName[NAME_LENGTH], newExpirationDate[EXPIRATION_LENGTH];
    int newQuantity = -1;
    float newPrice = -1;

    printf("\nPara manter o valor atual digite '-1'");

    printf("\nDigite o novo nome: ");
    scanf("%s", newName);

    if (strcmp(newName, "-1") != 0) {
        strcpy(selectedProduct.productName, newName);
    }

    printf("\nDigite o novo preco: ");
    scanf("%f", &newPrice);

    if (newPrice != -1) {
        selectedProduct.productPrice = newPrice;
    }

    printf("\nDigite a nova quantidade: ");
    scanf("%d", &newQuantity);

    if (newQuantity != -1) {
        selectedProduct.productQuantity = newQuantity;
    }

    printf("\nDigite a nova data de validade: ");
    scanf("%s", newExpirationDate);

    if (strcmp(newExpirationDate, "-1") != 0) {
        strcpy(selectedProduct.productExpirationDate, newExpirationDate);
    }

    printf("\nProduto atualizado com sucesso.");
}

int getOption() {
    int option = 0;

    printf("\n\n---- Menu ----\n1- Adicionar novo produto\n2- Atualizar produto\n3- Buscar produto\n4- Sair do sistema\nOpcao desejada: ");
    scanf("%d", &option);

    return option;
}

void main() {
    struct product registeredProducts[NAME_LENGTH];
    struct product selectedProduct;

    int option = 0, productIndex = 0, searchOption = 0, quantity = 0;
    float price = 0;

    char name[NAME_LENGTH], expirationDate[EXPIRATION_LENGTH];

    option = getOption();

    while (option != 4) {        
        switch (option) {
            case 1:
                printf("\n---- Cadastro de produto ----");

                printf("\nDigite o nome do produto: ");
                scanf("%s", name);

                printf("\nDigite o preco do produto: ");
                scanf("%f", &price);

                printf("\nDigite a quantidade desse produto: ");
                scanf("%d", &quantity);

                printf("\nDigite a data de validade do produto: ");
                scanf("%s", expirationDate);

                registeredProducts[productIndex] = registerProduct(name, price, quantity, expirationDate);
                productIndex++;

                break;
            case 2:
                printf("\n---- Busca de produto ----\n1- Pelo nome do produto\n2- Pelo preco do produto\nOpcao desejada: ");
                scanf("%d", &searchOption);

                if (searchOption == 1) {
                    char searchedName[NAME_LENGTH];

                    printf("\nDigite o nome do produto: ");
                    scanf("%s", searchedName);

                    selectedProduct = searchProduct(registeredProducts, productIndex, searchedName, 0);

                    updateProduct(selectedProduct, registeredProducts, productIndex);
                } else if (searchOption == 2) {
                    float searchedPrice;

                    printf("\nDigite o preco do produto: ");
                    scanf("%f", &searchedPrice);

                    selectedProduct = searchProduct(registeredProducts, productIndex, NULL, searchedPrice);

                    updateProduct(selectedProduct, registeredProducts, productIndex);
                } else {
                    printf("\nOpcao invalida.");
                }

                break;
            case 3:
                printf("\n---- Busca de produto ----\n1- Pelo nome do produto\n2- Pelo preco do produto\nOpcao desejada: ");
                scanf("%d", &searchOption);

                if (searchOption == 1) {
                    char searchedName[NAME_LENGTH];

                    printf("\nDigite o nome do produto: ");
                    scanf("%s", searchedName);

                    selectedProduct = searchProduct(registeredProducts, productIndex, searchedName, 0);

                    showProductInfo(selectedProduct);
                } else if (searchOption == 2) {
                    float searchedPrice;

                    printf("\nDigite o preco do produto: ");
                    scanf("%f", &searchedPrice);

                    selectedProduct = searchProduct(registeredProducts, productIndex, NULL, searchedPrice);

                    showProductInfo(selectedProduct);
                } else {
                    printf("\nOpcao invalida.");
                }

                break;
            default:
                printf("\nOpcao invalida.");
                break;
        }

        option = getOption();
    }

    printf("\nSaindo...");
}