//
// Created by tomas on 2/4/2025.
//
#include "saqueador.hpp"
#include <iostream>
#include <random>

   Saqueador :: Saqueador (const std::string& nombre, Estilo estilo) : EntidadGenerica(nombre) , m_estilo(estilo), m_numMiembros(randomGroupSize())
            {
            }

/**
 * @brief Muestra la información del grupo de saqueadores
 */
void  Saqueador :: showInfo() const override
{
    std::cout << "💀 Saqueadores: " << m_name << "\n"
              << " - Estilo: " << estiloToString(m_estilo) << "\n"
              << " - Miembros: " << m_numMiembros << "\n";

}

/**
 * @brief Simula una amenaza del grupo
 */
void  Saqueador :: amenazar() const
{
    switch (m_estilo)
    {
        case Estilo::AGRESIVO:
            std::cout << "💬" << m_name << " >>> ¡Entréganos tus recursos o lo pagarán caro!" << std::endl;
        break;
        case Estilo::SIGILOSO:
            std::cout << "💬" << m_name << " >>> Nadie nos vio entrar, nadie los verá salir..." << std::endl;
        break;
        case Estilo::OPORTUNISTA:
            std::cout << "💬" << m_name << " >>> Solo estamos aquí por lo que sobra... si queda algo." << std::endl;
        break;
    }
}
