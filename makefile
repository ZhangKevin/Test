main: main.o address_ele.o
	g++ -o main main.o address_ele.o 
clean:
	rm -f main main.o address_ele.o
