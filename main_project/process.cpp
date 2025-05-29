#include "processing.h"
#include "bank_operation.h"

double process(BankOperation* operations[], int size) {
    double balance = 0.0;

    for (int i = 0; i < size; i++) {
        if (operations[i]->type == "income") {
            balance += operations[i]->amount; // Пополнение счёта
        }
        else if (operations[i]->type == "expense") {
            balance -= operations[i]->amount; // Снятие со счёта
        }
    }

    return balance; 
}
