SOURCES := $(wildcard src/*/*.cpp src/*.cpp *.cpp)
OBJECTS := $(subst .cpp,.o,$(SOURCES))
EXE := ejecutable.exe
OBJDIR := obj
LIBS :=
INCLUDE := -I.
FLAGS :=
CC := g++
ejecutable: $(SOURCES)
	$(CC) -o $@ $^ $(INCLUDE) $(LIBS)

$(OBJDIR)/%.o: %.cpp
	$(CC) -o $@ -c $^ $(INCLUDE)
		
info:
	$(info $(SOURCES))
	$(info $(OBJECTS))
	
clean:
	rm $(EXE)
	rm $(OBJECTS)

openw:
	./ejecutable.exe

openl:
	./ejecutable
