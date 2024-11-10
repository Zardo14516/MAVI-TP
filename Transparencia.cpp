#include <SFML/Graphics.hpp>

int main() {
    // Crear una ventana de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana de Ejemplo");

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

    // Cargar la textura para el sprite
    sf::Texture texture;
    if (!texture.loadFromFile("C:\\Users\\Usuario\\Desktop\\Lu Facultad\\MAVI\\Unidad3_Assets\\Blucircle.png")) {
        // Manejar el error si la imagen no se carga
        return -1;
    }

    // Crear un sprite con la textura
    sf::Sprite sprite(texture);

    // Obtener las dimensiones del sprite
    sf::FloatRect spriteBounds = sprite.getLocalBounds();
    float spriteWidth = spriteBounds.width;
    float spriteHeight = spriteBounds.height;

    // Calcular la posición para centrar el sprite en la ventana
    float centerX = (800 - spriteWidth) / 2;
    float centerY = (600 - spriteHeight) / 2;

    // Posicionar el sprite en el centro de la ventana
    sprite.setPosition(centerX, centerY);

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
