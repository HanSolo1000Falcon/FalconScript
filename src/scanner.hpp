//
// Created by falcon1k on 3/28/26.
//

#ifndef FALCON_SCRIPT_SCANNER_HPP
#define FALCON_SCRIPT_SCANNER_HPP
#include <string>
#include <vector>

#include "token-type.hpp"
#include "token.hpp"

namespace scanner {
    inline std::vector<Token> tokenize(const std::string &str) {
        std::vector<Token> tokens;

        if (str.empty()) {
            return tokens;
        }

        int current = 0;

        while (current < str.length()) {
            switch (char c = str[current]) {
                default:
                    if (std::isdigit(c)) {
                        auto tempCurrent = current;
                        while (std::isdigit(str[tempCurrent])) {
                            ++tempCurrent;
                        }

                        if (str[tempCurrent] == '.' && std::isdigit(str[tempCurrent + 1])) {
                            ++tempCurrent;

                            while (std::isdigit(str[tempCurrent])) {
                                ++tempCurrent;
                            }
                        }

                        tokens.emplace_back(NUMBER, str.substr(current, tempCurrent - current),
                                                  std::stod(str.substr(current, tempCurrent - current)));
                        current = tempCurrent;
                    } else if (std::isalpha(str[current])) {
                        auto tempCurrent = current;
                        while (std::isalnum(str[tempCurrent])) {
                            ++tempCurrent;
                        }

                        tokens.emplace_back(IDENTIFIER, str.substr(current, tempCurrent - current), nullptr);
                        current = tempCurrent;
                    } else {
                        ++current;
                    }
            }
        }

        return tokens;
    }
}

#endif //FALCON_SCRIPT_SCANNER_HPP
