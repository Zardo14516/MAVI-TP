#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ventana con Cuadrados");

    // Rutas de los sprites
    std::string basePath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/";
    std::string spritesNames[] = { "cuad_red.png", "cuad_yellow.png", "cuad_blue.png", "cuad_grey.png" };
    sf::Texture textures[4];
    sf::Sprite sprites[4];

    // Cargar las texturas y crear los sprites
    for (int i = 0; i < 4; ++i) {
        if (!textures[i].loadFromFile(basePath + spritesNames[i])) {
            std::cerr << "Error al cargar la textura: " << spritesNames[i] << std::endl;
            return -1;
        }
        sprites[i].setTexture(textures[i]);
        sprites[i].setScale(100.0f / textures[i].getSize().x, 100.0f / textures[i].getSize().y); // Escalar a 100x100
    }

    // Posicionar los sprites de manera que se toquen
    sprites[0].setPosition(0, 0);        // Rojo - Arriba a la izquierda
    sprites[1].setPosition(100, 0);      // Amarillo - Arriba a la derecha
    sprites[2].setPosition(0, 100);      // Azul - Abajo a la izquierda
    sprites[3].setPosition(100, 100);    // Gris - Abajo a la derecha

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

        // Dibujar los sprites
        for (int i = 0; i < 4; ++i) {
            window.draw(sprites[i]);
        }

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}

