#ifndef DICT_H
#define DICT_H

#include <string>

template <typename V>
class Dict {
public:
    // Destructor virtual obligatorio en clases base
    virtual ~Dict() {}

    // Inserta key → value
    // Lanza std::runtime_error si key ya existe
    virtual void insert(std::string key, V value) = 0;

    // Busca el valor asociado a key
    // Lanza std::runtime_error si key no existe
    virtual V search(std::string key) = 0;

    // Elimina key → value y devuelve el valor eliminado
    // Lanza std::runtime_error si key no existe
    virtual V remove(std::string key) = 0;

    // Devuelve el número de elementos del diccionario
    virtual int entries() = 0;
};

#endif

