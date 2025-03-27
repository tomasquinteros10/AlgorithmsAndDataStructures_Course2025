//
// Created by benja on 26/03/25.
//

#include "saqueadores.hpp"

Saqueadores::Saqueadores(const std::string& name, int memberCount, int initialStrength)
    : EntidadGenerica(name)
    , m_memberCount(memberCount)
    , m_strength(initialStrength)
    , m_stolenResources(0.0)
    , m_estrategia(EstrategiaSaqueo::OPORTUNISTA)
{
    // Inicializar tipos de objetivos por defecto
    m_targetTypes = {"Refugio", "Mercader", "Almacén"};
}

void Saqueadores::showInfo() const
{
    std::cout << "Grupo de Saqueadores: " << m_name << std::endl;
    std::cout << "Número de Miembros: " << m_memberCount << std::endl;
    std::cout << "Fuerza del Grupo: " << m_strength << std::endl;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Recursos Robados: " << m_stolenResources << std::endl;

    std::cout << "Tipos de Objetivos: ";
    for (const auto& tipo : m_targetTypes) {
        std::cout << tipo << " ";
    }
    std::cout << std::endl;

    std::string estrategiaStr;
    switch (m_estrategia) {
        case EstrategiaSaqueo::AGRESIVA: estrategiaStr = "Agresiva"; break;
        case EstrategiaSaqueo::SIGILOSA: estrategiaStr = "Sigilosa"; break;
        case EstrategiaSaqueo::OPORTUNISTA: estrategiaStr = "Oportunista"; break;
    }
    std::cout << "Estrategia Actual: " << estrategiaStr << std::endl;
}

void Saqueadores::doAction() const
{
    std::cout << m_name << " está planeando su próximo objetivo..." << std::endl;

    switch (m_estrategia) {
        case EstrategiaSaqueo::AGRESIVA:
            std::cout << "Estrategia Agresiva: Preparándose para un ataque directo." << std::endl;
        break;
        case EstrategiaSaqueo::SIGILOSA:
            std::cout << "Estrategia Sigilosa: Buscando el momento preciso para atacar." << std::endl;
        break;
        case EstrategiaSaqueo::OPORTUNISTA:
            std::cout << "Estrategia Oportunista: Observando posibles blancos débiles." << std::endl;
        break;
    }
}

bool Saqueadores::atacar(const std::string& targetName)
{
    // Simulación de probabilidad de éxito basada en estrategia y fuerza
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, 1);

    double probabilidadExito = 0.0;
    switch (m_estrategia) {
        case EstrategiaSaqueo::AGRESIVA:
            probabilidadExito = 0.7 * (m_strength / 100.0);
        break;
        case EstrategiaSaqueo::SIGILOSA:
            probabilidadExito = 0.5 * (m_strength / 100.0);
        break;
        case EstrategiaSaqueo::OPORTUNISTA:
            probabilidadExito = 0.3 * (m_strength / 100.0);
        break;
    }

    bool exito = dis(gen) < probabilidadExito;

    if (exito) {
        // Simulación de robo de recursos
        std::uniform_real_distribution<> recursosDis(10.0, 100.0);
        double recursosRobados = recursosDis(gen);

        m_stolenResources += recursosRobados;

        std::cout << m_name << " ha saqueado exitosamente a " << targetName << std::endl;
        std::cout << "Recursos robados: " << std::fixed << std::setprecision(2)
                  << recursosRobados << std::endl;

        return true;
    } else {
        std::cout << m_name << " ha fallado en su intento de saquear a " << targetName << std::endl;
        return false;
    }
}

void Saqueadores::cambiarEstrategia(EstrategiaSaqueo nuevaEstrategia)
{
    m_estrategia = nuevaEstrategia;
    std::cout << m_name << " ha cambiado su estrategia de saqueo." << std::endl;
}

void Saqueadores::añadirTipoObjetivo(const std::string& tipoObjetivo)
{
    m_targetTypes.push_back(tipoObjetivo);
    std::cout << m_name << " ahora busca objetivos de tipo: " << tipoObjetivo << std::endl;
}

double Saqueadores::getRecursosRobados() const
{
    return m_stolenResources;
}

void Saqueadores::incrementarFuerza(int incremento)
{
    m_strength += incremento;
    std::cout << m_name << " ha incrementado su fuerza en " << incremento << std::endl;
    std::cout << "Fuerza actual: " << m_strength << std::endl;
}