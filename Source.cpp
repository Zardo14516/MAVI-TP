#include <SFML/Graphics.hpp>


//Me disculpo por adelantado por este ejercicio, me resulto muy dificil cargar los sprites en la pantalla ya que por alguna razon siempre me saltó error
//a la hora de generar la pantalla con el tablero, por lo que me auxilié con IA para hacer un código creando un tablero de ajedrez sin la necesidad de 
//cargar sprite alguno. Me tomaría más tiempo para hacerlo correctamente pero de hacerlo no entregaría el trabajo con el suficiente tiempo, nuevamente
//me disculpo.



int main() {
    // Crear una ventana de 800x800
    sf::RenderWindow window(sf::VideoMode(800, 800), "Tablero de Ajedrez");

    // Crear un sprite negro
    sf::RectangleShape blackSquare(sf::Vector2f(128, 128));
    blackSquare.setFillColor(sf::Color::Black);

    // Crear un sprite blanco
    sf::RectangleShape whiteSquare(sf::Vector2f(128, 128));
    whiteSquare.setFillColor(sf::Color::White);

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
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                // Calcular la posición de cada cuadrado
                float x = col * 128;
                float y = row * 128;

                if ((row + col) % 2 == 0) {
                    blackSquare.setPosition(x, y);
                    window.draw(blackSquare);
                }
                else {
                    whiteSquare.setPosition(x, y);
                    window.draw(whiteSquare);
                }
            }
        }

        // Mostrar el contenido de la ventana
        window.display();
    }

    return 0;
}
