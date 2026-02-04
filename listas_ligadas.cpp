#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct No {
    int conteudo;
    struct No* proximo;
} No;

void imprimir_lista(No* head);
void inserir_no_inicio(No** head, int valor);
void inserir_depois(No* head, int valor, int valor_procurado);
void pausar();

int main() {
    No* head = nullptr;
    int escolha, valor, valor_procurado;

    do {
        system("clear");
        printf("\n  ------------- MANIPULANDO LISTA -------------\n");
        printf("  | [1] Imprimir valores                      |\n");
        printf("  | [2] Adicionando valor no inicio           |\n");
        printf("  | [3] Adicionar conteúdo após um valor      |\n");

        printf("\n\nEscohla a opção: ");
        cin >> escolha;

        switch (escolha) {
            case 1:
                printf("\n");
                imprimir_lista(head);
                pausar();
                break;
            
            case 2:
                printf("\nValor: ");
                cin >> valor;
                inserir_no_inicio(&head, valor);
                break;
            
            case 3:
                printf("\nValor procurado: ");
                cin >> valor_procurado;
                printf("\nValor Novo: ");
                cin >> valor;
                inserir_depois(head, valor_procurado, valor);
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

void inserir_depois(No* head, int valor_procurado, int valor_novo) {
    No* atual = head;

    while(atual != nullptr && atual->conteudo != valor_procurado) {
        atual = atual->proximo;
    }

    if(atual == nullptr) {
        printf("\nValor não encontrado!!!");
        return;
    }

    No* novo = (No*) malloc(sizeof(int));
    novo->conteudo = valor_novo;
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();   // limpa o buffer
    cin.get();      // espera ENTER
}