all : prog excute clean
excute:
	 @echo "excuting..."
	./snaykie
prog : main.o snake.o board.o point.o
	@echo "building..."
	g++ main.cpp snake.cpp board.cpp point.cpp -o snaykie -lSDL -lSDL_image -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
