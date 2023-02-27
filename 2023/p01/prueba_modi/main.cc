#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "bigint.h"
#include "calculator.h"

// Leer fichero -> Meterlo en un vector menos el primer elemento  ->
// -> Primer elemento en size_t 
int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Error: Usa: " << argv[0] << " <archivo> <salida>" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error al abrir el archivo: " << argv[1] << std::endl;
    return 1;
  }
  std::ofstream output(argv[2]);
  if (!output.is_open()) {
    std::cerr << "Error al abrir el archivo: " << argv[2] << std::endl;
    return 1;
  }
  std::string line;
  std::vector<std::vector<std::string>> claves;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<std::string> claves_lineas;
    std::string clave;
    
    // Leyendo el archivo línea por línea y poniendo los valores en un vector de cadenas.
    while (iss >> clave) {
      claves_lineas.push_back(clave);
    }
    claves.push_back(claves_lineas);
  }

  try {
    // Obteniendo la base de la primera línea del archivo.
    const size_t base = std::stoi(claves[0][claves[0].size() - 1]);
    claves.erase(claves.begin());     // Se elimina la primera linea del vector (base =)
    Calculator<BigInt<2>> calculator_2;
    Calculator<BigInt<8>> calculator_8;
    Calculator<BigInt<10>> calculator_10;
    Calculator<BigInt<16>> calculator_16;
    enum bases { base2 = 2, base8 = 8, base10 = 10, base16 = 16 };
    switch (base) {
      case base2:
        calculator_2.SetClave(claves);
        calculator_2.ProcessClaves();
        output << calculator_2;
        break;
      case base8:
        calculator_8.SetClave(claves);
        calculator_8.ProcessClaves();
        output << calculator_8;
        break;
      case base10:
        calculator_10.SetClave(claves);
        calculator_10.ProcessClaves();
        output << calculator_10;
        break;
      case base16:
        calculator_16.SetClave(claves);
        calculator_16.ProcessClaves();
        output << calculator_16;
        break;
      default:
        std::cout << "Error" << std::endl;
        break;
    }
  } catch (const std::invalid_argument& i_a) {
    std::cerr << "Error: Argumento Invalido: " << i_a.what() << '\n';
  } catch (const std::out_of_range& o_r) {
    std::cerr << "Error: Fuera de rango: " << o_r.what() << '\n';
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  } catch (std::string& e) {
    std::cerr << "Error: " << e << '\n';
  }catch (...) {
    std::cerr << "Error: " << "Unknown error" << '\n';
  }

  return 0;
}