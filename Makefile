# Nombre del compilador
CXX = g++

# Archivos fuente
SRCS = Jacobi.cpp x2.cpp x3.cpp x4.cpp x5.cpp

# Archivo ejecutable
TARGET = jacobi

# Flags del compilador
CXXFLAGS = -std=c++11

# Regla por defecto
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)

# Limpiar los archivos generados
clean:
	rm -f $(TARGET)
