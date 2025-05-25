#pragma once
#include <string>

struct BankOperation {
    std::string date;       // формат: дд.мм.гг
    std::string time;       // формат: чч:мм:сс
    std::string type;       // "приход" или "расход"
    std::string account;    // номер счёта
    double amount;          // сумма
    std::string purpose;    // назначение платежа
};
