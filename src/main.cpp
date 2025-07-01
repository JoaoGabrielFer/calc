#include <iostream>
#include <string>
#include <clocale>
#include <vector>
#include <fstream>

#include "include/lexer.h"

int main(int argc, char* argv[]){
    std::setlocale(LC_ALL, ".UTF8");
    if (argc < 2){
	std::cerr << "Insira um argumento." << std::endl << std::endl;
	std::cerr << "Uso correto: " << argv[0] << " <flag> <arquivo ou expressão>" << std::endl;
	return 0;
    }
    if (argv[1][0] == '/'){
	if (std::string(argv[1]) == "/f"){ 
	    if (argc < 3){
		std::cerr << "Insira um arquivo." << std::endl;
		std::cerr << "Uso correto: " << argv[0] << " /f <arquivo>" << std::endl;
	    } else{
		std::ifstream Arquivo(argv[2]);
		std::string line;
		std::string fileString;
		while (getline(Arquivo, line)) {
		    fileString += line + ";";
		}
		Lexer lexer(fileString);
		std::vector<Token> tokens = lexer.getTokens();
		for (Token tk : tokens){
		    std::cout << tk.type << " ";
		}
		Arquivo.close();
	    } 
	} else if (std::string(argv[1]) == "/e"){
	    if (argc < 3){
		std::cerr << "insira uma expressão." << std::endl;
		std::cerr << "uso correto: " << argv[0] << " /e <expressão>" << std::endl;
	    } else{
		std::string fileString = argv[2];
		Lexer lexer(fileString);
		std::vector<Token> tokens = lexer.getTokens();
		for (Token tk : tokens){
		    std::cout << tk.type << " ";
		}
	    }
	} else {
		std::cerr << "insira uma flag válida" << std::endl;
	    }
    } else {
	std::cerr << "Insira um argumento." << std::endl << std::endl;
	std::cerr << "Uso correto: " << argv[0] << " <flag> <arquivo ou expressão>" << std::endl;
	return 0;
    }
}

