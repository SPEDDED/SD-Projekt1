# Kompilator i flagi
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude

# Pliki i foldery
SRC_DIR = src
OBJ_DIR = obj
BIN = main

# Znajdź wszystkie pliki .cpp w src/
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
# Zamień ścieżki .cpp na .o w folderze obj/
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Główny cel
all: $(OBJ_DIR) $(BIN)

# Tworzenie folderu na pliki binarne
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Linkowanie programu
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Kompilacja plików źródłowych do obiektowych
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Czyszczenie projektu
clean:
	rm -rf $(OBJ_DIR) $(BIN)