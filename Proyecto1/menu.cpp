
#include <iostream>

using namespace std;

int Menu() {
    int opcion, subopcion1;

    do {
        // Mostrar el menú principal
        cout << "Menu:" << endl;
        cout << "1. Pasillo" << endl;
        cout << "2. Producto" << endl;
        cout << "3. Marca" << endl;
        cout << "4. Inventario" << endl;
        cout << "5. Clientes" << endl;
        cout << "6. Administrador" << endl;
        cout << "7. Ciudad" << endl;
        cout << "8. Salir" << endl;
        // Solicitar al usuario que ingrese una opción
        cout << "Ingrese el numero de opcion: ";
        cin >> opcion;

        // Realizar acciones según la opción seleccionada
        switch (opcion) {
            case 1:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Pasillo:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;

                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                    switch (subopcion1) {
                        case 1:
                            cout << "Insertando en la Opción 1." << endl;
                            // Código correspondiente a insertar en la opción 1
                            break;
                        case 2:
                            cout << "Eliminando en la Opción 1." << endl;
                            // Código correspondiente a eliminar en la opción 1
                            break;
                        case 0:
                            cout << "Volviendo al menu principal..." << endl;
                            break;
                        default:
                            cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                            break;
                    }
                } while (subopcion1 != 0);
                break;
            case 2:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Producto:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 3:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Marca:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 4:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Inventario:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 5:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Cliente:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 6:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Administrador:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
            case 7:
                do {
                    // Mostrar submenú para la opción 1
                    cout << "Ciudad:" << endl;
                    cout << "1. Insertar" << endl;
                    cout << "2. Eliminar" << endl;
                    cout << "0. Atras" << endl;
    
                    cout << "Ingrese el numero de subopcion: ";
                    cin >> subopcion1;
                    
                switch (subopcion1) {
                    case 1:
                        cout << "Insertando en la Opción 1." << endl;
                        // Código correspondiente a insertar en la opción 1
                        break;
                    case 2:
                        cout << "Eliminando en la Opción 1." << endl;
                        // Código correspondiente a eliminar en la opción 1
                        break;
                    case 0:
                        cout << "Volviendo al menu principal..." << endl;
                        break;
                    default:
                        cout << "Subopcion no válida. Por favor ingresa un número del 1 al 3." << endl;
                        break;
                }
            } while (subopcion1 != 0);
            break;
             case 8:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor ingresa un número del 1 al 7." << endl;
                break;
        }
    } while (opcion != 8);

    return 0;
}
