/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo: Andrei Amasilio Seabra RA: 15826294639 – Pedro Antonio Anastacio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 1 - Este programa calcula a média de 4 notas e contabiliza faltas.
*/

#include <stdio.h>

float readValues(float grade1,float grade2,float grade3,float grade4, float avarege, int missedClass){

    avarege = (grade1 + grade2 + grade3 + grade4) / 4;

    if (avarege >= 7 && missedClass <= 36){
        printf("O Aluno foi Aprovado\n");
    }
    else if (avarege >= 4 && missedClass <= 36){
        printf("O Aluno foi Exame Final\n");
    }
    else if (avarege < 4 || missedClass > 36){
        printf("O Aluno foi Reprovado\n");
    }

    return avarege;
}
void main(){
    float grade1 = 0, grade2 = 0, grade3 = 0, grade4 = 0, avarege = 0;
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

    printf("A media e do aluno e: %.2f", readValues(grade1, grade2, grade3, grade4, avarege, missedClass));
}