#include <stdio.h>
#define MAX 60


typedef struct {
    int chave;
} Elemento;


void subir(Elemento T[], int i) {
    int j = i / 2;
    if (j >= 1) { 
        if (T[i].chave > T[j].chave) { 
            Elemento temp = T[i];
            T[i] = T[j];
            T[j] = temp;
            subir(T, j);
        }
    }
}


void descer(Elemento T[], int i, int n) {
    int j = 2 * i; 
    while (j <= n) {
        if (j < n && T[j + 1].chave > T[j].chave) {
            j = j + 1; 
        }
        if (T[i].chave < T[j].chave) {
            Elemento temp = T[i];
            T[i] = T[j];
            T[j] = temp;
            i = j; 
            j = 2 * i; 
        } else {
            break; 
        }
    }
}

void heapify(Elemento T[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        descer(T, i, n);
    }
}

void inserir(Elemento T[], int *n, Elemento e) {
    (*n)++;
    T[*n] = e;
    subir(T, *n);
}

Elemento remover(Elemento T[], int *n) {
    Elemento raiz = T[1];
    T[1] = T[*n];
    (*n)--;
    descer(T, 1, *n); 
    return raiz;
}


void exibirHeap(Elemento T[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", T[i].chave);
    }
    printf("\n");
}

int main() {
    Elemento heap[MAX + 1]; 
    int n = 0; 

    inserir(heap, &n, (Elemento){90});
    inserir(heap, &n, (Elemento){32});
    inserir(heap, &n, (Elemento){5});
    inserir(heap, &n, (Elemento){30});
    inserir(heap, &n, (Elemento){15});
    inserir(heap, &n, (Elemento){100});
    inserir(heap, &n, (Elemento){45});
    inserir(heap, &n, (Elemento){22});
    inserir(heap, &n, (Elemento){30});
    inserir(heap, &n, (Elemento){150});

    printf("Heap após inserções: ");
    exibirHeap(heap, n);

    Elemento removed = remover(heap, &n);
    printf("Elemento removido: %d\n", removed.chave);

    printf("Heap após remoção: ");
    exibirHeap(heap, n);

    return 0;
}
