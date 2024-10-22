/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo: Andrei Amasilio Seabra RA: 15826294639 – Pedro Antonio Anastacio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 1 - Este programa calcula a média de 4 notas e contabiliza faltas.
*/

#include <stdio.h>

float averageCalculator(float grade1,float grade2,float grade3,float grade4) {
    /*
        This function calculates the average of the 4 given grades and returns it.
        Paramenters: represents the 4 grades of the student.
    */

    return (grade1 + grade2 + grade3 + grade4) / 4;
}

void showResults(float average, int missedClass) {
    /*
        This function displays to the user the student's situation.
        Paramenters: represents the average of the student's grades and the quantity of classes that he/she missed.
    */

    if (average >= 7 && missedClass <= 36) {
        printf("O aluno foi aprovado\n");
    } else if (average >= 4 && missedClass <= 36) {
        printf("O aluno foi exame final\n");
    } else if (average < 4 || missedClass > 36) {
        printf("O aluno foi reprovado\n");
    }
}

void main(){
    float grade1 = 0, grade2 = 0, grade3 = 0, grade4 = 0, average = 0;
    int missedClass = 0;

    printf("Entre com a nota do primeiro bimestre: ");
    scanf("%f", &grade1);

    printf("Entre com a nota do segundo bimestre: ");
    scanf("%f", &grade2);

    printf("Entre com a nota do terceiro bimestre: ");
    scanf("%f", &grade3);

    printf("Entre com a nota do quarto bimestre: ");
    scanf("%f", &grade4);

    printf("Entre com o numero de faltas do aluno: ");
    scanf("%d", &missedClass);

    average = averageCalculator(grade1, grade2, grade3, grade4);

    showResults(average, missedClass);
}