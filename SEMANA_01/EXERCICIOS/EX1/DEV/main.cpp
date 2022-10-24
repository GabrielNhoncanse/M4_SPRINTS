#include <iostream>
#include <string>
#include <ctype.h> //biblioteca usada no exercício 5 (tolower)
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

// 3 -  Implemente a função 'armazenaVetor' que receberá 4 argumentos: o
// ponteiro do vetor que receberá a medida, o tamanho do vetor, a posição atual para armazenamento
// e a medida para ser armazenada no vetor. A função deve armazenar a medida no vetor, segundo
// posição indicada (posição atual) e retornar a próxima posição para armazenamento futuro.
void armazenaVetor(int tamanho, int posicao, int medida)
{
	// std::cout << tamanho << posicao << medida;
}

// 4. Implemente a função 'direcaoMenorCaminho' que receberá 2 argumentos: (1) o
// ponteiro para um vetor e (2) o ponteiro para uma variável. Esta função deve avaliar 4
// valores do vetor, a partir do ponteiro (1) recebido. Os 4 valores representam as distâncias
// nos sentidos: Direta, Esquerda, Frente e Trás (esses valores foram inseridos com a função
//'leituraSensor', convertidos com a função 'converteSensor' e armazenados no vetor com a
// função 'armazenaVetor'). Esta função retorna o sentido de maior distância, e com base no
// ponteiro (2) para a variável, nela armazena o valor da maior distância.

void direcaoMenorCaminho()
{
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

// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda",
// "Frente", "Tras").
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno
// para uma movimentação futura.
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja
// enviado pelo usuário.
//
//      Complete a função com a chamada das funções já criadas
// int dirige(int *v, int maxv)
// {
// 	int maxVetor = maxv;
// 	int *vetorMov = v;
// 	int posAtualVetor = 0;
// 	int dirigindo = 1;
// 	while (dirigindo)
// 	{
// 		int medida = /// .. Chame a função de de leitura da medida para a "Direita"
// 			medida = converteSensor(medida, 0, 830);
// 		posAtualVetor = // Chame a função para armazenar a medida no vetor
// 						///////////////////////////////////////////////////////////////////////////
// 			// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
// 			// ................
// 			///////////////////////////////////////////////////////////////////////////
// 			dirigindo = leComando();
// 	}
// 	return posAtualVetor;
// }

// // O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// // do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado
// // na maior distância a cada movimento
// void percorre(int *v, int tamPercorrido)
// {
// 	int *vetorMov = v;
// 	int maiorDir = 0;

// 	for (int i = 0; i < tamPercorrido; i += 4)
// 	{
// 		char *direcao = direcaoMenorCaminho(&(vetorMov[i]), &maiorDir);
// 		printf("Movimentando para %s distancia = %i\n", direcao, maiorDir);
// 	}
// }

// int main(int argc, char **argv)
// {
// 	int maxVetor = 100;
// 	int vetorMov[maxVetor * 4];
// 	int posAtualVet = 0;

// 	posAtualVet = dirige(vetorMov, maxVetor);
// 	percorre(vetorMov, posAtualVet);

// 	return 0;
// }

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

	int ponteiroVetor;
	int tamanhoVetor;
	int posicao;
	int medida;

	// std::cout << "Indique o ponteiro do vetor:";
	// std::cin >> ponteiroVetor;
	std::cout << "Indique o tamanho do vetor:";
	std::cin >> tamanhoVetor;
	std::cout << "Indique a posição a ser inserido o valor:";
	std::cin >> posicao;
	std::cout << "Indique a medida a ser inserida no vetor:";
	std::cin >> medida;
	armazenaVetor(tamanhoVetor, posicao, medida);

	leComando();

	return 0;
}