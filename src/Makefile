all : prog excute clean
excute:
	 @echo "excuting..."
	./snaykie
prog : main.o snake.o sound.o board.o point.o arbitrator.o node.o menu.o widget.o button.o toggle.o
	@echo "building..."
	g++ main.cpp snake.cpp sound.cpp board.cpp arbitrator.cpp point.cpp node.cpp menu.cpp button.cpp widget.cpp toggle.cpp -o snaykie -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
clean:
	@echo "cleaning up..."
	rm *.o
