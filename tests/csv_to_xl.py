import subprocess
import sys

# Функция для установки библиотек
def install_package(package):
    try:
        subprocess.check_call([sys.executable, "-m", "pip", "install", package])
    except Exception as e:
        print(f"Не удалось установить {package}: {e}")

# Установка необходимых библиотек
install_package("pandas")
install_package("openpyxl")
import pandas as pd

def csv_to_excel(csv_file, excel_file):
    try:
        # Чтение CSV-файла
        df = pd.read_csv(csv_file)

        # Сохранение в формате Excel
        df.to_excel(excel_file, index=False)
        print(f"Данные успешно переведены из {csv_file} в {excel_file}")
    except Exception as e:
        print(f"Ошибка: {e}")

# Пример использования
csv_file = '../tests/performance_data.csv'
excel_file = '../tests/performance_data.xlsx'
csv_to_excel(csv_file, excel_file)
