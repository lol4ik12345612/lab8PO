#include "file_reader.h"
#include <fstream>
#include <sstream>

std::vector<BankOperation> readOperations(const std::string& filename) {
    std::vector<BankOperation> operations;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        BankOperation op;

        iss >> op.date >> op.time >> op.type >> op.account >> op.amount;
        std::getline(iss, op.purpose); // назначение может содержать пробелы

        // Удаляем лишние пробелы в начале назначения
        op.purpose.erase(0, op.purpose.find_first_not_of(' '));
        operations.push_back(op);
    }

    return operations;
}
