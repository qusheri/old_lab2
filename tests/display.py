import pandas as pd
import matplotlib.pyplot as plt

# Чтение CSV-файла
csv_file = '../tests/performance_data.csv'
df = pd.read_csv(csv_file)

# Проверка структуры данных
if df.empty:
    print("Файл пустой. Графики построить невозможно.")
else:
    # Убираем пробелы из заголовков (если есть)
    df.columns = [col.strip() for col in df.columns]

    # Построение графиков для каждой сортировки
    for index, row in df.iterrows():
        test_name = row['Test Name']
        run_times = row[1:].values  # Значения времени выполнения

        # Построение линейного графика
        plt.plot(range(1, len(run_times) + 1), run_times, marker='o', label=test_name)

    # Настройки графика
    plt.title("Сравнение производительности сортировок")
    plt.xlabel("Запуск (Run)")
    plt.ylabel("Время выполнения (секунды)")
    plt.yscale('log')  # Логарифмическая шкала для удобства
    plt.legend()
    plt.grid(True)
    plt.show()
