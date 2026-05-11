#include <stdio.h>

int main(void) {
    int fila[5];
    int tamanho = 0; // Padronizado para 'tamanho'

    // INSERÇÃO (Enqueue)
    // Boa prática: Verificar se há espaço antes de inserir
    if (tamanho < 5) {
        fila[tamanho] = 10;
        tamanho++;
    }
    if (tamanho < 5) {
        fila[tamanho] = 20;
        tamanho++;
    }
    if (tamanho < 5) {
        fila[tamanho] = 30;
        tamanho++;
    }

    // IMPRESSÃO (Estado Inicial)
    printf("Fila antes da remocao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", fila[i]); // Adicionado espaço para não colar os números
    }
    printf("\n");

    // REMOÇÃO (Dequeue)
    // Salva o primeiro elemento para processamento
    int removido = fila[0];
    printf("Removido do inicio: %d\n", removido);

    // O Gargalo O(n): Deslocamento (Shift) para a esquerda
    for (int i = 0; i < tamanho - 1; i++) {
        // O elemento atual recebe o valor do seu vizinho da direita
        fila[i] = fila[i + 1];
    }
    tamanho--; // Reduzimos o tamanho lógico da fila

    // IMPRESSÃO (Estado Final)
    printf("Fila apos a remocao: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", fila[i]); // Agora sim imprimimos os valores restantes
    }
    printf("\n");

    return 0; // Sucesso
}
