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

int casa_adjacente_raposa (int i, int j) { //verifica se o movimento da raposa pode ser executado
    char tab[7][7];
    
    if (temdiagonal(i, j) == 1) {
        if (tab[i-1][j-1] == 'Z' || tab[i+1][j+1] == 'Z' || tab[i+1][j-1] == 'Z' || tab[i-1][j+1] == 'Z' || tab[i+1][j] == 'Z' || tab[i-1][j] == 'Z' || tab[i][j+1] == 'Z' || tab[i][j-1] == 'Z') {
            return 1; //casa eh adjacente a raposa
        }
        return -1; //casa nao eh adjacente a raposa
    }
    else {
        if (tab[i][j-1] == 'Z' || tab[i][j+1] == 'Z' || tab[i-1][j] == 'Z' || tab[i+1][j] == 'Z') {
            return 1; //casa eh adjacente a raposa
        }
        return -1; //casa nao eh adjacente a raposa
    }
}


int casa_adjacente_ganso (char ganso, int i, int j) { //verfica se o movimento do ganso pode ser executado
    char tab[7][7];
    
    if (temdiagonal(i, j) == 1) {
        if (tab[i-1][j-1] == ganso || tab[i+1][j+1] == ganso || tab[i+1][j-1] == ganso || tab[i-1][j+1] == ganso || tab[i+1][j] == ganso || tab[i-1][j] == ganso || tab[i][j+1] == ganso || tab[i][j-1] == ganso) {
            return 1; //casa eh adjacente ao ganso
        }
        return -1; //casa nao eh adjacente ao ganso
    }
    else {
        if (tab[i][j-1] == ganso || tab[i][j+1] == ganso || tab[i-1][j] == ganso || tab[i+1][j] == ganso) {
            return 1; //casa eh adjacente ao ganso
        }
        return -1; //casa nao eh adjacente ao ganso
    }
}


int main(void) {
	int i, j, a, b;
        char m[7][7] = {{"  ooo  "}, {"  ooo  "}, {"AooZooK"}, {"BoooooJ"}, {"CDEFGHI"}, {"  LMN  "}, {"  OPQ  "}}; //Configuração Inicial
	imprimir(m);
	
	do {
	    do {
	        printf("vez da raposa, digite as coordenadas da casa para qual deseja se movimentar: ");
	        scanf("%d %d", &i, &j);
	    } while (casaehvalida(m[i][j]) == -1 || casa_adjacente_raposa(i, j) == -1);
            system ("clear");
            m[i][j] = 'Z';
            //falta a casa antiga da raposa receber 'o'
	    imprimir(m);
	    
	    do {
            printf("vez dos gansos, digite as coordenadas do ganso que deseja movimentar: ");
            scanf("%d %d", &a, &b);
	    } while (m[a][b] == 'Z' || m[a][b] == 'o' ); //falta o caso das coordenadas serem fora do tabuleiro
	    do {
            printf("agora digite as coordenadas da casa para qual deseja se movimentar: ");
            scanf("%d %d", &i, &j);
            } while (casaehvalida(m[i][j]) == -1 || casa_adjacente_ganso(ganso, i, j) == -1);
            system ("clear");
            m[i][j] = ganso;
            m[a][b] = 'o';
            imprimir(m);
        
	} while (vitoria_raposa == -1 && vitoria_ganso == -1); 


  return 0;
}
