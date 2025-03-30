//
// Created by benja on 26/03/25.
//

#ifndef SAQUEADORES_HPP
#define SAQUEADORES_HPP

#include "entidadGenerica.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <random>

class Saqueadores : public EntidadGenerica
{
private:
    int m_strength; // Nivel de fuerza del grupo
    int m_memberCount; // Numero de miembros del grupo
    double m_stolenResources; // Recursos robados
    std::vector<std::string> m_targetTypes; // Tipos de objetivos que buscan

    enum class EstrategiaSaqueo {
        AGRESIVA,
        SIGILOSA,
        OPORTUNISTA
    };

    EstrategiaSaqueo m_estrategia;

public:
    /**
     * @brief Constructor de Saqueadores
     * @param name Nombre del grupo de saqueadores
     * @param memberCount Número de miembros
     * @param initialStrength Fuerza inicial del grupo
     */
    Saqueadores(const std::string& name, int memberCount = 5, int initialStrength = 50);

    /**
     * @brief Muestra la información detallada de los saqueadores
     * Implementación del método virtual puro de EntidadGenerica
     */
    void showInfo() const override;

    /**
     * @brief Acción principal de los saqueadores
     * Implementación del método virtual puro de EntidadGenerica
     */
    void doAction() const override;

    /**
     * @brief Realiza un ataque a un objetivo
     * @param targetName Nombre del objetivo
     * @return bool Indica si el saqueo fue exitoso
     */
    bool atacar(const std::string& targetName);

    /**
     * @brief Cambia la estrategia de saqueo
     * @param nuevaEstrategia Nueva estrategia a adoptar
     */
    void cambiarEstrategia(EstrategiaSaqueo nuevaEstrategia);

    /**
     * @brief Añade un nuevo tipo de objetivo a la lista de búsqueda
     * @param tipoObjetivo Tipo de objetivo a añadir
     */
    void añadirTipoObjetivo(const std::string& tipoObjetivo);

    /**
     * @brief Obtiene los recursos robados
     * @return double Cantidad de recursos robados
     */
    double getRecursosRobados() const;

    /**
     * @brief Incrementa la fuerza del grupo de saqueadores
     * @param incremento Cantidad de incremento de fuerza
     */
    void incrementarFuerza(int incremento);
};



#endif //SAQUEADORES_HPP
