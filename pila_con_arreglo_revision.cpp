#include <iostream>
using namespace std;

// Define la capacidad máxima del arreglo que almacenará la pila.
const int MAX = 5;

class Pila {
private:
    int datos[MAX]; // Arreglo donde se guardan los elementos.
    int top;        // Índice del elemento que está en la cima de la pila.

public:
    // Constructor: inicializa top en -1 para indicar que la pila está vacía.
    Pila() {
        top = -1;
    }

    // Comprueba si la pila está vacía. Devuelve true si top es -1.
    bool estaVacia() {
        return top == -1;
    } 
    // Comprueba si la pila está llena: el último índice válido es MAX - 1.
    bool estaLlena() {
        return top == MAX - 1;
    }

    // PUSH: agrega un valor en la cima si todavía hay espacio.
    void push(int valor) {
        if (estaLlena()) { // Evita insertar elementos cuando se alcanzó la capacidad.
            cout << "Error: la pila esta llena." << endl;
            return; // Termina la función sin modificar la pila.
        }

        top++;              // Avanza al índice que ocupará el nuevo elemento.
        datos[top] = valor; // Guarda el valor en esa posición del arreglo.

        cout << "Se agrego: " << valor << endl; // Informa qué elemento se agregó.
    }

    // POP: retira y devuelve el elemento que está en la cima.
    int pop() {
        if (estaVacia()) { // Comprueba que exista un elemento para retirar.
            cout << "Error: la pila esta vacia." << endl;
            return -1; // Devuelve -1 como aviso de que no se pudo eliminar.
        }

        int valor = datos[top]; // Guarda el valor superior antes de retirarlo.
        top--;                  // Baja la cima una posición; el elemento queda fuera de la pila.

        return valor; // Devuelve el valor que se eliminó.
    }

    // PEEK: consulta el elemento superior sin eliminarlo.
    int peek() {
        if (estaVacia()) { // Evita consultar la cima cuando no hay elementos.
            cout << "La pila esta vacia." << endl;
            return-1; // Devuelve -1 para indicar que la pila está vacía.
        }

        return datos[top]; // Devuelve el dato que ocupa la cima.
    }
};

int main() {
    Pila pila; // Crea una pila vacía.

    // Inserta tres valores; el último insertado queda en la cima.
    pila.push(10);
    pila.push(20);
    pila.push(30);

    // Muestra el elemento de la cima sin retirarlo.
    cout << "Elemento superior: " << pila.peek() << endl;

    // Retira el elemento superior y muestra el valor devuelto por pop().
    cout << "Elemento eliminado: " << pila.pop() << endl;

    // Consulta la cima actual después de la eliminación.
    cout << "Nuevo elemento superior: " << pila.peek() << endl;

    return 0; // Indica que el programa terminó correctamente.
}
