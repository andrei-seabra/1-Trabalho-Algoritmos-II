/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo:Andrei Amasilio Seabra RA: 15826294639 - Pedro Antônio Anastácio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 3 - Este programa calcula a média de 3 notas, aritmética e ponderada.
*/

#include <stdio.h>

float calculateAverage(float grade1, float grade2, float grade3, char letter) {
    switch (letter) {
    case 'A':
        return (grade1 + grade2 + grade3) / 3; // calculate the average of the 3 grades

        break;
    case 'P':
        return ((grade1 * 5) + (grade2 * 3) + (grade3 * 2)) / 10; // calculates the weighted average of the grades

        break;
    default:
        return -1;
        break;
    }
}

void main() {
    float grade1 = 0, grade2 = 0, grade3 = 0, average = 0;
    char letter;

    printf("Nota da 1 prova: ");
    scanf("%f", &grade1);

    printf("\nNota da 2 prova: ");
    scanf("%f", &grade2);

    printf("\nNota da 3 prova: ");
    scanf("%f", &grade3);

    printf("\n---- Calcular media ----\n'A' para aritmetica\n'P' para ponderada\nMedia desejada:");
    scanf(" %c", &letter);

    average = calculateAverage(grade1, grade2, grade3, letter);

    if (average != -1) {
        printf("\nMedia: %.2f", average);
    } else {
        printf("\nOpcao invalida.");
    }
}