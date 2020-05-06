#include <stdio.h>

int main() {
    char m[7][7];

    //imprime a configurção inicial
    printf("        o---o---o        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        o---o---o        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("A---o---o---Z---o---o---K\n");
    printf("|   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |\n");
    printf("B---o---o---o---o---o---J\n");
    printf("|   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |\n");
    printf("C---D---E---F---G---H---I\n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        L---M---N        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        O---P---Q        \n");
    
    //tabuleiro pra imprimir as jogadas    
    printf("        %c---%c---%c        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        %c---%c---%c        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("%C---%c---%c---%c---%c---%c---%c\n");
    printf("|   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |\n");
    printf("%C---%c---%c---%c---%c---%c---%c\n");
    printf("|   |   |   |   |   |   |\n");
    printf("|   |   |   |   |   |   |\n");
    printf("%C---%c---%c---%c---%c---%c---%c\n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        %c---%c---%c        \n");
    printf("        |   |   |        \n");
    printf("        |   |   |        \n");
    printf("        %c---%c---%c        \n");




return(0);
}
