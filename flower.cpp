#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 700;
const unsigned int SCR_HEIGHT = 700;

const float angle1 = 3.1415926/2.f;
const float angle2 = 3.1415926/6.f;
const float angle3 = -3.1415926/6.f;
const float angle4 = 3.1415926/4.f;


int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Cvet", nullptr, nullptr);
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

    float r1=1.0f;
    float r2=0.5f;

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        for(int i=1; i<=4; i++){

            float x1 = r1*cos(angle1*i);
            float y1 = r1*sin(angle1*i);

            float x2 = r2*cos(angle2 + (3.1415926/2)*i);
            float y2 = r2*sin(angle2 + (3.1415926/2)*i);

            float x3 = r2*cos(angle3 + (3.1415926/2)*i);
            float y3 = r2*sin(angle3 + (3.1415926/2)*i);

            glBegin(GL_TRIANGLES);
            glColor4f(1.0f, 0.5f, 0.2f, 1.0f);
            glVertex2f(0.0f, 0.0f);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);

            glVertex2f(0.0f, 0.0f);
            glVertex2f(x1, y1);
            glVertex2f(x3, y3);

            glEnd();
        }

        for(int i=1; i<=4; i++){
            float x1 = r1*cos(angle4 + (3.1415926/2)*i);
            float y1 = r1*sin(angle4 + (3.1415926/2)*i);

            float x2 = r2*cos(angle2 + (3.1415926/2)*i);
            float y2 = r2*sin(angle2 + (3.1415926/2)*i);

            float x3 = r2*cos(angle2 + (3.1415926/2)*i + 3.1415926/6);
            float y3 = r2*sin(angle2 + (3.1415926/2)*i + 3.1415926/6);

            glBegin(GL_LINES);
            glColor4f(1.0f, 0.5f, 0.2f, 1.0f);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);

            glVertex2f(x1, y1);
            glVertex2f(x3, y3);

            glEnd();
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