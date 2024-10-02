#include "all_tests_s21.h"
#include <stdio.h>

void make_the_test(Suite *test_to_run, int *tests_counter) {
    // Печатаем информацию о текущем тесте
    if (*tests_counter > 1) printf("\n");
    printf("%s%d%s", "Идет тест: ", *tests_counter, "\n");
    (*tests_counter)++;

    SRunner *sr = srunner_create(test_to_run);
    
    // Создаем уникальное имя файла XML для отчетов
    char xml_filename[256];
    snprintf(xml_filename, sizeof(xml_filename), "test_reports/results_%d.xml", *tests_counter);

    // Устанавливаем файл XML для отчетов
    srunner_set_xml(sr, xml_filename);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    
    // Освобождаем ресурсы после завершения тестов
    srunner_free(sr);
}

int main(void) {
    // Здесь создан массив со всеми тестируемыми функциями
    Suite *list_cases[] = {
        s21_abs_suite(), s21_fmod_suite(), s21_ceil_suite(), s21_floor_suite(),
        s21_sin_suite(), s21_cos_suite(), s21_asin_suite(), s21_acos_suite(),
        s21_tan_suite(), s21_atan_suite(), s21_exp_suite(), s21_log_suite(),
        s21_pow_suite(), s21_sqrt_suite(), s21_fabs_suite(), NULL
    };
    
    int tests_counter = 0; // Инициализируем счетчик тестов
    // В цикле прогоняем тест-кейсы для всех функций
    for (Suite **i = list_cases; *i != NULL; i++) {
        make_the_test(*i, &tests_counter);
    }
    
    return 0;
}
