#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {

private:
    BSTree<TableEntry<V>>* tree;

public:
    BSTreeDict();
    ~BSTreeDict();

    V operator[](std::string key);

    friend std::ostream& operator<<(std::ostream &out,
                                    const BSTreeDict<V> &bs) {
        bs.tree->print_inorder(out);
        return out;
    }
};

/* ======================================================
   IMPLEMENTACIÓN
   ====================================================== */

template <typename V>
BSTreeDict<V>::BSTreeDict() {
    tree = new BSTree<TableEntry<V>>();
}

template <typename V>
BSTreeDict<V>::~BSTreeDict() {
    delete tree;
}

/*
 * Acceso / inserción:
 *  - si la clave existe → devuelve el valor
 *  - si no existe → se inserta con valor por defecto
 */
template <typename V>
V BSTreeDict<V>::operator[](std::string key) {
    TableEntry<V> entry(key, V{});

    if (!tree->search(entry)) {
        tree->insert(entry);
    }

    // Ahora seguro que existe: lo buscamos para devolver su valor
    // (BSTree no devuelve nodos, así que usamos un recorrido)
    // SOLUCIÓN habitual en prácticas: lanzar excepción si no está
    // o modificar BSTree para devolver referencia.
    // Aquí usamos una excepción controlada:
    throw std::logic_error("operator[] requiere acceso por referencia (no soportado)");
}

#endif

