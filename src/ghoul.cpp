//
// Created by tomas on 2/4/2025.
//
#include "ghoul.cpp"
#include <iostream>
#include <random>

        Ghoul :: Ghoul(const std::string& nombre)
        : EntidadGenerica(nombre)
        , m_cantidad(generarCantidad())
        , m_saludBase(generarSalud())
        , m_danyoBase(generarDanyo())
                {
                }
void Ghoul ::  showInfo() const override
        {
            std::cout << "☣️ HORDA DE GHOULS: " << m_name << "\n"
                      << " - Individuos: " << m_cantidad << "\n"
                      << " - Salud por ghoul: " << m_saludBase << "\n"
                      << " - Daño por ghoul: " << m_danyoBase << "\n";
        }


int Ghoul ::  danyoTotal() const
        {
            return m_danyoBase * m_cantidad;
        }

/**
 * @brief Simula una reducción del tamaño de la horda
 * @param eliminados Cantidad de ghouls eliminados
 */
void Ghoul ::  eliminarGhouls(int eliminados)
        {
            m_cantidad -= eliminados;
            if (m_cantidad <= 0)
            {
                m_cantidad = 0;
                std::cout << "☠️ ¡La horda ha sido completamente aniquilada!" << std::endl;
            }
            else
            {
                std::cout << "⚠️ Han sido eliminados " << eliminados << " ghouls. Restan: " << m_cantidad << std::endl;
            }
        }

/**
 * @brief Devuelve si la horda sigue siendo una amenaza
 */
bool Ghoul ::  sigueActiva() const
        {
            return m_cantidad > 0;
        }

