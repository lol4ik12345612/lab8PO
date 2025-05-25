#include <iostream>
#include "file_reader.h"
#include "bank_operation.h"
#include "constants.h"

using namespace std;

int main()
{
    cout << "Laboratory work #8. GIT\n";
    cout << "Variant #7. Bank operation\n";
    cout << "Author: Denis Proschenko\n\n";

    vector<BankOperation> operations;
    try
    {
        operations = readOperations("data.txt");

        for (const auto& op : operations)
        {
            cout << "Date: " << op.date << '\n';
            cout << "Time: " << op.time << '\n';
            cout << "Type: " << op.type << '\n';
            cout << "Account: " << op.account << '\n';
            cout << "Amount: " << op.amount << '\n';
            cout << "Purpose: " << op.purpose << '\n';
            cout << '\n';
        }
    }
    catch (const char* error)
    {
        cout << "Error: " << error << '\n';
    }

    return 0;
}
