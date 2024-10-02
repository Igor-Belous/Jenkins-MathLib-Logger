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
                    sh 'cat test_reports/results.xml' // Вывод содержимого файла отчета      
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
