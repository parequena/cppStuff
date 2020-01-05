/*
1. Operaciones con bits. Dado un entero de 32 bits que contiene la siguiente información sobre un personaje:
    - Los 8 bits de mayor peso, contienen la vida del personaje.
    - Los siguientes 8 bits, el número de balas.
    - Los siguientes 4 bits, el número de compañeros.
    - El bit 0, el indicador del modo invulnerable.
    - El bit 1, el indicador de balas infinitas.
    - El bit 2, el indicador de escudo presente.
    - El bit 3, el indicador de modo "Berserker".

Realizar las siguientes funciones:
    a. Función que dado el entero anterior, retorne el número de balas.
    b. Función que dado el entero anterior, añada un número de balas a las existentes.
    c. Función que dado el entero anterior, retorne si está activado el modo de balas infinitas.
    d. Función que dado el entero anterior, active el modo de balas infinitas.
*/

#include <iostream>
#include <cstdint>

int main()
{
    //                                          FISB
    //              | HP   ||  BU  || C|        ||||
    uint32_t n  = 0b00000001000000000000000000000000;
    uint32_t HP = 0b11111111000000000000000000000000;
    uint32_t BU = 0b00000000111111110000000000000000;
    uint32_t CO = 0b00000000000000001111000000000000;
    uint32_t F_ = 0b00000000000000000000000000001000;
    uint32_t I_ = 0b00000000000000000000000000000100;
    uint32_t S_ = 0b00000000000000000000000000000010;
    uint32_t B_ = 0b00000000000000000000000000000001;

    std::cout << " n: " << n  << '\n';
    std::cout << "HP: " << HP << '\n';
    std::cout << "--: " << static_cast<int>(n&HP) << '\n';

    return 0;
}