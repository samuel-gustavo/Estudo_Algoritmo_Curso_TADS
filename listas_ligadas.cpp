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
void inserir_no_fim(No** head, int valor);
void remover_por_valor(No** head, int valor_procurado);
void limpar_lista(No** head);
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
        printf("  | [4] Adicionar conteúdo no fim             |\n");
        printf("  | [5] Remover por valor                     |\n");
        printf("  | [6] Apagar toda a lista                   |\n");
        printf("  | [0] Sair do Sistema                       |\n");

        printf("\n\nEscolha a opção: ");
        cin >> escolha;

        switch (escolha) {
            case 0:
                printf("\nSaindo do Sistema...");
                break;
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
            case 4:
                printf("\nValor: ");
                cin >> valor;
                inserir_no_fim(&head, valor);
                break;
            case 5:
                printf("\nValor procurado: ");
                cin >> valor_procurado;
                remover_por_valor(&head, valor_procurado);
                break;
            case 6:
                limpar_lista(&head);
                printf("\nMemória Liberada...");
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

void inserir_no_fim(No** head, int valor) {
    if(*head == nullptr) {
        return;
    }

    No* novo = (No*) malloc(sizeof(int));
    novo->conteudo = valor;
    novo->proximo = nullptr;

    No* atual = *head;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    
    atual->proximo = novo;
}

void remover_por_valor(No** head, int valor_procurado) {
    if(*head == nullptr) {
        cout << "\nLista vazia!";
        return;
    }

    // Conteúdo no Inicio
    if((*head)->conteudo == valor_procurado) {
        No* temp = *head;
        *head = (*head)->proximo;
        free(temp);
        return;
    }

    // Conteúdo no meio
    No* atual = *head;
    while(atual->proximo != nullptr && atual->proximo->conteudo != valor_procurado) {
        atual = atual->proximo;
    }

    if(atual->proximo == nullptr) {
        cout << "Valor não Encontrado!";
        return;
    }

    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
}

void limpar_lista(No** head) {
    No* atual;

    while(*head != nullptr) {
        atual = *head;
        *head = (*head)->proximo;
        free(atual);
    }
};

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore();   // limpa o buffer
    cin.get();      // espera ENTER
}