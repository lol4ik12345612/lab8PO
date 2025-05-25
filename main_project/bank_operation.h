#pragma once
#include <string>

struct BankOperation {
    std::string date;       // ������: ��.��.��
    std::string time;       // ������: ��:��:��
    std::string type;       // "������" ��� "������"
    std::string account;    // ����� �����
    double amount;          // �����
    std::string purpose;    // ���������� �������
};
