/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo:Andrei Amasilio Seabra RA: 15826294639 - Pedro Antônio Anastácio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 4 - Este programa gerencia a compra de bilhetes de cinema.
*/

#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 9

#define VIP_PRICE 80
#define NORMAL_PRICE 40

#define OWNED 1
#define NOT_OWNED 0

struct seatPosition {
    char row;
    int column;
};

int getOption() {
    /*
        This function gets the user input to get his option and returns it.
    */

    int option = 0;

    printf("\n---- Menu ----\n1- Visualizar sessao\n2- Comprar bilhete\n3- Sair do sistema\nDigite a opcao desejada: ");
    scanf(" %d", &option);

    return option;
}

void showAvailableSeats(int layout[ROWS][COLUMNS], int i) {
    /*
        This function displays to the user the seats that are still available of each row.
        Paramenters: represents the seats layout and the index of the for loop.
    */

    int j;

    for (j = 0; j < COLUMNS; j++) {
        if (layout[i][j] == NOT_OWNED) {
            printf("[O] ");
        }
        else {
            printf("[X] ");
        }
    }
}

void showSeats(int layout[ROWS][COLUMNS]) {
    /*
        This function displays the seats layout.
        Paramenter: represents the seats layout.
    */

    int i;

    for (i = 0; i < ROWS; i++) {
        switch (i) {
        case 0:
            printf("\nA: ");

            showAvailableSeats(layout, i);

            break;
        case 1:
            printf("\nB: ");

            showAvailableSeats(layout, i);

            break;
        case 2:
            printf("\nC: ");

            showAvailableSeats(layout, i);

            break;
        case 3:
            printf("\nD: ");

            showAvailableSeats(layout, i);

            break;
        case 4:
            printf("\nE: ");

            showAvailableSeats(layout, i);

            break;
        }
    }
}

void showPrice(int row) {
    /*
        This function displays the price of the reservation.
        Paramenter: represents the row of the reserved seat.
    */

    switch (row) {
    case 0:
    case 1:
        printf("\nAssento reservado.\nTotal R$%d", VIP_PRICE);
        break;
    case 2:
    case 3:
    case 4:
        printf("\nAssento reservado.\nTotal: R$%d", NORMAL_PRICE);
        break;
    }
}

int getRow(char rowLetter) {
    /*
        This function checks and converts the row letter into the index of it and returns it.
        Paramenters: represents the letter of ther row.
    */

    int row = 0;

    switch (rowLetter) {
    case 'A':
        row = 0;
        break;
    case 'B':
        row = 1;
        break;
    case 'C':
        row = 2;
        break;
    case 'D':
        row = 3;
        break;
    case 'E':
        row = 4;
        break;
    default:
        row = ROWS + 1;
        break;
    }

    return row;
}

int getColumn(int columnNumber) {
    /*
        This function checks the number of the column and returns it.
        Paramenter: represents the column number.
    */

    int j, column = 0;

    for (j = 0; j < COLUMNS; j++) {
        if (columnNumber == j) {
            column = j;
            break;
        }
        else {
            column = COLUMNS + 1;
        }
    }

    return column;
}

void checkSeatAvailability(int row, int column, int seatAvailability) {
    /*
        This function checks if the seat exits and if it's not owned.
        Paramenters: represents the row, column and availability of the seat.
    */

    if (row == (ROWS + 1) || column == (COLUMNS + 1)) {
        printf("\nAssento nao encontrado.");
    }

    if (seatAvailability == OWNED) {
        printf("\nAssento indisponivel.");
    } else {
        showPrice(row);
    }
}

void buySeats(int row, int column, int layout[ROWS][COLUMNS]) {
    /*
        This function sets the state of the seat as onwed.
        Paramenters: represents the row and column of the seat, also the seats layout.
    */

    checkSeatAvailability(row, column, layout[row][column]);

    layout[row][column] = OWNED;
}

void main() {
    int i, j, layout[ROWS][COLUMNS], row, column, option = 0;
    struct seatPosition chosenSeat;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            layout[i][j] = NOT_OWNED;
        }
    }

    option = getOption();

    while (option != 3) {
        switch (option) {
        case 1:
            showSeats(layout);
            break;
        case 2:
            printf("\n---- Comprar bilhete ----");

            showSeats(layout);

            printf("\nVIP: 'A' e 'B' | NORMAL: 'C', 'D' e 'E'");

            printf("\nDigite o assento desejado (Ex: A5): ");
            scanf(" %c%d", &chosenSeat.row, &chosenSeat.column);

            row = getRow(chosenSeat.row);
            column = getColumn(chosenSeat.column);

            buySeats(row, column, layout);

            break;
        default:
            printf("\nOpcao invalida.");
            break;
        }

        option = getOption();
    }

    printf("\nSaindo...");
}