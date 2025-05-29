#pragma once
#include <vector>
#include "bank_operation.h"

int compareByPurpose(const BankOperation* a, const BankOperation* b) {
    return a->purpose.compare(b->purpose);
}

int compareByAccountTypeAmount(const BankOperation* a, const BankOperation* b) {
    if (a->account != b->account) {
        return a->account.compare(b->account);
    }
    if (a->type != b->type) {
        return a->type.compare(b->type);
    }
    return (a->amount < b->amount) ? -1 : (a->amount > b->amount) ? 1 : 0;
}

void selectionSort(std::vector<BankOperation*>& arr, int (*compare)(const BankOperation*, const BankOperation*)) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < arr.size(); ++j) {
            if (compare(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void quickSort(std::vector<BankOperation*>& arr, int (*compare)(const BankOperation*, const BankOperation*), int low, int high) {
    if (low < high) {
        BankOperation* pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (compare(arr[j], pivot) < 0) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int partitionIndex = i + 1;
        quickSort(arr, compare, low, partitionIndex - 1);
        quickSort(arr, compare, partitionIndex + 1, high);
    }
}
