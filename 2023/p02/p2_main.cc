#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "bigint.h"
#include "calculator.h"

// Leer fichero con esta entrada
// Meterlo en un vector de strings excepto el primer elemento
// Meter el primer elemento en un size_t

void PrintUsage(char* argv[]) {
  std::cerr << "Usage: " << argv[0] << " <entrada>" << "salida " << std::endl;
  std::cerr << "Formato:" << std::endl;
  std::cerr << "Base = 10" << std::endl;
  std::cerr << "N1 = xxxxx" << std::endl;
  std::cerr << "N2 = xxxxx" << std::endl;
  std::cerr << "E1 = N1 N2 +" << std::endl;
  exit(1);
}

int main(int argc, char* argv[]) {
  if (argc != 3 && argc != 2) {
    std::cerr << "Usa: " << argv[0] << " <entrada>" << "salida " << std::endl;
    std::cerr << "Usa: " << argv[0] << " -h | --help para mas informacion" << std::endl;
    return 1;
  } else if (argc == 2 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
    PrintUsage(argv);
  }
  std::ifstream file(argv[1]);
  if (!file.is_open()) {
    std::cerr << "Error opening file " << argv[1] << std::endl;
    return 1;
  }
  std::ofstream output(argv[2]);
  if (!output.is_open()) {
    std::cerr << "Error opening file " << argv[2] << std::endl;
    return 1;
  }
  std::string line;
  std::vector<std::vector<std::string>> tokens;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::vector<std::string> line_tokens;
    std::string token;
    while (iss >> token) {
      line_tokens.push_back(token);
    }
    tokens.push_back(line_tokens);
  }
  // La primera linea es el base
  // base = 10 asi accedemos a la primer vector la ultima posicion
  try {
    const size_t base = std::stoi(tokens[0][tokens[0].size() - 1]);
    // Se elimina la primera linea del vector
    tokens.erase(tokens.begin());
    Calculator<BigInt<2>, BigInt<2>> calculator2;
    Calculator<BigInt<2>, BigInt<8>> calculator8;
    Calculator<BigInt<2>, BigInt<10>> calculator10;
    Calculator<BigInt<2>, BigInt<16>> calculator16;
    enum bases { base2 = 2,
                 base8 = 8,
                 base10 = 10,
                 base16 = 16 };
    switch (base) {
      case base2:
        calculator2.SetTokens(tokens);
        calculator2.Process();
        output << calculator2;
        break;
      case base8:
        calculator8.SetTokens(tokens);
        calculator8.Process();
        output << calculator8;
        break;
      case base10:
        calculator10.SetTokens(tokens);
        calculator10.Process();
        output << calculator10;
        break;
      case base16:
        calculator16.SetTokens(tokens);
        calculator16.Process();
        output << calculator16;
        break;
      default:
        std::cout << "Error" << std::endl;
        break;
    }
  } catch (const std::invalid_argument& ia) {
    std::cerr << "Invalid argument: " << ia.what() << '\n';
  } catch (const std::out_of_range& oor) {
    std::cerr << "Out of Range error: " << oor.what() << '\n';
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  } catch (std::string& e) {
    std::cerr << "Error: " << e << '\n';
  } catch (...) {
    std::cerr << "Error: "
              << "Unknown error" << '\n';
  }

  return 0;
}