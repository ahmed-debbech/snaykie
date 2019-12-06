all : prog excute clean
excute:
	 @echo "excuting..."
	./snaykie
prog : main.o snake.o board.o point.o arbitrator.o node.o menu.o
	@echo "building..."
	g++ main.cpp snake.cpp board.cpp arbitrator.cpp point.cpp node.cpp menu.cpp button.cpp widget.cpp -o snaykie -lSDL -lSDL_image -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
