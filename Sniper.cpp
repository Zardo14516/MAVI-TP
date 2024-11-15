#include <SFML/Graphics.hpp>


//Sniper//


int main() {
    // Crear una ventana de 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ventana de Ejemplo");
    // Crear puntos rojos para las esquinas
    sf::CircleShape cornerPoint(5); // Radio de 5 p�xeles
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
        // Mostrar el contenido de la ventana
        window.display();
    }
    return 0;
}
