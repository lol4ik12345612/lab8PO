#pragma once
#include <string>
#include <vector>

struct BankOperation {
    std::string date;       // формат: дд.мм.гг
    std::string time;       // формат: чч:мм:сс
    std::string type;       // "приход" или "расход"
    std::string account;    // номер счёта
    double amount;          // сумма
    std::string purpose;    // назначение платежа
};

// Фильтр 1: все приходные операции
std::vector<BankOperation> filterIncome(const std::vector<BankOperation>& ops) {
    std::vector<BankOperation> result;
    for (const auto& op : ops) {
        if (op.type == "приход") {
            result.push_back(op);
        }
    }
    return result;
}

// Фильтр 2: операции за ноябрь 2021
std::vector<BankOperation> filterNovember2021(const std::vector<BankOperation>& ops) {
    std::vector<BankOperation> result;
    for (const auto& op : ops) {
        if (op.date.substr(3, 5) == "11.21") { // формат дд.мм.гг → мм.гг
            result.push_back(op);
        }
    }
    return result;
}
