#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero de Ajedrez");

    // Rutas de los sprites
    std::string basePath = "C:/Users/Usuario/Desktop/Lu Facultad/MAVI/Unidad3_Assets/";
    std::string blackSquarePath = basePath + "chessb.png";
    std::string whiteSquarePath = basePath + "chessw.png";

    // Cargar texturas
    sf::Texture blackTexture, whiteTexture;
    if (!blackTexture.loadFromFile(blackSquarePath) || !whiteTexture.loadFromFile(whiteSquarePath)) {
        std::cerr << "Error al cargar las texturas." << std::endl;
        return -1;
    }

    // Crear sprites
    sf::Sprite blackSquare(blackTexture);
    sf::Sprite whiteSquare(whiteTexture);

    // Tamaño de los cuadrados
    const float squareSize = 100.0f; // 800 / 8 = 100

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

        // Dibujar el tablero de ajedrez
        for (int y = 0; y < 8; ++y) {
            for (int x = 0; x < 8; ++x) {
                // Calcular la posición del cuadrado
                sf::Sprite& currentSquare = (x + y) % 2 == 0 ? whiteSquare : blackSquare;
                currentSquare.setPosition(x * squareSize, y * squareSize);
                currentSquare.setScale(squareSize / currentSquare.getTexture()->getSize().x,
                    squareSize / currentSquare.getTexture()->getSize().y);
                window.draw(currentSquare);
            }
        }

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
