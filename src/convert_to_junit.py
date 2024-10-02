import xml.etree.ElementTree as ET
import os

# Определение пути к файлу results.xml
file_path = os.path.join('test_reports', 'results.xml')

# Открытие и парсинг исходного results.xml
tree = ET.parse(file_path)
root = tree.getroot()

# Создание нового дерева JUnit-совместимого XML
testsuites = ET.Element('testsuites')
testsuite = ET.SubElement(testsuites, 'testsuite', name='s21_fabs', tests='0', failures='0', errors='0', skipped='0')

# Обработка каждого теста в исходном XML
test_count = 0
failure_count = 0

for test in root.findall('.//test'):
    test_count += 1
    test_id = test.find('id').text
    description = test.find('description').text
    result = test.get('result')
    
    # Создание элемента testcase
    test_element = ET.SubElement(testsuite, 'testcase', classname='s21_fabs', name=test_id)
    
    # Проверка результата теста и добавление failure, если необходимо
    if result != 'success':
        failure = ET.SubElement(test_element, 'failure', message='Test failed')
        failure.text = f'Test {description} failed'

# Обновляем атрибуты testsuite
testsuite.set('tests', str(test_count))
testsuite.set('failures', str(failure_count))
# Можно добавить ошибки и пропуски, если они есть

# Определение пути для сохранения JUnit XML
output_path = os.path.join('test_reports', 'junit_results.xml')

# Сохранение нового JUnit XML
tree = ET.ElementTree(testsuites)
tree.write(output_path, encoding='utf-8', xml_declaration=True)

print(f"JUnit-совместимый отчет сохранен в: {output_path}")
