#include <iostream>
using namespace std;

const int MAX = 5;

class Pila {
private:
    int datos[MAX];
    int top;

public:
    Pila() {
        top = -1;
    }

    bool estaVacia() {
        return top == -1;
    } bool estaLlena() {
        return top == MAX - 1;
    }

    void push(int valor) {
        if (estaLlena()) {
            cout << "Error: la pila esta llena." << endl;
            return;
        }

        top++;
        datos[top] = valor;

        cout << "Se agrego: " << valor << endl;
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: la pila esta vacia." << endl;
            return -1;
        }

        int valor = datos[top];
        top--;

        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return-1;
        }

        return datos[top];
    }
};

int main() {
    Pila pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    cout << "Elemento superior: " << pila.peek() << endl;

    cout << "Elemento eliminado: " << pila.pop() << endl;

    cout << "Nuevo elemento superior: " << pila.peek() << endl;

    return 0;
}