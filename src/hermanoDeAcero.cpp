//
// Created by tomas on 2/4/2025.
//
#include "hermanoDeAcero.hpp"
#include <iostream>

HermanoAcero :: HermanoAcero (const std::string& nombre, int entrenamiento = 100) : EntidadGenerica(nombre)
       , m_entrenamiento(entrenamiento)
      , m_suministros(80)
      , m_enRefugio(false)
      , m_consumoMinimo(20)
            {
            }

void HermanoAcero :: showInfo() const override
        {
            std::cout << "⚙️ Hermano del Acero: " << m_name << "\n"
                      << " - Nivel de entrenamiento: " << m_entrenamiento << "\n"
                      << " - Suministros actuales: " << m_suministros << "\n"
                      << " - En refugio: " << (m_enRefugio ? "Sí" : "No") << "\n";
        }

int HermanoAcero :: solicitarIngreso(int recursosDisponibles)
        {
            if (recursosDisponibles >= m_consumoMinimo)
            {
                m_enRefugio = true;
                std::cout << "💬" << m_name <<" >>> Por la tecnología, serviré a este refugio." << std::endl;
                return m_consumoMinimo;
            }
            else
            {
                std::cout << "💬" << m_name << " >>> Sus recursos no están a la altura de la Hermandad." << std::endl;
                return 0;
            }
        }

void HermanoAcero :: consumir()
        {
            if (m_suministros >= m_consumoMinimo)
            {
                m_suministros -= m_consumoMinimo;
                std::cout << "💬" << m_name << " >>> Reabastecido. Listo para defender." << std::endl;
            }
            else
            {
                m_enRefugio = false;
                std::cout << "💬" << m_name << " >>> Sin suministros. Este refugio no merece protección." << std::endl;
            }
        }

bool HermanoAcero :: estaEnRefugio() const
        {
            return m_enRefugio;
        }