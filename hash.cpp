#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
 * @class MyHashSet
 * @brief Implementación de un conjunto (HashSet) utilizando una lista enlazada.
 */
class MyHashSet
{
    list<int> miLista; ///< Lista enlazada para almacenar los elementos del conjunto.

public:
    /**
     * @brief Constructor de la clase MyHashSet.
     *
     * Inicializa la lista enlazada vacía.
     */
    MyHashSet() : miLista()
    {
        // La lista se inicializa vacía automáticamente.
    }

    /**
     * @brief Añade un valor al conjunto.
     *
     * Si el valor ya existe, no se agrega.
     *
     * @param key Valor a agregar al conjunto.
     */
    void add(int key)
    {
        for (auto it = miLista.begin(); it != miLista.end(); ++it)
        {
            if (*it == key)
            {
                return; // El elemento ya existe, no se agrega.
            }
        }
        miLista.push_back(key); // Agrega la clave al final de la lista.
    }

    /**
     * @brief Elimina un valor del conjunto.
     *
     * Si el valor no existe, no realiza ninguna acción.
     *
     * @param key Valor a eliminar del conjunto.
     */
    void remove(int key)
    {
        for (auto it = miLista.begin(); it != miLista.end(); ++it)
        {
            if (*it == key)
            {
                miLista.erase(it); // Elimina el elemento de la lista.
                return;            // Salimos del bucle una vez que se elimina el elemento.
            }
        }
    }

    /**
     * @brief Verifica si un valor existe en el conjunto.
     *
     * @param key Valor a verificar.
     * @return true Si el valor existe en el conjunto.
     * @return false Si el valor no existe en el conjunto.
     */
    bool contains(int key)
    {
        for (auto it = miLista.begin(); it != miLista.end(); ++it)
        {
            if (*it == key)
            {
                return true; // El elemento existe en la lista.
            }
        }
        return false; // El elemento no existe en la lista.
    }
};

/**
 * @brief Función principal del programa.
 *
 * Permite al usuario interactuar con un conjunto (HashSet) mediante un menú.
 *
 * @return int Código de salida del programa.
 */
int main()
{
    MyHashSet mySet;
    int opcion;
    int valor;

    do
    {
        cout << "\n===== Menu HashSet =====\n";
        cout << "1. Agregar valor\n";
        cout << "2. Eliminar valor\n";
        cout << "3. Verificar si existe valor\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el valor a agregar: ";
            cin >> valor;
            mySet.add(valor);
            cout << "Valor agregado!\n";
            break;
        case 2:
            cout << "Ingrese el valor a eliminar: ";
            cin >> valor;
            mySet.remove(valor);
            cout << "Valor eliminado (si existia).\n";
            break;
        case 3:
            cout << "Ingrese el valor a verificar: ";
            cin >> valor;
            if (mySet.contains(valor))
            {
                cout << "El valor SÍ existe en el conjunto.\n";
            }
            else
            {
                cout << "El valor NO existe en el conjunto.\n";
            }
            break;
        case 4:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 4);

    return 0;
}