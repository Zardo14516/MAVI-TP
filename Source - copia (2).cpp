#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ventana con Fondo");

    // Cargar la textura del fondo
    sf::Texture fondoTexture;
    std::string fondoPath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/fondo.jpg";

    if (!fondoTexture.loadFromFile(fondoPath)) {
        std::cerr << "Error al cargar la textura del fondo." << std::endl;
        return -1;
    }

    // Crear un sprite para el fondo
    sf::Sprite fondoSprite(fondoTexture);

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Limpiar la ventana
        window.clear();

        // Dibujar el fondo
        window.draw(fondoSprite);

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
