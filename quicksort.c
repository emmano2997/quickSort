#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particiona(int *v, int inicio, int fim) {
		int meio = (v[inicio] + v[fim]) / 2;  // Meio do intervalo
		int pivo = (v[inicio] + v[fim] + meio) / 3;  // Escolher o pivô

		while (inicio < fim) {
				// Percorrer o vetor da esquerda para direita procurando elemento maior que o pivô
				while (inicio < fim && v[inicio] <= pivo) {
						inicio++;
				}
				// Percorrer o vetor da direita para esquerda procurando elemento menor que o pivô
				while (inicio < fim && v[fim] > pivo) {
						fim--;
				}
				// Faz uma troca no vetor com o auxiliar
				if (inicio < fim) {
						int aux = v[inicio];
						v[inicio] = v[fim];
						v[fim] = aux;
				}
		}
		return inicio;
}

void quickSort(int *v, int inicio, int fim) {
		if (inicio < fim) {  // Chamadas recursivas
				int q = particiona(v, inicio, fim);
				quickSort(v, inicio, q - 1);
				quickSort(v, q, fim);
		}
}

void imprimir(int *v, int tam) {
		for (int i = 0; i < tam; i++) {
				printf("%d ", v[i]);
		}
		printf("\n");
}

int main() {
		FILE *arquivo;
		int *vet;
		int tam = 0;

		arquivo = fopen("./num.1000.1.in", "r");
        
		if (arquivo == NULL) {
				printf("ERRO ao abrir o arquivo\n");
				return 1;
		}

		fscanf(arquivo, "%d", &tam);

		// Alocando memória para o vetor
		vet = (int *)malloc(tam * sizeof(int));
		if (vet == NULL) {
				printf("Erro ao alocar memória\n");
				fclose(arquivo);
				return 1;
		}

		// Lendo os elementos do arquivo
		for (int i = 0; i < tam; i++) {
				fscanf(arquivo, "%d", &vet[i]);
		}

		fclose(arquivo);

		clock_t inicio = clock();

		quickSort(vet, 0, tam - 1);

		clock_t fim = clock();
		double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;

		imprimir(vet, tam);

		//  tempo gasto
		printf("Tempo gasto na ordenação: %f segundos\n", tempo_gasto);

		free(vet);

		return 0;
}
