#include <stdio.h>

struct Pessoa {
    char nome[50];
    char sexo;
    char cpf[13];
    float peso, altura;
    int dia, mes, ano;
};

// função para cadastrar pessoa
void cadasrtarPessoa(struct Pessoa *p) {
    printf("Digite seu primeiro nome: ");
    scanf("%s", p->nome);

    printf("Digite seu cpf: ");
    scanf("%s", p->cpf);

    printf("Sexo (m/f): ");
    scanf(" %c", &p->sexo); 

    printf("Data de nascimento\n");
    printf("Dia: ");
    scanf("%d", &p->dia);

    printf("Mes: ");
    scanf("%d", &p->mes);

    printf("Ano: ");
    scanf("%d", &p->ano);

    printf("Peso: ");
    scanf("%f", &p->peso); 

    printf("Altura: ");
    scanf("%f", &p->altura); 
}

void mostrarPessoa(struct Pessoa *p) {
    printf("\n--SEUS DADOS--\n"); 
    printf("CPF: %s\n", p->cpf);
    printf("Sexo: %c\n", p->sexo);
    printf("Nascimento: %02d/%02d/%d\n", p->dia, p->mes, p->ano); 
    printf("Peso: %.2f\n", p->peso);
    printf("Altura: %.2f\n", p->altura);
}

int main() {
    struct Pessoa pessoa;

    cadasrtarPessoa(&pessoa);
    mostrarPessoa(&pessoa);
    
    return 0;

}