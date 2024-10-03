pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                dir('src') {
                    sh 'make s21_math.a'  // Сборка библиотеки
                }
            }
        }

        stage('Test') {
            steps {
                dir('src') {
                    sh 'make test'  // Запуск тестов, которые создают results.xml в test_reports
                }
            }
        }

        stage('Publish Test Results') {
            steps {
                dir('src') {
                    junit 'test_reports/junit_results.xml' 
                }
            }
        }
    }

    post {
        always {
            dir('src') {
                sh 'make clean'  // Очистка
            }
        }
    }
}
