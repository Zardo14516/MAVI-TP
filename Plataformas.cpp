#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ventana con Plataforma");

    // Cargar la textura de la plataforma
    sf::Texture plataformaTexture;
    std::string plataformaPath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/plataforma.jpg";

    if (!plataformaTexture.loadFromFile(plataformaPath)) {
        std::cerr << "Error al cargar la textura de la plataforma." << std::endl;
        return -1;
    }

    // Crear los sprites para la plataforma
    sf::Sprite sprites[6];

    // Inicializar los sprites con la textura
    for (int i = 0; i < 6; ++i) {
        sprites[i].setTexture(plataformaTexture);
    }

    // Escalar los primeros cinco sprites
    sprites[0].setScale(50.0f / plataformaTexture.getSize().x, 50.0f / plataformaTexture.getSize().y);   // 50x50
    sprites[1].setScale(50.0f / plataformaTexture.getSize().x, 100.0f / plataformaTexture.getSize().y);  // 50x100
    sprites[2].setScale(50.0f / plataformaTexture.getSize().x, 150.0f / plataformaTexture.getSize().y);  // 50x150
    sprites[3].setScale(50.0f / plataformaTexture.getSize().x, 200.0f / plataformaTexture.getSize().y);  // 50x200
    sprites[4].setScale(50.0f / plataformaTexture.getSize().x, 250.0f / plataformaTexture.getSize().y);  // 50x250

    // Escalar el sexto sprite a 250x50
    sprites[5].setScale(250.0f / plataformaTexture.getSize().x, 50.0f / plataformaTexture.getSize().y); // 250x50

    // Ubicar los sprites en la esquina inferior izquierda
    float startX = 0; // Posición inicial en X
    float startY = 800; // Posición Y 

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

        // Dibujar los primeros cinco sprites en la misma posición Y
        for (int i = 0; i < 5; ++i) {
            // Posición de cada sprite, alejados 100 píxeles entre sí
            sprites[i].setPosition(startX + i * 100, startY - (sprites[i].getGlobalBounds().height)); // Ajusta la posición Y
            window.draw(sprites[i]);
        }

        // Posicionar el sexto sprite en la coordenada (550, 450)
        sprites[5].setPosition(550, 450);
        window.draw(sprites[5]);

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}

