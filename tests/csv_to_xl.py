import subprocess
import sys

def install_package(package):
    try:
        subprocess.check_call([sys.executable, "-m", "pip", "install", package])
    except Exception as e:
        print(f"Не удалось установить {package}: {e}")

install_package("pandas")
install_package("openpyxl")
import pandas as pd

def csv_to_excel(csv_file, excel_file):
    try:
        df = pd.read_csv(csv_file)

        df.to_excel(excel_file, index=False)
        print(f"Данные успешно переведены из {csv_file} в {excel_file}")
    except Exception as e:
        print(f"Ошибка: {e}")

csv_file = '../tests/performance_data.csv'
excel_file = '../tests/performance_data.xlsx'
csv_to_excel(csv_file, excel_file)
