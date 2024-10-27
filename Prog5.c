/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo:Andrei Amasilio Seabra RA> 15826294639 - Pedro Antônio Anastácio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 5 - Este programa faz o gerenciomento de produtos.
*/

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 100
#define EXPIRATION_LENGTH 11
#define PRODUCTS_LENGTH 100

struct product {
    char name[NAME_LENGTH];
    float price;
    int quantity;
    char expirationDate[EXPIRATION_LENGTH];
};

int getOption() {
    /*
        This function gets the user input to get his option and returns it.
    */

    int option = 0;

    printf("\n---- Menu ----\n1- Cadastrar produto\n2- Atualizar produto\n3- Buscar produto\n4- Sair\nOpcao desejada: ");
    scanf(" %d", &option);

    return option;
}

int registerProduct(char productName[NAME_LENGTH], float productPrice, int productQuantity, char productExpirationDate[EXPIRATION_LENGTH], int productIndex, struct product products[]) {
    /*
        This function registers a new product to the products array.
        Paramenters: represents the product's name, price, quantity and expiration date, also the index of the products array and the products array.
    */

    struct product newProduct;
    
    strcpy(newProduct.name, productName);
    newProduct.price = productPrice;
    newProduct.quantity = productQuantity;

    if (strcmp(productExpirationDate, "-1") == 0) {
        strcpy(newProduct.expirationDate, "nao info.");
    } else {
        strcpy(newProduct.expirationDate, productExpirationDate);
    }

    products[productIndex] = newProduct;

    return ++productIndex;
}

int searchProduct(int productIndex, struct product products[], char searchedName[], float minPrice, float maxPrice) {
    /*
        This function searchs a product by it's name or price range, and gets it's index and return it.
        Paramenters: represents the index of the products array, the products array, the name searched, the minimum price and maximum price.
    */

    int i, searchedProductIndex;
    
    for (i = 0; i < productIndex; i++) {
        if (strcmp(products[i].name, searchedName) == 0 || products[i].price >= minPrice && products[i].price <= maxPrice) {
            searchedProductIndex = i;
            break;
        } else {
            searchedProductIndex = PRODUCTS_LENGTH + 1;
        }
    }

    return searchedProductIndex;
}

void showSearchedProduct(struct product products[], int productIndex) {
    /*
        This function displays to the user the searched product's information.
        Paramenters: represents the products array and the index of it.
    */

    struct product searchedProduct = products[productIndex];

    printf("\nInformacoes sobre o(a) %s:\nPreco: %.2f\nQuantidade: %d\nValidade: %s\nId: %d", searchedProduct.name, searchedProduct.price, searchedProduct.quantity, searchedProduct.expirationDate, productIndex);
}

void updateProduct(struct product products[], int productIndex, char newName[], float newPrice, int newQuantity, char newExpirationDate[]) {
    /*
        This function updates the information of a given product.
        Paramenters: represents the products array, the index of it, the new name, price, quantity and expiration date of the product.
    */

    if (strcmp(newName, "-1") != 0) {
        strcpy(products[productIndex].name, newName);
    }
    
    if (newPrice != -1) {
        products[productIndex].price = newPrice;
    }
    
    if (newQuantity != -1) {
        products[productIndex].quantity = newQuantity;
    }
    
    if (strcmp(newExpirationDate, "-1") != 0) {
        strcpy(products[productIndex].expirationDate, newExpirationDate);
    }
}

void main() {
    int option = 0, productIndex = 0, searchedProductIndex = 0, quantity = 0, searchOption = 0;
    char name[NAME_LENGTH], expirationDate[EXPIRATION_LENGTH], searchedName[NAME_LENGTH];
    float price = 0, minPrice = 0, maxPrice = 0;
    struct product products[PRODUCTS_LENGTH];

    option = getOption();

    while (option != 4) {
        switch (option) {
        case 1:
            printf("\n---- Cadastrar produto ----");

            printf("\nDigite o nome: ");
            scanf(" %s", name);

            printf("\nDigite o preco: ");
            scanf(" %f", &price);

            printf("\nDigite a quantidade em estoque: ");
            scanf(" %d", &quantity);

            printf("\nPara omitir a data de validade digite '-1'.");

            printf("\nDigite a data de validade: ");
            scanf(" %s", expirationDate);

            productIndex = registerProduct(name, price, quantity, expirationDate, productIndex, products);

            printf("\nProduto cadastrado.");
            break;
        case 2:
            printf("\n---- Atualizar produto ----");

            printf("\nMetodo de busca:\n1- Nome\n2- Faixa de preco\nOpcao desejada: ");
            scanf(" %d", &searchOption);

            if (searchOption == 1) { // search by name
                printf("\nDigite o nome do produto: ");
                scanf(" %s", searchedName);

                searchedProductIndex = searchProduct(productIndex, products, searchedName, -1, -1);
            } else if (searchOption == 2) { // search by price range
                printf("\nDigite o preco minimo: ");
                scanf(" %f", &minPrice);

                printf("\nDigite o preco maximo: ");
                scanf(" %f", &maxPrice);

                searchedProductIndex = searchProduct(productIndex, products, searchedName, minPrice, maxPrice);
            } else {
                printf("\nOpcao invalida.");
            }

            if (searchedProductIndex < 0 || searchedProductIndex >= productIndex) {
                printf("\nProduto nao encontrado.");
                break;
            }

            printf("\nPara manter os dados digite '-1'.");

            printf("\nDigite o nome: ");
            scanf(" %s", name);

            printf("\nDigite o preco: ");
            scanf(" %f", &price);

            printf("\nDigite a quantidade em estoque: ");
            scanf(" %d", &quantity);

            printf("\nDigite a data de validade: ");
            scanf(" %s", expirationDate);

            updateProduct(products, searchedProductIndex, name, price, quantity, expirationDate);

            printf("\nProduto atualizado.");
            break;
        case 3:
            printf("\n---- Buscar produto ----");

            printf("\nMetodo de busca:\n1- Nome\n2- Faixa de preco\nOpcao desejada: ");
            scanf(" %d", &searchOption);

            if (searchOption == 1) { // search by name
                printf("\nDigite o nome do produto: ");
                scanf(" %s", searchedName);

                searchedProductIndex = searchProduct(productIndex, products, searchedName, -1, -1);

                if (searchedProductIndex < 0 || searchedProductIndex >= productIndex) {
                    printf("\nProduto nao encontrado.");
                    break;
                }

                showSearchedProduct(products, searchedProductIndex);
            } else if (searchOption == 2) { // search by price range
                printf("\nDigite o preco minimo: ");
                scanf(" %f", &minPrice);

                printf("\nDigite o preco maximo: ");
                scanf(" %f", &maxPrice);

                searchedProductIndex = searchProduct(productIndex, products, searchedName, minPrice, maxPrice);

                if (searchedProductIndex < 0 || searchedProductIndex >= productIndex) {
                    printf("\nProduto nao encontrado.");
                    break;
                }

                showSearchedProduct(products, searchedProductIndex);
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