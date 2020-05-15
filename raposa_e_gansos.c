#include <stdio.h>

void imprimir(char tab[7][7]){ //Imprime o tabuleiro de uma forma agradável ao usuário
	int i, j;
	for (i= 0; i < 7; i++){ 
		for (j = 0; j < 7; j++){ 
			if(tab[i][j] == ' '){
				printf("%c   ", tab[i][j]);
				continue;
			}
			printf("%c", tab[i][j]);
			if (j != 6){
				printf("---");
			}
		}

		printf("\n\n\n");
	}
}
int casaehvalida(char casa){ //Verifica se a casa do movimento selecionado está livre e faz parte do tabuleiro
	if (casa != 'o'){ 
		return -1;
	}
	return 1;
}
int temdiagonal(int i, int j){ //Verifica se a casa atual permite movimentos diagonais
	if (i == 0 || i == 2 || i == 4 || i == 6){ 
		if (j % 2 == 0){ //Em casas de linha par (começando a partir de zero), colunas pares permitem movimento diagonal
			return 1; //Permite movimento diagonal
		}
		return -1; //Não permite movimento diagonal
	}
	else{ 
		if (j % 2 != 0){ //Em casas de linha ímpar, colunas ímpares permitem movimento diagonal 
			return 1; //Permite movimento diagonal
		}
		return -1; //Não permite movimento diagonal
	}
}


int main(void) {
  char m[7][7] = {{"  ooo  "}, {"  ooo  "}, {"AooZooK"}, {"BoooooJ"}, {"CDEFGHI"}, {"  LMN  "}, {"  OPQ  "}}; //Configuração Inicial
	imprimir(m);

  return 0;
}
