//
// Created by benja on 26/03/25.
//

#include "refugiado.hpp"

Refugiado::Refugiado(const std::string& name, int initialHealth, int initialSupplies)
    : EntidadGenerica(name)
    , m_health(initialHealth)
    , m_supplies(initialSupplies)
    , m_isInShelter(false)
{}

void Refugiado::showInfo() const
{
        std::cout << "Refugiado: " << m_name << std::endl;
        std::cout << "Salud: " << m_health << std::endl;
        std::cout << "Suministros: " << m_supplies << std::endl;
        std::cout << "Estado: " << (m_isInShelter ? "En el refugio." : "No esta en el refugio") << std::endl;
}

void Refugiado::doAction() const
{
    if (m_health <= 0) {
        std::cout << m_name << " está demasiado herido para realizar acciones." << std::endl;
        return;
    }

    if (m_isInShelter) {
        std::cout << m_name << " descansa y recupera fuerzas en el refugio." << std::endl;
    } else {
        std::cout << m_name << " busca un lugar seguro para refugiarse." << std::endl;
    }
}

void Refugiado::consumeSupplies(int amount)
{
    if (amount > m_supplies) {
        std::cout << "No hay suficientes suministros." << std::endl;
        return;
    }

    m_supplies -= amount;
    std::cout << m_name << " ha consumido " << amount << " suministros." << std::endl;
}

void Refugiado::recoverHealth(int amount)
{
    m_health = std::min(m_health + amount, 100);
    std::cout << m_name << " ha recuperado " << amount << " puntos de salud." << std::endl;
}

void Refugiado::findShelter()
{
    m_isInShelter = true;
    std::cout << m_name << " ha encontrado un refugio seguro." << std::endl;
}