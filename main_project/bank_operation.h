#pragma once
#include <string>
#include <vector>

struct BankOperation {
    std::string date;
    std::string time;
    std::string type;
    std::string account;
    double amount;
    std::string purpose;
};

std::vector<BankOperation> filterIncome(const std::vector<BankOperation>& ops);
std::vector<BankOperation> filterNovember2021(const std::vector<BankOperation>& ops);
