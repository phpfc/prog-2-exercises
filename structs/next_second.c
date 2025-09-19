// 2) Faça uma função que receba uma hora como parâmetro 
// e retorne uma nova estrutura com a hora mais um segundo. 
// O tipo HORA foi criado a partir de uma estrutura que armazena
// os valores para a hora, minuto e segundo.

#include <stdio.h>
#include <time.h>
#include  <stdlib.h>

struct hora {
	int hora;
	int minuto;
	int segundo;
};
typedef struct hora HORA;

HORA adicionaSegundo( HORA horaAtual) {
	horaAtual.segundo++;

	if (horaAtual.segundo == 60) {
		horaAtual.segundo = 0;
		horaAtual.minuto++;
	} // Lógica de propagação
	if (horaAtual.minuto == 60) {
		horaAtual.minuto = 0;
		horaAtual.hora++;
	}
	if (horaAtual.hora == 24) {
		horaAtual.hora = 0;
	}

	return horaAtual;
}

int main() {
	srand(time(nullptr));

	HORA horaAtual = {
		.hora   = rand() % 24,
		.minuto = rand() % 60,
		.segundo= rand() % 60
	};

	printf("%02d:%02d:%02d antes da adição\n", horaAtual.hora, horaAtual.minuto, horaAtual.segundo);

	HORA novaHora = adicionaSegundo(horaAtual);

	printf("%02d:%02d:%02d depois da adição\n", novaHora.hora, novaHora.minuto, novaHora.segundo);
}
