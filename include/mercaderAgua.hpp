//
// Created by benja on 26/03/25.
//

#ifndef MERCADERAGUA_HPP
#define MERCADERAGUA_HPP

#include "entidadGenerica.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

class MercaderAgua : public EntidadGenerica
{
private:
    double m_waterReserve; // Reserva total de agua
    double m_waterPrice; // Precio por unidad de agua
    std::vector<std::string> m_clients; // Clientes del mercader

public:
    /**
     * @brief Constructor de MercaderAgua
     * @param name Nombre del mercader
     * @param initialWaterReserve Reserva inicial de agua
     * @param waterPrice Precio por unidad de agua
     */
    MercaderAgua(const std::string& name, double initialWaterReserve = 1000.0, double waterPrice = 5.0);

    /**
    * @brief Muestra la información detallada del mercader de agua
    * Implementación del método virtual puro de EntidadGenerica
    */
    void showInfo() const override;

    /**
    * @brief Acción principal del mercader de agua
    * Implementación del método virtual puro de EntidadGenerica
    */
    void doAction() const override;

    /**
     * @brief Vende agua a un cliente
     * @param clientName Nombre del cliente
     * @param quantity Cantidad de agua a vender
     * @return bool Indica si la venta fue exitosa
     */
    bool sellWater(const std::string& clientName, double quantity);

    /**
    * @brief Añade más agua a la reserva
    * @param quantity Cantidad de agua a añadir
    */
    void restockWater(double quantity);

    /**
     * @brief Cambia el precio del agua
     * @param newPrice Nuevo precio por unidad de agua
     */
    void adjustPrice(double newPrice);

    /**
     * @brief Obtiene la lista de clientes
     * @return std::vector<std::string> Lista de clientes
     */
    std::vector<std::string> getClients() const;

};

#endif //MERCADERAGUA_HPP
