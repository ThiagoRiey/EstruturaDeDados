#include <iostream>
#include <vector>

std::vector<int> fibonacci(int n) {
    std::vector<int> fib_sequence;
    int a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        fib_sequence.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }
    return fib_sequence;
}

int main() {
    int n = 10;  // número de termos desejados
    std::vector<int> fib_sequence = fibonacci(n);
    
    std::cout << "Sequência de Fibonacci: ";
    for (int num : fib_sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
