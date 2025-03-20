#include <iostream>
#include <sstream>
#include <thread>

int main() {
    std::cout << "Iniciando sistema de control 'Refugio 33'" << std::endl;
    std::cout << "Cargando: ";
    for (int i = 0; i <= 100; i += 10)
    {
        std::cout << "[" << i << "%]" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        if (i < 100)
        {
            std::cout << "\b\b\b\b\b" << std::flush;
        }
    }
    std::cout << std::endl;
    // Iniciar sistema de control
    // Engine::start();
    std::cout << "Sistema de control 'Refugio 33' iniciado correctamente" << std::endl;
    return 0;
}
......
asddasdas