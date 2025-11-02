bin/animacion: src/animacion.cpp
	c++ src/animacion.cpp -o bin/animacion -I include -lftxui-screen -lftxui-dom -lftxui-component -pthread
ejecutar: bin/animacion
	./bin/animacion
