#include <iostream>

class Pilha {
private:
    int* elementos;
    int topo;
    int tamanho;


public:
    Pilha(int tam) : tamanho(tam), topo(-1) {
        elementos = new int[tamanho];
    }

    ~Pilha(){
        delete[] elementos;
    }

    bool cheia(){
        return topo == tamanho -1;

    }

    bool vazia() {
        return topo == -1;
    }

    void empilhar(int valor) {
        if (cheia()) {
            std::cout << "Pilha ficou cheia" << valor << ".\n";

        }else{
            elementos[++topo] = valor;
        }
    }

    void remover() {
        if (vazia()){
            std::cout << "pilha vazia. \n";
        }else{
            --topo;
        }
    }

    void exibir(){
        if (vazia()){
            std::cout << "A pilha está vazia. \n";
        }else{
            std::cout << "Elementos da pilha: \n";
            for (int i = 0; i <= topo; ++i) {
                std::cout << elementos[i] << " ";
            }
            std::cout <<"\n"
        }
    }
}

int main() {
    int tamanho;
    std::cout << "Digite o tamanho da pilha: ";
    std::cin >> tamanho;

    Pilha Pilha(tamanho);

    for (int i = 0; i < tamanho - 1; ++i){
        pilha.empilhar(i);
    }

    pilha.exibir();

    std::cout << "A pilha está " << (pilha.vazia() ? "vazia" : "não vazia") << ".\n";
    std::cout << "A pilha está " << (pilha.cheia() ? "cheia" : "não cheia") << ".\n";

    int novoValor;
    std::cout << "Digite um novo valor para empilhar: ";
    std::cin >> novoValor;
    pilha.empilhar(novoValor);
    pilha.exibir();

    pilha.remover();
    pilha.exibir();

    return 0;
}
