#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana de Ejemplo");

    // Cargar la textura del sprite
    sf::Texture texture;
    std::string texturePath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/Blucircle.png";

    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error al cargar la textura desde " << texturePath << std::endl;
        return -1;
    }

    // Crear el sprite
    sf::Sprite sprite(texture);

    // Escalar el sprite a 15x15
    sprite.setScale(15.0f / texture.getSize().x, 15.0f / texture.getSize().y);

    // Posicionar el sprite en el centro de la ventana
    sprite.setPosition(400 - sprite.getGlobalBounds().width / 2,
        300 - sprite.getGlobalBounds().height / 2); // Centrar el sprite

// Crear puntos rojos para las esquinas
    sf::CircleShape cornerPoint(5); // Radio de 5 píxeles
    cornerPoint.setFillColor(sf::Color::Red);

    // Posiciones de las esquinas
    sf::Vector2f corners[] = {
        {0, 0},                        // Esquina superior izquierda
        {790, 0},                      // Esquina superior derecha
        {0, 590},                      // Esquina inferior izquierda
        {790, 590}                     // Esquina inferior derecha
    };

    // Bucle principal
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Limpiar la ventana
        window.clear(sf::Color::Black);

        // Dibujar los puntos en las esquinas
        for (const auto& corner : corners) {
            cornerPoint.setPosition(corner);
            window.draw(cornerPoint);
        }

        // Dibujar el sprite en el centro
        window.draw(sprite);

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
