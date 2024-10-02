import xml.etree.ElementTree as ET
import os
import glob

# Путь к директории с результатами тестов
results_dir = 'test_reports'
output_file = os.path.join(results_dir, 'junit_results.xml')

# Пространство имен
namespace = {'ns': 'http://check.sourceforge.net/ns'}

# Функция для конвертации XML в формат JUnit
def convert_to_junit(input_files, output_file):
    # Создание корневого элемента JUnit
    junit_root = ET.Element('testsuites')

    for input_file in input_files:
        tree = ET.parse(input_file)
        root = tree.getroot()

        # Извлечение названия сьюты
        suite_name = root.get('name', 'machina')  # Используйте значение атрибута name, если доступно

        # Создание элемента test suite
        testsuite = ET.SubElement(junit_root, 'testsuite')
        testsuite.set('name', suite_name)  # Устанавливаем название сьюты

        # Добавляем информацию о каждом тесте в JUnit формат
        for test in root.findall('.//ns:test', namespace):
            testcase = ET.SubElement(testsuite, 'testcase')

            # Установка атрибута classname
            classname = "MathClass"  # Укажите имя класса, в котором находятся тесты
            testcase.set('classname', classname)  # Устанавливаем имя класса

            # Получение уникального имени теста и времени выполнения
            test_id = test.find('ns:id', namespace).text
            duration = test.find('ns:duration', namespace).text
            
            testcase.set('name', test_id)  # Устанавливаем уникальное имя теста
            testcase.set('time', duration)  # Устанавливаем время выполнения теста

            # Проверка на успешность теста
            if test.get('result') == 'success':
                # Добавляем успешный тест
                ET.SubElement(testcase, 'system-out').text = test.find('ns:message', namespace).text
            else:
                # Добавляем неуспешный тест
                failure = ET.SubElement(testcase, 'failure')
                failure.set('message', 'Test failed')
                failure.text = test.find('ns:message', namespace).text

    # Сохранение нового файла в формате JUnit
    junit_tree = ET.ElementTree(junit_root)
    junit_tree.write(output_file, xml_declaration=True, encoding='utf-8')

# Получаем все файлы results*.xml
input_files = glob.glob(os.path.join(results_dir, 'results*.xml'))

# Вызов функции конвертации
convert_to_junit(input_files, output_file)
print(f'Файл успешно сконвертирован и сохранен как {output_file}')
