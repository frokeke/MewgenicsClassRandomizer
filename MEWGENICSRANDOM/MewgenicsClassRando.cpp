#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <map>

unsigned SEED = time(0);

int main() {
    srand(SEED);

    std::vector<std::string> nomeClasses{
        "Butcher", 
        "Cleric", 
        "Druid", 
        "Fighter",
        "Mage", 
        "Monk", 
        "Psyquic", 
        "Tinkerer"
    };

    std::string classeEscolhida = nomeClasses[rand() % nomeClasses.size()];
    std::cout << "Classe: " << classeEscolhida << std::endl;

    std::map<std::string, int> contadorClasses;

    std::ifstream arquivoEntrada("contadorClasses.sav");

    if (arquivoEntrada.is_open()) {
        std::string linha;

        while (std::getline(arquivoEntrada, linha)) {
            size_t pos = linha.find(":");
            if (pos != std::string::npos) {
                std::string nome = linha.substr(0, pos);
                int valor = std::stoi(linha.substr(pos + 2));
                contadorClasses[nome] = valor;
            }
        }
        arquivoEntrada.close();
    }

    contadorClasses[classeEscolhida]++;

    std::ofstream arquivoSaida("contadorClasses.sav");

    for (const auto& par : contadorClasses) {
        arquivoSaida << par.first << ": " << par.second << std::endl;
    }

    arquivoSaida.close();

    system("pause");
    system("cls");

    return 0;
}