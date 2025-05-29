#include "bank_operation.h"

std::vector<BankOperation> filterIncome(const std::vector<BankOperation>& ops) {
    std::vector<BankOperation> result;
    for (const auto& op : ops) {
        if (op.type == "income") {
            result.push_back(op);
        }
    }
    return result;
}

std::vector<BankOperation> filterNovember2021(const std::vector<BankOperation>& ops) {  
    std::vector<BankOperation> result;
    for (const auto& op : ops) {
        size_t dot1 = op.date.find('.');
        size_t dot2 = op.date.rfind('.');

        if (dot1 != std::string::npos && dot2 != std::string::npos && dot1 != dot2) {
            std::string month = op.date.substr(dot1 + 1, dot2 - dot1 - 1);
            std::string year = op.date.substr(dot2 + 1);

            if (month == "11" && year == "2021") {
                result.push_back(op);  //agdsdsfg
            }
        }
    }
    return result;
}
