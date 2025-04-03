//
// Created by tomas on 2/4/2025.
//
#include "refugiado.hpp"
#include <iostream>
// Implementación del constructor
Refugiado::Refugiado(const std::string& name, bool isFromVault)
    : EntidadGenerica(name), m_maxHealth(isFromVault ? 80 : 100), m_health(m_maxHealth),
      m_supplies(0), m_isFromVault(isFromVault)
{
}

//  showInfo()
void Refugiado::showInfo() const
{
    std::cout << "👤 Refugiado: " << m_name << "\n"
              << " - Salud: " << m_health <<"/" << m_maxHealth << "\n"
              << " - Suministros: " << m_supplies << "\n"
              << " - Origen: " << (m_isFromVault ? "VAULT" : "Superficie") << "\n";
}

// consumeSupplies()
void Refugiado::consumeSupplies(int cantidad)
{
    if (m_supplies >= cantidad)
    {
        m_supplies -= cantidad;
        std::cout << "💬" << m_name << " >>> Gracias por mantenerme alimentado." << std::endl;
    }
    else
    {
        m_supplies = 0;
        std::cout << "💬" << m_name << " >>> No puedo quedarme sin recursos... buscaré otro lugar." << std::endl;
    }
}

// requestShelter()
void Refugiado::requestShelter(bool espacioDisponible)
{
    if (espacioDisponible)
    {
        std::cout << "💬" << m_name << " >>> Gracias por recibirme en su refugio." << std::endl;
    }
    else
    {
        std::cout << "💬" << m_name << " >>> Entiendo, seguiré buscando un lugar donde quedarme..." << std::endl;
    }
}

// isFromVault()
bool Refugiado::isFromVault() const
{
    return m_isFromVault;
}