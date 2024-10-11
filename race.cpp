#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <chrono>
#include <mutex>

std::mutex mtx; // Mutex para sincronizar la salida en consola
int autoCount = 0; // Variable para llevar el conteo de autos que terminan
std::vector<int> posiciones; // Vector para registrar el orden de llegada de los autos

// Función para simular el avance de cada auto
void carrera(int id, int distanciaTotal) {
    int distanciaRecorrida = 0; // Distancia que ha recorrido el auto
    std::random_device rd; // Dispositivo de generación de números aleatorios
    std::mt19937 gen(rd()); // Motor de números aleatorios Mersenne Twister
    std::uniform_int_distribution<> avanceDist(1, 10); // Distribución para el avance (1 a 10 metros)
    std::uniform_int_distribution<> pausaDist(100, 500); // Distribución para la pausa (100 a 500 ms)

    // Bucle hasta que el auto haya recorrido toda la distancia
    while (distanciaRecorrida < distanciaTotal) {
        int avance = avanceDist(gen); // Calcular avance aleatorio
        distanciaRecorrida += avance;
        if (distanciaRecorrida > distanciaTotal) distanciaRecorrida = distanciaTotal; // Evitar sobrepasar la meta

        // Bloquear mutex para sincronizar la salida
        mtx.lock();
        std::cout << "Auto" << id << " avanza " << avance << " metros (total: " << distanciaRecorrida << " metros)" << std::endl;
        mtx.unlock();

        // Pausa aleatoria para simular la velocidad variable
        std::this_thread::sleep_for(std::chrono::milliseconds(pausaDist(gen)));
    }

    // Registrar el lugar de llegada
    mtx.lock();
    autoCount++;
    posiciones.push_back(id); // Guardar el ID del auto en la posición correspondiente
    std::cout << "Auto" << id << " ha terminado la carrera en el lugar " << autoCount << "!" << std::endl;
    mtx.unlock();
}

// Función para mostrar el podio al final de la carrera
void mostrarPodio(int numAutos) {
    std::cout << "\n========== Podio ==========" << std::endl;

    // Mostrar 1er lugar
    if (numAutos > 0) {
        std::cout << "1er Lugar: Auto" << posiciones[0] << std::endl;
    } else {
        std::cout << "1er Lugar: X" << std::endl;
    }

    // Mostrar 2do lugar
    if (numAutos > 1) {
        std::cout << "2do Lugar: Auto" << posiciones[1] << std::endl;
    } else {
        std::cout << "2do Lugar: X" << std::endl;
    }

    // Mostrar 3er lugar
    if (numAutos > 2) {
        std::cout << "3er Lugar: Auto" << posiciones[2] << std::endl;
    } else {
        std::cout << "3er Lugar: X" << std::endl;
    }

    std::cout << "============================" << std::endl;

    // Mostrar el resto de los autos si hay más de tres
    if (numAutos > 3) {
        std::cout << "\nAutos restantes:" << std::endl;
        for (int i = 3; i < numAutos; ++i) {
            std::cout << i + 1 << "to Lugar: Auto" << posiciones[i] << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    // Validar los argumentos del programa
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <distancia> <numero_de_autos>" << std::endl;
        return 1;
    }

    // Convertir los argumentos de entrada
    int distanciaTotal = std::stoi(argv[1]); // Distancia total de la carrera
    int numAutos = std::stoi(argv[2]); // Número de autos

    std::vector<std::thread> autos; // Vector para almacenar las hebras (hilos) de cada auto

    // Crear y lanzar una hebra para cada auto
    for (int i = 0; i < numAutos; ++i) {
        autos.push_back(std::thread(carrera, i, distanciaTotal));
    }

    // Esperar a que todas las hebras terminen
    for (auto& t : autos) {
        t.join();
    }

    // Mostrar el podio al final de la carrera
    mostrarPodio(numAutos);

    return 0;
}
