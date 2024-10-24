#include <iostream>
#define Max_size 10
using namespace std;

class Fila {
private:
    int f, r;
    int queue[Max_size];

public:
    Fila() {
        f = -1;
        r = -1;
    }

    bool Cheio() {
        return (r == Max_size - 1);
    }

    bool Vazio() {
        return (f == -1 && r == -1);
    }

    void enfileirar(int data) {
        if (Cheio()) {
            cout << "A fila está cheia." << endl;
            return;
        } 
        else if (Vazio()) {
            f = r = 0;
        } 
        else {
            r++;
        }
        queue[r] = data;
        cout << "Cliente com o número " << data << " entrou na fila." << endl;
    }

    void desenfileirar() {
        if (Vazio()) {
            cout << "A fila está vazia." << endl;
        } 
        else if (f == r) {
            cout << "Cliente com o número " << queue[f] << " saiu da fila." << endl;
            f = r = -1;
        } 
        else {
            cout << "Cliente com o número " << queue[f] << " saiu da fila." << endl;
            f++;
        }
    }

    void display() {
        if (Vazio()) {
            cout << "A fila está vazia." << endl;
            return;
        }
        cout << "Fila de clientes: ";
        for (int i = f; i <= r; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Fila fila;
    int choice, data;

    do {
        cout << "Escolha uma opção:" << endl;
        cout << "1. Entrar na fila" << endl;
        cout << "2. Sair da fila" << endl;
        cout << "3. Mostrar a fila" << endl;
        cout << "0. Sair do programa" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Digite o número do cliente: ";
                cin >> data;
                fila.enfileirar(data);
                break;
            case 2:
                fila.desenfileirar();
                break;
            case 3:
                fila.display();
                break;
            case 0:
                cout << "Encerrando o programa." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}
