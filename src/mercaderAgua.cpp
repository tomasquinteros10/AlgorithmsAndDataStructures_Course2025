//
// Created by benja on 26/03/25.
//

#include "mercaderAgua.hpp"


MercaderAgua::MercaderAgua(const std::string& name, double initialWaterReserve, double waterPrice)
    : EntidadGenerica(name)
    , m_waterReserve(initialWaterReserve)
    , m_waterPrice(waterPrice)
{
}

void MercaderAgua::showInfo() const
{
    std::cout << "Mercader de Agua: " << m_name << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Reserva de Agua: " << m_waterReserve << " litros" << std::endl;
    std::cout << "Precio por Litro: $" << m_waterPrice << std::endl;
    std::cout << "Número de Clientes: " << m_clients.size() << std::endl;
}

void MercaderAgua::doAction() const
{
    if (m_waterReserve <= 0) {
        std::cout << m_name << " no tiene agua para vender. Necesita reabastecerse." << std::endl;
        return;
    }

    std::cout << m_name << " está preparando su puesto de venta de agua." << std::endl;
    std::cout << "Está listo para atender a posibles clientes." << std::endl;
}

bool MercaderAgua::sellWater(const std::string& clientName, double quantity)
{
    if (quantity > m_waterReserve) {
        std::cout << "Lo siento, " << clientName << ". No hay suficiente agua disponible." << std::endl;
        return false;
    }

    // Vender agua
    m_waterReserve -= quantity;

    // Añadir cliente si no existe previamente
    if (std::find(m_clients.begin(), m_clients.end(), clientName) == m_clients.end()) {
        m_clients.push_back(clientName);
    }

    double totalCost = quantity * m_waterPrice;
    std::cout << clientName << " compra " << quantity << " litros de agua por $"
              << std::fixed << std::setprecision(2) << totalCost << std::endl;

    return true;
}

void MercaderAgua::restockWater(double quantity)
{
    m_waterReserve += quantity;
    std::cout << m_name << " ha reabastecido " << quantity << " litros de agua." << std::endl;
    std::cout << "Reserva actual: " << m_waterReserve << " litros" << std::endl;
}

void MercaderAgua::adjustPrice(double newPrice)
{
    double oldPrice = m_waterPrice;
    m_waterPrice = newPrice;
    std::cout << m_name << " ha cambiado el precio del agua de $"
              << oldPrice << " a $" << newPrice << " por litro." << std::endl;
}

std::vector<std::string> MercaderAgua::getClients() const
{
    return m_clients;
}
