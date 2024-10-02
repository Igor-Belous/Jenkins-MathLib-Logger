pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                dir('src') {
                    sh 'make s21_math.a'
                }
            }
        }

        stage('Test') {
            steps {
                dir('src') {
                    sh 'make test'
                    sh 'ls -l test_reports' // Проверка наличия файла отчета
                }
            }
        }
    }
    post {
        always {
            junit 'src/test_reports/results.xml'
        }
    }
}
