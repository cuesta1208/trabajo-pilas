#include <iostream>
using namespace std;

// Define la estructura de cada nodo de la pila.
// Cada nodo guarda un dato entero y un puntero al siguiente nodo.
struct Nodo {
    int dato;             // Valor que almacena este nodo.
    Nodo* siguiente;      // Dirección del nodo que está debajo en la pila.
};

class Pila {
private:
    Nodo* top;            // Apunta al nodo que está en la cima de la pila.

public:
    // Constructor: se ejecuta al crear una pila.
    // NULL indica que inicialmente no hay ningún nodo.
    Pila() {
        top = NULL;
    }

    // Devuelve true si la pila está vacía; de lo contrario, devuelve false.
    bool estaVacia() {
        return top == NULL;
    }

    // PUSH: agrega un nuevo elemento en la cima de la pila.
    void push (int valor) {
        Nodo* nuevo = new Nodo(); // Reserva memoria para crear un nodo.

        nuevo->dato = valor;       // Guarda el valor recibido en el nodo.
        nuevo->siguiente = top;    // Conecta el nuevo nodo con la cima anterior.

        top = nuevo;               // El nuevo nodo pasa a ser la cima.

        cout << "Se agrego: "<< valor << endl; // Muestra el elemento agregado.
    }

    // POP: elimina y devuelve el elemento que está en la cima.
    int pop() {
        if (estaVacia()) { // Comprueba que exista un elemento para eliminar.
            cout << "Error: la piola esta vacia." << endl;
            return -1;     // Valor de aviso cuando no se puede eliminar.
        }

        Nodo* auxiliar = top;       // Guarda temporalmente el nodo de la cima.
        int valor = auxiliar->dato; // Conserva el dato antes de borrar el nodo.

        top = top->siguiente;        // La cima pasa a ser el nodo siguiente.

        delete auxiliar;             // Libera la memoria del nodo eliminado.

        return valor;                // Devuelve el dato que se quitó.
    }

    // PEEK: consulta el elemento de la cima sin eliminarlo.
    int peek() {
        if (estaVacia()) { // Evita consultar una pila sin elementos.
            cout << "La pila esta vacia." << endl;
            return -1;     // Indica que no hay un elemento que devolver.
        }

        return top->dato;  // Devuelve el dato de la cima.
    }

    // Destructor: se ejecuta al destruir el objeto Pila.
    // Elimina todos los nodos para liberar la memoria reservada dinámicamente.
    ~Pila() {
        while (!estaVacia()) { // Mientras queden nodos en la pila...
            pop();             // ...elimina el nodo superior.
        }
    }
};

int main() {
    Pila pila; // Crea una pila vacía.

    // Agrega tres elementos. El último agregado queda en la cima.
    pila.push(100);
    pila.push(200);
    pila.push(300);

    // Consulta y muestra la cima sin eliminarla.
    cout << "Elemento superior: " << pila.peek() << endl;

    // Elimina la cima y muestra el valor que se eliminó.
    cout << "Elemento eliminado: " << pila.pop() << endl;

    // Muestra la nueva cima después de la eliminación.
    cout << "Elemento superior: " << pila.peek() << endl;

    return 0; // Finaliza el programa indicando que terminó correctamente.
}
