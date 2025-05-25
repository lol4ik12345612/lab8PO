#pragma once
#include <vector>
#include "bank_operation.h"

std::vector<BankOperation> readOperations(const std::string& filename);
