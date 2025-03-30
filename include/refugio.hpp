#ifndef REFUGIO_HPP
#define REFUGIO_HPP

#include "entidadGenerica.hpp"
#include "wrapperVector.hpp"
#include <iostream>
#include <string>
#include <utility>
#include "list.hpp"

/**
 * @class Refugio
 * @brief Representa un refugio dentro del Yermo
 *
 * Un refugio proporciona seguridad y almacenamiento de recursos para los moradores.
 * Tiene capacidades de defensa y ataque, además de una lista de refugiados y recursos disponibles.
 */
class Refugio : public EntidadGenerica
{
    enum class Faccion
    {
        HERMANDAD_DE_ACERO, // Grupo militarizado que busca preservar la tecnologia. (Buenos)
        ENCLAVE, // Restos del antiguo gobierno de EE.UU, con ideologia autoritaria. (Malos)
        SUPERMUTANTES, //Criaturas mutantes que suelen ser hostiles. (Malos)
        ASALTANTES,
        CARAVANAS_COMERCIALES, // Grupos de mercaderes que viajan entre asentamientos. (Buenos)
        LOCALES // Personas que viven en el refugio.
    };

    struct Visitante {
        std::string nombre;
        Faccion faccion;
    };
private:
    float m_defense;                                          ///< Nivel de defensa del refugio
    float m_attack;                                           ///< Capacidad de ataque del refugio
    wrapperVector<std::string> m_refugees;                    ///< Lista de moradores dentro del refugio
    wrapperVector<std::pair<std::string, float>> m_resources; ///< Lista de recursos con su cantidad
    DoublyLinkedList<Visitante>* m_visitants;                  ///< Lista de visitantes registrados

    void printRecursive(DoublyListNode<Visitante>* mNode);

    /**
     * @brief Devuelve la faccion en formato de string para su impresion.
     */
    std::string faccionToString(Faccion faccion) const;

public:
    /**
     * @brief Constructor del refugio
     *
     * @param name Nombre del refugio
     * @param defense Nivel de defensa inicial
     * @param attack Nivel de ataque inicial
     */
    Refugio(const std::string& name, float defense, float attack);

    /**
     * @brief Muestra la información del refugio
     */
    void showInfo() const override;

    /**
     * @brief Ejecuta una acción específica del refugio
     */
    void doAction() const override;

    /**
     * @brief Agrega un morador al refugio
     * @param refugee Nombre del morador
     */
    void addRefugee(const std::string& refugee);

    /**
     * @brief Agrega un recurso al refugio
     * @param resource Nombre del recurso
     * @param amount Cantidad del recurso
     */
    void addResource(const std::string& resource, float amount);

    /**
     * @brief Consume un recurso del refugio
     * @param resource Nombre del recurso a consumir
     * @param amount Cantidad a consumir
     * @return true si el consumo fue exitoso, false si no hay suficiente recurso
     */
    bool consumeResource(const std::string& resource, float amount);

    /**
     * @brief Registra un visitante en el refugio (nombre y facción)
     * @param nombre Nombre del visitante
     * @param faccion Facción del visitante
     */
    void registerVisitant(const std::string& nombre, Faccion faccion);

    /**
     * @brief Muestra todos los visitantes registrados
     */
    void showVisits();

    /**
     * @brief Busca si una facción ha visitado el refugio
     */
    bool hasFactionVisited(const Faccion faccion) const;

    /**
     *
     * @param faccion Faccion a verificar si es segura.
     * @return Booleano si es segura o no.
     */
    bool Refugio::isSafeFaction(const Faccion faccion) const;


};

#endif // REFUGIO_HPP
