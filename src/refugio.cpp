#include "Refugio.hpp"

Refugio::Refugio(const std::string& name, float defense, float attack)
    : EntidadGenerica(name)
    , m_defense(defense)
    , m_attack(attack)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << getName() << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: ";
    for (const auto& refugee : m_refugees)
    {
        std::cout << refugee << ", ";
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
    for (const auto& resource : m_resources)
    {
        std::cout << "   - " << resource.first << ": " << resource.second << "\n";
    }
}

void Refugio::doAction() const
{
    std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    std::runtime_error("Not implemented yet");
}

void Refugio::addResource(const std::string& resource, float amount)
{
    std::runtime_error("Not implemented yet");
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    std::runtime_error("Not implemented yet");
}