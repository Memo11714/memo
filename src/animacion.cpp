#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <string>
#include <list>
#include <thread>
#include <chrono>

using namespace std;
using namespace ftxui;

class Dibujo {
private:
    list<string> dibujo;
    int x = 0;
    int y = 0;

public:
    Dibujo(list<string> d, int posx, int posy) {
        dibujo = d;
        x = posx;
        y = posy;
    }

    void Mover(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void SetDibujo(list<string> nuevo) {
        dibujo = nuevo;
    }

    void Imprimir(Screen &pantalla) {
        int fila = 0;
        for (auto &linea : dibujo) {
            int columna = 0;
            for (auto &letra : linea) {
                if (letra != ' ') {
                    Pixel &pixel = pantalla.PixelAt(x + columna, y + fila);
                    pixel.character = letra;
                    pixel.foreground_color = Color::Yellow;
                }
                columna++;
            }
            fila++;
        }
    }
};

int main() {
    Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());

  
    list<string> mono_inicial = {
        "  O  ",
        " /|\\ ",
        " / \\ "
    };

    list<string> mono_agachado = {
        "  O  ",
        " /|\\ ",
        "_/ \\_"
    };

    list<string> mono_pateando = {
        "  O  ",
        " /|\\ ",
        "  /_ "
    };

    list<string> balon_ascii = {"o"};
    list<string> porteria_ascii = {
        "  _______  ",
        " |       | ",
        " |       | ",
        " |       | "
    };

    Dibujo mono(mono_inicial, 5, 10);
    Dibujo balon(balon_ascii, 12, 11);
    Dibujo porteria(porteria_ascii, 40, 8);

   
    for (int paso = 0; paso < 60; paso++) {
        pantalla.Clear();

       
        if (paso < 10)
            mono.SetDibujo(mono_inicial);
        else if (paso < 20)
            mono.SetDibujo(mono_agachado); 
        else if (paso < 25)
            mono.SetDibujo(mono_pateando); 
        else
            mono.SetDibujo(mono_inicial); 

       
        if (paso >= 25)
            balon.Mover(1, 0);

        mono.Imprimir(pantalla);
        balon.Imprimir(pantalla);
        porteria.Imprimir(pantalla);

        pantalla.Print();
        cout << flush;

        this_thread::sleep_for(chrono::milliseconds(120));
    }

    
    pantalla.Clear();
    list<string> mensaje = {
        "  ██████   ██████   ██████   ██████  ██      ",
        " ██       ██    ██ ██    ██ ██    ██ ██      ",
        " ██   ███ ██    ██ ██    ██ ██    ██ ██      ",
        " ██    ██ ██    ██ ██    ██ ██    ██ ██      ",
        "  ██████   ██████   ██████   ██████  ███████ ",
        
    };

    int y = 8;
    for (auto &linea : mensaje) {
        int x = 10;
        for (auto &letra : linea) {
            if (letra != ' ') {
                Pixel &pixel = pantalla.PixelAt(x, y);
                pixel.character = letra;
                pixel.foreground_color = Color::Green;
            }
            x++;
        }
        y++;
    }

    pantalla.Print();
    cout << flush;

    return 0;
}
