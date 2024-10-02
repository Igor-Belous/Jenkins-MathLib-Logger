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
                }
            }
        }
    }
    post {
        always {
            // Отчет JUnit
            junit 'src/test_reports/*.xml'
        }
    }
}