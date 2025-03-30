#include "refugio.hpp"

Refugio::Refugio(const std::string& name, float defense, float attack)
    : EntidadGenerica(name)
    , m_defense(defense)
    , m_attack(attack)
{
}

void Refugio::showInfo() const
{
    std::cout << "🏠 Refugio: " << m_name << "\n";
    std::cout << "\t🛡️  Defensa: " << m_defense << "\n";
    std::cout << "\t⚔️  Ataque: " << m_attack << "\n";
    std::cout << "👥 Moradores: ";
    for (int refugee = 0; refugee < m_refugees.size(); refugee++)
    {
        std::cout << "\t - " << m_refugees.at(refugee) << std::endl;
    }
    std::cout << "\n";
    std::cout << "\t📦 Recursos: \n";
}

void Refugio::doAction() const
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addRefugee(const std::string& refugee)
{
    throw std::runtime_error("Not implemented yet");
}

void Refugio::addResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
}

bool Refugio::consumeResource(const std::string& resource, float amount)
{
    throw std::runtime_error("Not implemented yet");
    return false;
}

void Refugio::registerVisitant(const std::string& nombre, const Faccion faccion)
{
    if (!isSafeFaction(faccion)) {
        std::cout << "Acceso denegado: La facción " << faccionToString(faccion)
                    << " no es segura para el refugio." << std::endl;
        return;
    }

    Visitante nuevoVisitante{nombre, faccion};
    m_visitants->push_front(nuevoVisitante);
    std::cout << "Visitante: " << nombre << " registrado existosamente en el refugio." << std::endl;

}

void Refugio::showVisits()
{
    std::cout << "📖 Registro de visitas al Refugio " << m_name << ":\n";
    printRecursive(m_visitants->get_head());
}

void Refugio::printRecursive(DoublyListNode<Visitante>* mNode)
{
    if (!mNode)
    {
        std::cout << "Fin del registro!" << std::endl;
        return;
    }

    std::cout << "\t - " << mNode->data.nombre << " de la facción " << faccionToString(mNode->data.faccion)  << std::endl;
    printRecursive(mNode->next);
}

bool Refugio::hasFactionVisited(Faccion faccion) const
{
    DoublyListNode<Visitante>* aux = m_visitants->get_head();

    while (aux->data.faccion != faccion)
    {
        if (aux->next == nullptr) // Se llego al final de la lista de visitantes y no se encontro la faccion
        {
            std::cout << "No hay registro de que la facción " << faccionToString(faccion)
                        << " haya visitado el refugio." << std::endl;
            return false;
        }

        aux = aux->next;
    }

    std::cout << "La facción " << faccionToString(faccion)
                << " si ha visitado el refugio." << std::endl;
    return true;
}

std::string Refugio::faccionToString(Faccion faccion) const
{
    switch (faccion)
    {
        case Faccion::LOCALES: return "Locales"; break;
        case Faccion::CARAVANAS_COMERCIALES: return "Caravanas"; break;
        case Faccion::ASALTANTES: return "Asaltantes"; break;
        case Faccion::SUPERMUTANTES: return "Supermutantes"; break;
        case Faccion::HERMANDAD_DE_ACERO: return "Hermandad de acero"; break;
        case Faccion::ENCLAVE: return "Enclave"; break;
        default: return "Desconocida"; break;
    }
}

bool Refugio::isSafeFaction(const Faccion faccion) const
{
    return !(faccion == Faccion::ENCLAVE ||
             faccion == Faccion::SUPERMUTANTES ||
             faccion == Faccion::ASALTANTES);
}

