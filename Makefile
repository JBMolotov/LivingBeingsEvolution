all: clean
	@g++ -o main main.cpp -lGL -lGLU -lglfw -lGLEW -lglut -lm
run: all 
	./main
clean:
	rm main || true
