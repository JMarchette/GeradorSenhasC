/* Projeto de calculo de salarios
Grupo composto por: Gustavo Hideki Takeuchi, Joao V L Marchette, Vinicius Kazuo Takeuchi */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar senha
char* geraSenha(char tipo, int tamanho) 
{
    char* senha = (char*)malloc(tamanho + 1);
    if (senha == NULL) 
	{
        return NULL;
    }

    for (int i = 0; i < tamanho; i++) {
        switch (tipo) {
            case 'a': // Numérica
                senha[i] = '0' + rand() % 10;
                break;
            case 'b': // Alfabética
                if (rand() % 2) {
                    senha[i] = 'A' + rand() % 26;
                } else {
                    senha[i] = 'a' + rand() % 26;
                }
                break;
            case 'c': // Alfanumérica 1
                if (rand() % 2) {
                    senha[i] = 'A' + rand() % 26;
                } else {
                    senha[i] = '0' + rand() % 10;
                }
                break;
            case 'd': // Alfanumérica 2
                switch (rand() % 3) {
                    case 0:
                        senha[i] = 'A' + rand() % 26;
                        break;
                    case 1:
                        senha[i] = 'a' + rand() % 26;
                        break;
                    case 2:
                        senha[i] = '0' + rand() % 10;
                        break;
                }
                break;
            case 'e': // Geral
                switch (rand() % 8) {
                    case 0:
                        senha[i] = 'A' + rand() % 26;
                        break;
                    case 1:
                        senha[i] = 'a' + rand() % 26;
                        break;
                    case 2:
                        senha[i] = '0' + rand() % 10;
                        break;
                    case 3:
                        senha[i] = '-';
                        break;
                    case 4:
                        senha[i] = '_';
                        break;
                    case 5:
                        senha[i] = ':';
                        break;
                    case 6:
                        senha[i] = '@';
                        break;
                    case 7:
                        senha[i] = '#';
                        break;
                }
                break;
        }
    }

    senha[tamanho] = '\0';
    return senha;
}

int main() 
{
    FILE* entrada, * saida;
    char matricula[7];
    char tipoSenha;
    int tamanhoSenha;

    srand(time(NULL));

	printf("Projeto gerador de senhas ILP-501\n");
	printf("Grupo: Gustavo Hideki Takeuchi, Joao V L Marchette, Vinicius Kazuo Takeuchi\n\n");

	printf("Tipos de senha:\n Tipo a: Numerica\n Tipo b: Alfabetica\n Tipo c: Alfanumerica 1\n tipo d: Alfanumerica 2\n Tipo e: Geral\n\n");
    printf("Informe o tipo de senha (a, b, c, d, e): ");  
    scanf(" %c", &tipoSenha);
    
    int valido = 1;
	if (tipoSenha != 'a' && tipoSenha != 'b' && tipoSenha != 'c' && tipoSenha != 'd' && tipoSenha != 'e') 
	{
	    valido = 0;
	    while (valido == 0) 
		{
	        printf("Entrada invalida! Insira o tipo de senha novamente:\n");
	        scanf(" %c", &tipoSenha);
	
	        if (tipoSenha == 'a' || tipoSenha == 'b' || tipoSenha == 'c' || tipoSenha == 'd' || tipoSenha == 'e') 
			{
	            valido = 1;
	        }
	    }
	}
    printf("Informe o tamanho da senha: ");
    scanf("%d", &tamanhoSenha);


    entrada = fopen("MATR.TXT", "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo MATR.TXT\n");
        return 1;
    }

    saida = fopen("SENHAS.TXT", "w");
    if (saida == NULL) 
	{
        printf("Erro ao abrir o arquivo SENHAS.TXT\n");
        fclose(entrada);
        return 1;
    }
    fprintf(saida, "%-20s%-20s\n", "Matricula/RA", "Senha");

	while (fscanf(entrada, "%6s", matricula) == 1) 
	{
	    char* senha = geraSenha(tipoSenha, tamanhoSenha);
	    fprintf(saida, "%-20s%-20s\n", matricula, senha);
	    free(senha);
	}
	
	printf("Programa executado com sucesso! Verifique o arquivo 'SENHAS.TXT'");


    fclose(entrada);
    fclose(saida);

    return 0;
}

