#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<BankOperation> readOperations(const std::string& filename) {
    std::vector<BankOperation> operations;
    std::ifstream file(filename);

    // �������� ��������� �������� �����
    if (!file.is_open()) {
        std::cerr << "������: �� ������� ������� ���� " << filename << std::endl;
        return operations;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        BankOperation op;

        if (!(iss >> op.date >> op.time >> op.type >> op.account >> op.amount)) {
            std::cerr << "������ ������ ������: " << line << std::endl;
            continue;
        }

        std::getline(iss, op.purpose);
        op.purpose.erase(0, op.purpose.find_first_not_of(' '));

        operations.push_back(op);
    }

    file.close();
    std::cout << "����� ������� ��������: " << operations.size() << std::endl;
    return operations;
}
