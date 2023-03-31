pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                checkout scm
                script {
                    REPO_NAME = env.JOB_NAME.split('/')[0]
                }
                echo "Repository name: ${REPO_NAME}"
                sh "ls -la"
            }
        }
        stage('Environment setup') {
            steps {
                sh "ls -la"
                sh ". ${REPO_NAME}/tools/envsetup.sh"
                sh 'mkdir -p build/MassCalculatorCore-Debug'
                sh 'mkdir -p build/MassCalculatorCore-Release'
            }
        }
        stage('Build') {
            parallel {
                stage('Debug') {
                    steps {
                        dir('build/MassCalculatorCore-Debug') {
                            sh "cmake -DBUILD_TESTS=ON $MASSCALCULATOR_SOURCE"
                            sh "cmake --build ."
                        }
                    }
                }
                stage('Release') {
                    steps {
                        dir('build/MassCalculatorCore-Release') {
                            sh "cmake -DBUILD_RELEASE=ON -DBUILD_TESTS=ON $MASSCALCULATOR_SOURCE"
                            sh "cmake --build ."
                        }
                    }
                }
            }
        }
        stage('Test') {
            parallel {
                stage('Debug') {
                    steps {
                        dir('build/MassCalculatorCore-Debug') {
                            sh 'ctest'
                        }
                    }
                }
                stage('Release') {
                    steps {
                        dir('build/MassCalculatorCore-Release') {
                            sh 'ctest'
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
