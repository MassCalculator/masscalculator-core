pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }
        stage('Environment setup') {
            steps {
                sh "sudo tools/installers/essentials.sh"
            }
        }
        stage('Build') {
            parallel {
                stage('Debug') {
                    steps {
                        sh "cmake -B build/masscalculator-core-Debug -DCMAKE_BUILD_TYPE=Debug"
                        sh "cmake --build build/masscalculator-core-Debug --config Debug"
                    }
                }
                stage('Release') {
                    steps {
                        sh "cmake -B build/masscalculator-core-Release -DCMAKE_BUILD_TYPE=Release"
                        sh "cmake --build build/masscalculator-core-Release --config Release"
                    }
                }
            }
        }
        stage('Test') {
            parallel {
                stage('Debug') {
                    steps {
                        dir('build/masscalculator-core-Debug') {
                            sh 'ctest -C Debug'
                        }
                    }
                }
                stage('Release') {
                    steps {
                        dir('build/masscalculator-core-Release') {
                            sh 'ctest -C Release'
                        }
                    }
                }
            }
        }
        stage('Package') {
            steps {
                echo 'Package stage is in progress'
            }
        }
        stage('Deploy') {
            steps {
                echo 'Deploy stage is in progress'
            }
        }
    }
}
