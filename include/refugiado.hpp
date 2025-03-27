//
// Created by benja on 26/03/25.
//

#ifndef REFUGIADO_HPP
#define REFUGIADO_HPP

#include "entidadGenerica.hpp"
#include <string>

class Refugiado : public EntidadGenerica
{
private:
    int m_health; // Salud del refugiado
    int m_supplies; // Suministros que posee
    bool m_isInShelter; // Estado de si esta en el refugio

public:
    /**
     * @brief Constructor de Refugiado
     * @param name Nombre del refugiado
     * @param initialHealth Salud inicial del refugiado
     * @param initialSupplies Suministros iniciales
     */
    Refugiado(const std::string& name, int initialHealth = 100, int initialSupplies = 50);

    /**
    * @brief Muestra la información detallada del refugiado
    * Implementación del método virtual puro de EntidadGenerica
    */
    void showInfo() const override;

     /**
     * @brief Acción principal del refugiado
     * Implementación del método virtual puro de EntidadGenerica
     */
    void doAction() const override;

    /**
     * @brief Método para consumir suministros
     * @param amount Cantidad de suministros a consumir
     */
    void consumeSupplies(int amount);

    /**
     * @brief Método para recuperar salud
     * @param amount Cantidad de salud a recuperar
     */
    void recoverHealth(int amount);

}

#endif //REFUGIADO_HPP
