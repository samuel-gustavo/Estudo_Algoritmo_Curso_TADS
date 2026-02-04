#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct No {
    int conteudo;
    struct No* proximo;
} No;

void imprimir_lista(No* head);
void inserir_no_inicio(No** head, int valor);
void pausar();

int main() {
    No* head = nullptr;
    int escolha, valor;

    do {
        system("clear");
        printf("\n  ------------- MANIPULANDO LISTA -------------\n");
        printf("  | [1] Adicionando valor no inicio           |\n");
        printf("  | [2] Imprimir valores                      |\n");

        printf("\n\nEscohla a opção: ");
        cin >> escolha;

        switch (escolha) {
            case 1:
                printf("\nValor: ");
                cin >> valor;
                inserir_no_inicio(&head, valor);
                break;
            
            case 2:
                imprimir_lista(head);
                pausar();
                break;

            default:
                printf("\nOpção inválida!!!");
                break;
        }
    } while(escolha != 0);

    return 0;
}

void imprimir_lista(No* head) {
    No* atual = head;
    while(atual != nullptr) {
        cout << atual->conteudo << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL\n";
}

void inserir_no_inicio(No** head, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->conteudo = valor;
    novo->proximo = *head;
    *head = novo;
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();   // limpa o buffer
    cin.get();      // espera ENTER
}