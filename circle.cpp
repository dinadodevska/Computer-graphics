#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 650;
const unsigned int SCR_HEIGHT = 600;

const float steps = 100;
const float angle = 3.1415926 * 2.f/steps;

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
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

    float x=0.0f;
    float y=0.0f;
    float r=0.7f;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float x1 = x;
        float y1 = y;

        for(int i=0; i<=steps; i++){
            float x2 = r * sin(angle*i);
            float y2 = -r * cos(angle*i);

            glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 1.0f, 1.0f);
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(x1, y1, 0.0f);
            glVertex3f(x2, y2, 0.0f);

            glEnd();

            x1 = x2;
            y1 = y2;
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