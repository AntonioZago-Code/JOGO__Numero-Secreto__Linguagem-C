#include <stdio.h> // Biblioteca padrão da linguagem C
#include <stdlib.h> // Biblioteca para gerar números aleatórios (rand())
#include <Windows.h> // Biblioteca para usar o Sleep() em milissegundos (1000 para aguradar 1 segundo)
#include <time.h>


void game()
{
	int user_number;
	char restart;

	srand(time(NULL));
	int rand_number = rand() % 100 + 1;

	int tentativa = 1;
	const int max_tentativas = 10;

	while (tentativa <= max_tentativas)
	{
		printf("\nTentativa %i: ", tentativa);
		scanf_s("%i", &user_number);

		if (user_number < rand_number)
		{
			printf("Numero secreto e MAIOR!\n");
		}

		else if (user_number > rand_number)
		{
			printf("Numero secreto e MENOR!\n");
		}

		else
		{
			printf("\nPARABENS CONSEGUIU ACERTAR COM %i!!\n", tentativa);

			printf("\nGostaria de jogar novamente? Digite 's' para sim ou 'n' para nao: ");
			do
			{
				scanf_s(" %c", &restart);

				if (restart == 's')
				{
					printf("Perfeito!! Reinicando tentativas...\n");
					Sleep(2000);
					game();
				}
				else if (restart == 'n')
				{ 
					printf("\nSem problemas!! Fique a vontade para jogar novamente");
					return;
				}
				else
				{
					printf("\nOpcao invalida!! Digite 's' para sim ou 'n' para nao: ");
				}

			} while (restart != 's' && restart != 'n');
		}


		tentativa++;

		if (tentativa > max_tentativas)
		{
			printf("\nInfelizmente nao conseguiu acertar! O numero era %i.\n", rand_number);

			printf("\nGostaria de jogar novamente?\nDigite 's' para sim ou 'n' para nao: ");
			do
			{
				scanf_s(" %c", &restart);

				if (restart == 's')
				{
					printf("\nPerfeito!! Reinicando tentativas...\n");
					Sleep(2000);
					game();
				}
				else if (restart == 'n')
				{
					printf("\nSem problemas!! Fique a vontade para jogar novamente\n");
					return;
				}
				else
				{
					printf("\nOpcao invalida!! Digite 's' para sim ou 'n' para nao: ");
				}

			} while (restart != 's' && restart != 'n');
		}
	}
}

int main(void)
{
	char start;

	printf("\nEsta pronto para comecar o jogo e tentar acertar o numero secreto com apenas 10 tentaivas?\n");
	printf("Digite 's' para sim ou 'n' para nao: ");

	do
	{
		scanf_s(" %c", &start);

		if (start == 's')
		{
			game();
		}

		else if (start == 'n')
		{
			printf("\nEntendido!! Nos vemos na proxima :)!\n");
		}

		else
		{
			printf("\nOpcao invalida! Digite 's' para sim ou 'n' para nao: ");
		}

	} while (start != 's' && start != 'n');
}
