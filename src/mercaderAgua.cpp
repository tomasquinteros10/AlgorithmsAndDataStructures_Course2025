//
// Created by tomas on 2/4/2025.
//
#include "mercaderAgua.hpp"
#include <iostream>

MercaderAgua :: MercaderAgua (const std::string& nombre, int agua, double tasa, bool confiable): EntidadGenerica(nombre)
    ,m_unidadesAgua(agua), m_tasaCambio(tasa), m_esConfiable(confiable)
{
}


void MercaderAgua :: showInfo() const override
            {
                std::cout << "💧 Mercader de Agua: '" << m_name << "'\n"
                          << " - Agua disponible : " << m_unidadesAgua << " unidades\n"
                          << " - Tasa de cambio   : 1 agua = " << m_tasaCambio << " recursos\n"
                          << " - Estado moral     : " << (m_esConfiable ? "Confiable" : "Especulador") << "\n";

                std::cout << "💬" << m_name << ">>> Tengo el agua más pura del Yermo..." << std::endl;
                if (m_esConfiable)
                {
                    std::cout << "Ofrezco un trato justo: 1 unidad de agua por " << m_tasaCambio << " unidades de recursos."
                              << std::endl;
                }
                else
                {
                    std::cout << "Mmm... esos recursos no valen nada, pero si me das el doble, hablamos." << std::endl;
                }
            }

void MercaderAgua :: refillWater(int cantidad)
            {
                m_unidadesAgua += cantidad;
            }
bool MercaderAgua :: trade(int recursosDisponibles)
            {
                double requerido = m_tasaCambio;
                if (!m_esConfiable)
                {
                    requerido *= 2;
                }

                if (recursosDisponibles >= requerido && m_unidadesAgua > 0)
                {
                    std::cout << "💬" << m_name << ">>> Bussinesssss" << std::endl;
                    m_unidadesAgua -= requerido;
                    return true;
                }
                else
                {
                    std::cout << "💬" << m_name << ">>> Acaso crees que soy Santa Claus? Vuelve cuando tengas recursos"
                              << std::endl;
                    return false;
                }
            }