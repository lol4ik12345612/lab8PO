#include <iostream>
#include <iomanip>
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
        cout << "***** Bank Operations *****\n\n";

        for (const auto& op : operations)
        {
            /********** ����� �������� **********/
            cout << "Transaction.....: ";
            cout << op.date << " " << op.time << '\n';

            /********** ��� �������� **********/
            cout << "Type............: ";
            cout << op.type << '\n';

            /********** ����� ����� **********/
            cout << "Account.........: ";
            cout << op.account << '\n';

            /********** ����� �������� **********/
            cout << "Amount..........: ";
            cout << fixed << setprecision(2) << op.amount << '\n';

            /********** ���������� **********/
            cout << "Purpose.........: ";
            cout << op.purpose << '\n';

            cout << '\n';
        }
    }
    catch (const char* error)
    {
        cout << "Error: " << error << '\n';
    }

    cout << "Author: Denis Proschenko\n";
    cout << "Group: 24ISIT\n";
    return 0;
}
