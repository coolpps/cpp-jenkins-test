pipeline{
    agent {
        docker {image "ubuntu:24.04"}
    }

    environment {
        BUILD_DIR = "build"
        EXECUTABLE_NAME = "cpp-jenkins-test"
        TESTCASE_EXECUTABLE_NAME = "test-cpp-jenkins"
    }

    stages {
        stage("setup environment") {
            steps {
                sh '''
                    apt-get update
                    apt-get install -y cmake build-essential
                '''
            }
        }

        stage("configure") {
            steps{
                sh "mkdir -p ${env.BUILD_DIR}"
                sh "cmake -S . -B ${env.BUILD_DIR} -DCMAKE_BUILD_TYPE=Release"
            }
        }


        stage("build") {
            steps{
                sh "cmake --build ${env.BUILD_DIR}"
            }
        }

        stage("test") {
            steps{
                script {
                    def executable_path = "${env.BUILD_DIR}/test/${env.TESTCASE_EXECUTABLE_NAME}"
                    sh "chmod +x ${executable_path}"
                    sh "${executable_path}"
                }
            }
        }
    }


    post
    {
        success { echo "Pipeline succeeded!" }
        failure { echo "Pipeline failed!" }
        always
        {
            echo "Pipeline finished."
            cleanWs()
        }
    }

}