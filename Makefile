SOURCES := $(wildcard src/*/*.cpp src/*.cpp *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
OBJDIR := /obj
LIBS :=
INCLUDE := -I.
CC := g++

ejecutable: $(SOURCES)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

$(OBJDIR)/%.o: %.cpp
	$(CC) -o $@ -c $^ $(INCLUDE)
	
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
	
clean:
	rm $(OBJECTS)