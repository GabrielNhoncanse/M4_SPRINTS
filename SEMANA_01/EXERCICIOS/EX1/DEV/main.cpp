#include <iostream>
#include <string>
#include <ctype.h> //biblioteca usada na função leComando (tolower)
#include <vector>

int converteSensor(float &valor, float &minimo, float &maximo)
{
	int max = maximo - minimo;
	int val = valor - minimo;

	int per;
	per = (val * 100) / max;
	std::cout << "O valor percentual é igual a " << per << "%\n";

	return per;
}

int leituraSensor(int min, int max)
{
	float valInserido;

	std::cout << "\n"
			  << "Insira um valor entre " << min << " e " << max << ":";
	std::cin >> valInserido;

	while (valInserido < min || valInserido > max)
	{
		std::cout << "O valor inserido é inválido, insira um valor entre " << min << " e " << max << ":";
		std::cin >> valInserido;
	}
	std::cout << "O valor inserido foi igual a " << valInserido << "\n";

	return valInserido;
}

int armazenaVetor(int *vetor, int tamanho, int posicao, int medida)
{
	if (posicao < tamanho)
	{
		vetor[posicao] = medida;
		return posicao + 1;
	}
	else
	{
		return posicao;
	}
}

char direcaoMenorCaminho(int *vetor, int &maiorDis)
{
	int maiorValor = vetor[0];
	for (int i = 0; i < 4; i++)
	{
		if (maiorValor < vetor[i])
		{
			maiorValor = vetor[i];
			switch (i)
			{
			case 1:
				return 'E';
				break;
			case 2:
				return 'F';
				break;
			case 3:
				return 'T';
				break;

			default:
				return 'D';
				break;
			}
		}
	}
	maiorDis = maiorValor;
}

int leComando()
{
	std::string resposta;

	std::cout << "Você deseja continuar o mapeamento?(SIM/NAO):\n";
	std::cin >> resposta;

	for (int i = 0; i < resposta.length(); i++)
	{
		resposta[i] = tolower(resposta[i]);
	}

	while (resposta != "sim" && resposta != "nao")
	{
		std::cout << "Resposta inválida, responda SIM ou NAO:";
		std::cin >> resposta;
		for (int i = 0; i < resposta.length(); i++)
		{
			resposta[i] = tolower(resposta[i]);
		}
	}

	if (resposta == "sim")
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{

	float minimo;
	float maximo;
	float valor;

	std::cout << "Escreva o numero mínimo: ";
	std::cin >> minimo;

	std::cout << "Escreva o numero máximo: ";
	std::cin >> maximo;
	while (maximo <= minimo)
	{
		std::cout << "O número máximo precisa ser maior que o mínimo, digite novamente:";
		std::cin >> maximo;
	}

	std::cout << "Escreva o valor: ";
	std::cin >> valor;

	while (valor < minimo || valor > maximo)
	{
		std::cout << "O valor inserido é inválido, insira um valor entre " << minimo << " e " << maximo << ":";
		std::cin >> valor;
	}

	converteSensor(valor, minimo, maximo);
	leituraSensor(minimo, maximo);

	int tamanhoVetor = 100;
	int posicao;
	int medida;
	int vetor[400];

	std::cout << "Indique a posição a ser inserido o valor:";
	std::cin >> posicao;
	std::cout << "Indique a medida a ser inserida no vetor:";
	std::cin >> medida;
	armazenaVetor(vetor, tamanhoVetor, posicao, medida);

	int maiorDis;
	direcaoMenorCaminho(vetor, maiorDis);

	leComando();

	return 0;
}