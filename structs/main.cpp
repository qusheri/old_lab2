// #include <QApplication>
// #include <QMainWindow>
// #include <QMenuBar>
// #include <QPushButton>
// #include <QVBoxLayout>
// #include <QTextEdit>
// #include <QComboBox>
// #include <QLabel>
// #include <QInputDialog>
// #include <QMessageBox>
// #include <vector>
// #include <chrono>
// #include <random>
// #include <algorithm>
// #include <functional>
#include "../tests/structures_tests.h"
#include "iostream"

// // Пример реализации быстрой сортировки
// template<typename T>
// void QuickSort(std::vector<T>& sequence, std::function<bool(T, T)> compare) {
//     std::sort(sequence.begin(), sequence.end(), compare);
// }

// // Пример функции для замера времени выполнения
// template<typename Func>
// double measureExecutionTime(Func func) {
//     auto start = std::chrono::high_resolution_clock::now();
//     func();
//     auto end = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double> duration = end - start;
//     return duration.count();
// }

// // Генерация случайных чисел
// std::vector<int> generateRandomSequence(int size) {
//     std::vector<int> sequence(size);
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 10000);
//     std::generate(sequence.begin(), sequence.end(), [&]() { return dis(gen); });
//     return sequence;
// }

// class MainWindow : public QMainWindow {
// Q_OBJECT
// public:
//     MainWindow() {
//         setWindowTitle("Sorting Algorithms");
//         resize(400, 300);

//         QWidget *widget = new QWidget(this);
//         setCentralWidget(widget);

//         QVBoxLayout *layout = new QVBoxLayout(widget);

//         // Комбобокс для выбора алгоритма сортировки
//         QLabel *sortLabel = new QLabel("Choose Sorting Algorithm:", this);
//         layout->addWidget(sortLabel);

//         QComboBox *algorithmComboBox = new QComboBox(this);
//         algorithmComboBox->addItem("QuickSort");
//         algorithmComboBox->addItem("MergeSort");
//         algorithmComboBox->addItem("BubbleSort");
//         layout->addWidget(algorithmComboBox);

//         // Комбобокс для выбора порядка сортировки
//         QLabel *orderLabel = new QLabel("Choose Order:", this);
//         layout->addWidget(orderLabel);

//         QComboBox *orderComboBox = new QComboBox(this);
//         orderComboBox->addItem("Ascending");
//         orderComboBox->addItem("Descending");
//         layout->addWidget(orderComboBox);

//         // Кнопка для генерации последовательности
//         QPushButton *generateButton = new QPushButton("Generate Random Sequence", this);
//         layout->addWidget(generateButton);

//         // Поле для вывода исходной и отсортированной последовательностей
//         QTextEdit *outputTextEdit = new QTextEdit(this);
//         outputTextEdit->setReadOnly(true);
//         layout->addWidget(outputTextEdit);

//         // Кнопка для запуска сортировки
//         QPushButton *sortButton = new QPushButton("Sort", this);
//         layout->addWidget(sortButton);

//         // Кнопка для замера времени
//         QPushButton *compareButton = new QPushButton("Compare Algorithms", this);
//         layout->addWidget(compareButton);

//         connect(generateButton, &QPushButton::clicked, [=]() {
//             bool ok;
//             int size = QInputDialog::getInt(this, "Input Size", "Enter the size of the sequence:", 100, 10, 10000, 1, &ok);
//             if (ok) {
//                 sequence = generateRandomSequence(size);
//                 outputTextEdit->setText("Generated Sequence:\n" + sequenceToString(sequence));
//             }
//         });

//         connect(sortButton, &QPushButton::clicked, [=]() {
//             if (sequence.empty()) {
//                 QMessageBox::warning(this, "Warning", "Please generate a sequence first.");
//                 return;
//             }

//             std::function<bool(int, int)> compare;
//             if (orderComboBox->currentText() == "Ascending") {
//                 compare = std::less<int>();
//             } else {
//                 compare = std::greater<int>();
//             }

//             QString algorithm = algorithmComboBox->currentText();
//             double duration = 0.0;

//             if (algorithm == "QuickSort") {
//                 duration = measureExecutionTime([&]() { QuickSort(sequence, compare); });
//             } else if (algorithm == "MergeSort") {
//                 // Вставьте реализацию MergeSort
//             } else if (algorithm == "BubbleSort") {
//                 // Вставьте реализацию BubbleSort
//             }

//             outputTextEdit->append("\nSorted Sequence:\n" + sequenceToString(sequence));
//             outputTextEdit->append("\nExecution Time: " + QString::number(duration) + " seconds");
//         });

//         connect(compareButton, &QPushButton::clicked, [=]() {
//             if (sequence.empty()) {
//                 QMessageBox::warning(this, "Warning", "Please generate a sequence first.");
//                 return;
//             }
//             // Вставьте код для сравнения времени работы алгоритмов
//         });
//     }

// private:
//     std::vector<int> sequence;

//     QString sequenceToString(const std::vector<int>& seq) {
//         QString result;
//         for (int num : seq) {
//             result += QString::number(num) + " ";
//         }
//         return result;
//     }
// };

int main(int argc, char *argv[]) {
    // QApplication app(argc, argv);

    // MainWindow window;
    // window.show();

    // return app.exec();
    std::cout << runLinkedListTests();

    std::cout << runDynamicArrayTests();

    std::cout << runListSequenceTests();

    std::cout << runArraySequenceTests();
}

