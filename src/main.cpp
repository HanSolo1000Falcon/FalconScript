#include <fstream>
#include <iostream>
#include <sstream>

#include "scanner.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Invalid amount of parameters passed, usage: FalconScript <file-path>\n";
        return 1;
    }

    std::ifstream ifs(argv[1]);

    if (!ifs.is_open()) {
        std::cerr << "Error opening file: " << argv[1] << '\n';
        return 1;
    }

    std::ostringstream buf;
    buf << ifs.rdbuf();
    std::string complete = buf.str();

    ifs.close();

    for (const auto tokens = scanner::tokenize(complete); const auto& token : tokens) {
        std::cout << token.lexeme << ' ' << token.type << '\n';
    }

    return 0;
}
