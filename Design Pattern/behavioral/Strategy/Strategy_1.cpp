/*
The Strategy Design Pattern is useful when we have multiple algorithms for a specific task and we want our application
to be flexible to choose any of the algorithms at runtime for that task. It allows us to define a family of algorithms,
encapsulate each one as an object, and make them interchangeable. This pattern provides a way to delegate the implementation
of an algorithm to different classes, which can be selected at runtime based on the context in which they are used. The
Strategy pattern is particularly useful when you begin to notice recurring algorithms but in different variations. By separating
the algorithm from the client code, it makes it easier to maintain and extend the codebase over time.

Here are some reasons why you might want to use the Strategy design pattern:

1. Encapsulation of algorithms: The Strategy design pattern allows you to encapsulate each algorithm or behavior into its own class,
making it easier to manage and modify each one independently.

2. Flexibility and modifiability: The Strategy pattern allows you to switch between different algorithms or behaviors at runtime,
which makes the code more flexible and easier to modify.

3. Separation of concerns: The Strategy pattern separates the algorithm or behavior implementation from the client code that uses it.
This separation allows the client code to focus on its own responsibilities, without having to worry about the implementation details of the algorithm.

4. Testability: The Strategy pattern makes it easier to test different algorithms or behaviors independently, since each one is encapsulated in its own class.

5. Reusability: The Strategy pattern enables the reuse of algorithms or behaviors across different contexts and applications, which can save time and effort
in software development.

Overall, the Strategy pattern can help you write more maintainable, flexible, and reusable code, by separating concerns and encapsulating algorithm implementations.

*/



#include <iostream>

class SortStrategy {
public:
    virtual void sort(int* arr, int size) = 0;
};

class BubbleSort : public SortStrategy {
public:
    void sort(int* arr, int size) {
        // Implementation of bubble sort algorithm
        std::cout << "Sorting using bubble sort." << std::endl;
    }
};

class MergeSort : public SortStrategy {
public:
    void sort(int* arr, int size) {
        // Implementation of merge sort algorithm
        std::cout << "Sorting using merge sort." << std::endl;
    }
};

class Sorter {
public:
    Sorter(SortStrategy* strategy) : m_strategy(strategy) {}

    void sort(int* arr, int size) {
        m_strategy->sort(arr, size);
    }

private:
    SortStrategy* m_strategy;
};

int main() {
    int arr[] = {5, 3, 8, 1, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort bubbleSort;
    MergeSort mergeSort;

    Sorter sorter(&bubbleSort);
    sorter.sort(arr, size);

    sorter = Sorter(&mergeSort);
    sorter.sort(arr, size);

    return 0;
}
