CC = g++

CFLAGS = -c -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

OBJECTS = Square_main.o Square_io.o Square_solver.o Square_tests.o


all: Square.exe


Square.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o Square.exe


Square_main.o: Square_main.cpp
	$(CC) $(CFLAGS) Square_main.cpp


Square_io.o: Square_io.cpp
	$(CC) $(CFLAGS) Square_io.cpp


Square_solver.o: Square_solver.cpp
	$(CC) $(CFLAGS) Square_solver.cpp


Square_tests.o: Square_tests.cpp
	$(CC) $(CFLAGS) Square_tests.cpp
