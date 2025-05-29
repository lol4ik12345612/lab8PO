#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Денисиус\git\lab8PO\main_project\bank_operation.h"
#include "C:\Users\Денисиус\git\lab8PO\main_project\processing.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    
    BankOperation* build_operation(const std::string& type, const std::string& account, double amount)
    {
        BankOperation* operation = new BankOperation;
        operation->type = type;
        operation->account = account;
        operation->amount = amount;
        return operation;
    }

    
    void delete_operations(BankOperation* array[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            delete array[i];
        }
    }

    TEST_CLASS(unittestproject)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "123456", 1000.00);
            operations[1] = build_operation("expense", "123456", 400.00);
            operations[2] = build_operation("income", "123456", 600.00);

            Assert::AreEqual(1200.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod2)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "654321", 2500.00);
            operations[1] = build_operation("expense", "654321", 500.00);
            operations[2] = build_operation("expense", "654321", 1500.00);

            Assert::AreEqual(500.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod3)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "111111", 500.00);
            operations[1] = build_operation("expense", "111111", 700.00);
            operations[2] = build_operation("income", "111111", 200.00);

            Assert::AreEqual(0.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod4)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "222222", 3000.00);
            operations[1] = build_operation("expense", "222222", 2000.00);
            operations[2] = build_operation("expense", "222222", 500.00);

            Assert::AreEqual(500.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod5)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("expense", "333333", 1000.00);
            operations[1] = build_operation("expense", "333333", 500.00);
            operations[2] = build_operation("income", "333333", 2000.00);

            Assert::AreEqual(500.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod6)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "444444", 5000.00);
            operations[1] = build_operation("expense", "444444", 4500.00);
            operations[2] = build_operation("income", "444444", 1000.00);

            Assert::AreEqual(1500.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod7)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("expense", "555555", 200.00);
            operations[1] = build_operation("income", "555555", 300.00);
            operations[2] = build_operation("expense", "555555", 100.00);

            Assert::AreEqual(0.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod8)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "666666", 500.00);
            operations[1] = build_operation("expense", "666666", 600.00);
            operations[2] = build_operation("income", "666666", 100.00);

            Assert::AreEqual(0.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }

        TEST_METHOD(TestMethod9)
        {
            BankOperation* operations[3];
            operations[0] = build_operation("income", "777777", 1000.00);
            operations[1] = build_operation("expense", "777777", 750.00);
            operations[2] = build_operation("income", "777777", 500.00);

            Assert::AreEqual(750.00, process(operations, 3), 0.01);
            delete_operations(operations, 3);
        }
    };
}
