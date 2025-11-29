#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5 

// Struct 
struct Peca {
    char nome; // 'I', 'O', 'T', 'L'
    int id;
};

// Função para gerar peça aleatória
struct Peca gerarPeca(int id) {
    struct Peca p;
    char tipos[4] = {'I', 'O', 'T', 'L'};
    p.nome = tipos[rand() % 4];
    p.id = id;         
    return p;
}

// Função para mostrar a fila
void mostrarFila(struct Peca fila[], int frente, int tras) {
    printf("Fila atual:\n");
    int i = frente;
    while (i != tras) {
        printf("[%c | %d] ", fila[i].nome, fila[i].id);
        i = (i + 1) % TAM; 
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); 

    struct Peca fila[TAM];
    int frente = 0, tras = 0;
    int idAtual = 1;

    for (int i = 0; i < TAM; i++) {
        fila[i] = gerarPeca(idAtual++);
        tras = (tras + 1) % TAM;
    }

    int opcao;
    do {
        printf("\nMenu:\n1 - Jogar peça\n2 - Inserir peça\n3 - Mostrar fila\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                printf("Peça jogada: [%c | %d]\n", fila[frente].nome, fila[frente].id);
                frente = (frente + 1) % TAM;
                break;
            case 2: 
                fila[tras] = gerarPeca(idAtual++);
                tras = (tras + 1) % TAM;
                printf("Nova peça inserida.\n");
                break;
            case 3: 
                mostrarFila(fila, frente, tras);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(opcao != 0);

    return 0;
}