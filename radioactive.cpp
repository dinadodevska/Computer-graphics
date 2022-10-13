#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 600;


const float steps = 80;
const float angle = 3.1415926*2.f/steps;

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    float m=0;
    float n=0;
    float r=0.2f;
    float r1=0.4f;
    float r2=1.0f;

    while (!glfwWindowShouldClose(window))
    {


        processInput(window);
        glClearColor(0.91f, 0.745f,  0.157f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float previous_M = m;
        float previous_N = n;

        for(int i=0; i<=steps; i++){
            float m2 = r * sin(angle*i);
            float n2 = -r * cos(angle*i);

            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(previous_M, previous_N, 0.0f);
            glVertex3f(m2, n2, 0.0f);

            glEnd();

            previous_M = m2;
            previous_N = n2;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}