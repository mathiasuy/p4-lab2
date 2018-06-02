SOURCES := $(wildcard src/*/*.cpp src/*.cpp *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))

ejecutable: $(SOURCES)
	g++ -o $@ $^ -lsfml-window -lsfml-graphics -lsfml-system

%.o: %.cpp
	g++ -o $@ -c $^ -I.
	
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))