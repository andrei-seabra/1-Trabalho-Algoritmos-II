/*
1º Trabalho da disciplina Algoritmos e Fundamentos da Programação II – Outubro/2024
Grupo:Andrei Amasilio Seabra RA: 15826294639 - Pedro Antônio Anastácio Borges RA: 12115138660
Status: funciona perfeitamente
Exercício 1 - Este programa faz apuração de votos.
*/

#include <stdio.h>

int getVote() {
    /*
        This function gets the user input to get his vote and returns it.
    */

    int vote = 0;

    printf("\nCandidatos:\n1- Candidato 1\n2- Candidato 2\n3- Candidato 3\n4- Candidato 4\n5- Nulo\n6- Em branco \n0- Sair\nSeu voto: ");
    scanf("%d", &vote);

    return vote;
}

void showResults(int candidate1, int candidate2, int candidate3, int candidate4, int null, int white) {
    /*
        This function displays to the user the number of votes that every candidate have.
        Paramenters: represents the quantity of votes of each candidate.
    */

    printf("\n---- Total de votos ----\nCandidato 1: %d voto(s)\nCandidato 2: %d voto(s)\nCandidato 3: %d voto(s)\nCandidato 4: %d voto(s)\nNulo:        %d voto(s)\nEm branco:   %d voto(s)", candidate1, candidate2, candidate3, candidate4, null, white);
}

void main() {
    int vote = 0, candidate1 = 0, candidate2 = 0, candidate3 = 0, candidate4 = 0, null = 0, white = 0;

    vote = getVote();

    while (vote != 0) {
        switch (vote) {
        case 1:
            printf("\nVoto para candidato 1 contabilizado.");
            candidate1++;

            vote = getVote();

            break;
        case 2:
            printf("\nVoto para candidato 2 contabilizado.");
            candidate2++;

            vote = getVote();

            break;
        case 3:
            printf("\nVoto para candidato 3 contabilizado.");
            candidate3++;

            vote = getVote();

            break;
        case 4:
            printf("\nVoto para candidato 4 contabilizado.");
            candidate4++;

            vote = getVote();

            break;
        case 5:
            printf("\nVoto nulo contabilizado.");
            null++;

            vote = getVote();

            break;
        case 6:
            printf("\nVoto em branco contabilizado.");
            white++;

            vote = getVote();

            break;
        default:
            printf("\nNumero do candidato invalido.");

            vote = getVote();

            break;
        }
    }

    showResults(candidate1, candidate2, candidate3, candidate4, null, white);
}