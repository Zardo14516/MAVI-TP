#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ventana con Cuadro Amarillo Giratorio");

    // Cargar la textura del cuadro amarillo
    sf::Texture cuadroTexture;
    std::string cuadroPath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/cuad_yellow.png";

    if (!cuadroTexture.loadFromFile(cuadroPath)) {
        std::cerr << "Error al cargar la textura del cuadro amarillo." << std::endl;
        return -1;
    }

    // Crear un sprite para el cuadro amarillo
    sf::Sprite cuadroSprite(cuadroTexture);

    // Escalar el sprite a 250x250
    cuadroSprite.setScale(250.0f / cuadroTexture.getSize().x, 250.0f / cuadroTexture.getSize().y);

    // Posicionar el sprite en el centro de la ventana
    cuadroSprite.setPosition(400, 400); // Centro de la ventana de 800x800

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

        // Girar el sprite
        cuadroSprite.rotate(0.033f); 

        // Dibujar el sprite
        window.draw(cuadroSprite);

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
