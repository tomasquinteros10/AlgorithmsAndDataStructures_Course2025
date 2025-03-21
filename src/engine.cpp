#include "engine.hpp"

void Engine::start(const PlayerInfo& player)
{
    m_player = player;
    initResources();
    initEntities();
    interactiveConsole();
}

void Engine::initResources()
{
    std::cout << GREEN << "Inicializando recursos..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::initEntities()
{
    std::cout << GREEN << "Inicializando entidades..." << RESET << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Engine::showBanner()
{
    std::cout << GREEN << "============================" << RESET << std::endl;
    std::cout << GREEN << "       SISTEMA REFUGIO 33   " << RESET << std::endl;
    std::cout << GREEN << "============================" << RESET << std::endl;
    std::cout << WHITE << "\t\t\t\tLíder: " << m_player.name << " / Lvl: " << m_player.level << RESET << std::endl;
    std::cout << GREEN << "Comandos disponibles:" << RESET << std::endl;
    std::cout << GREEN << " - show board   : Mostrar tablero" << RESET << std::endl;
    std::cout << GREEN << " - show details : Mostrar detalles de un elemento" << RESET << std::endl;
    std::cout << GREEN << " - exit         : Salir del juego" << RESET << std::endl;
    std::cout << GREEN << "=================================" << RESET << std::endl;
}

void Engine::clearScreen()
{
    std::system(CLEAR_SCREEN);
}

void Engine::interactiveConsole()
{
    bool keepRunning = true;
    while (keepRunning)
    {
        clearScreen();
        showBanner();
        std::string input;
        std::cout << GREEN << "> " << RESET;
        std::cin >> input;

        if (input == "board")
        {
            std::cout << GREEN << "Mostrando tablero..." << RESET << std::endl;
        }
        else if (input == "details")
        {
            std::cout << GREEN << "Mostrando detalles..." << RESET << std::endl;
        }
        else if (input == "exit")
        {
            std::cout << GREEN << "Saliendo del juego..." << RESET << std::endl;
            keepRunning = false;
        }
        else
        {
            std::cout << GREEN << "Operación desconocida. Inténtalo de nuevo." << RESET << std::endl;
        }
    }
    clearScreen();
}
