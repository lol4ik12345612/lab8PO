#include <iostream>
#include <vector>
#include <iomanip>
#include "bank_operation.h"
#include "file_reader.h"
#include "sorting.h"

void printOperations(const std::vector<BankOperation*>& ops) {
    if (ops.empty()) {
        std::cout << "��� ������ ��� ������!" << std::endl;
        return;
    }

    std::cout << std::left << std::setw(12) << "Date"
        << std::setw(10) << "Time"
        << std::setw(10) << "Type"
        << std::setw(15) << "Account"
        << std::setw(10) << "Amount"
        << "Purpose" << std::endl;
    std::cout << std::string(70, '-') << std::endl;

    for (const auto& op : ops) {
        std::cout << std::left << std::setw(12) << op->date
            << std::setw(10) << op->time
            << std::setw(10) << op->type
            << std::setw(15) << op->account
            << std::setw(10) << std::fixed << std::setprecision(2) << op->amount
            << op->purpose << std::endl;
    }
}

int main() {

    setlocale(LC_ALL, "RU");

    auto operations = readOperations("data.txt");

    if (operations.empty()) {
        std::cerr << "������: ���� data.txt ���� ��� �� ������� ��������� ������!" << std::endl;
        return 1;
    }

    std::vector<BankOperation*> opPtrs;
    for (auto& op : operations) {
        opPtrs.push_back(&op);
    }

    int choice;
    std::cout << "1. ������� ��� ��������� ��������\n"
        << "2. ������� �������� �� ������ 2021\n"
        << "3. ����������� ������\n"
        << "�������� ��������: ";
    std::cin >> choice;

    std::vector<BankOperation> filtered;
    switch (choice) {
    case 1:
        filtered = filterIncome(operations);
        break;
    case 2:
        filtered = filterNovember2021(operations);
        break;
    case 3: {
        int sortMethod, sortCriteria;
        std::cout << "1. ���������� �������\n2. ������� ����������\n�������� �����: ";
        std::cin >> sortMethod;
        std::cout << "1. �� ����������\n2. �� �����/����/�����\n�������� ��������: ";
        std::cin >> sortCriteria;

        auto compare = (sortCriteria == 1) ? compareByPurpose : compareByAccountTypeAmount;
        if (sortMethod == 1) {
            selectionSort(opPtrs, compare);
        }
        else {
            quickSort(opPtrs, compare, 0, opPtrs.size() - 1);
        }
        printOperations(opPtrs);
        return 0;
    }
    default:
        std::cerr << "������ ������!" << std::endl;
        return 1;
    }

    if (filtered.empty()) {
        std::cout << "��� ���������� ��������!" << std::endl;
    }
    else {
        for (const auto& op : filtered) {
            std::cout << op.date << " " << op.time << " " << op.type << " "
                << op.account << " " << op.amount << " " << op.purpose << std::endl;
        }
    }

    return 0;
}
