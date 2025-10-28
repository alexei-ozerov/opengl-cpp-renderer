// System headers
#include <GLFW/glfw3.h>
#include <cstdio>
#include <glad/glad.h>

// Standard headers
#include <cstdlib>
#include <string>

const int windowWidth = 1024;
const int windowHeight = 768;
const std::string windowTitle = "OpenGL";
const GLint windowResizable = GL_FALSE;
const int windowSamples = 4;

// A callback which allows GLFW to report errors whenever they occur
static void glfwErrorCallback(int error, const char *description) {
  fprintf(stderr, "GLFW returned an error:\n\t%s (%i)\n", description, error);
}

void drawTriangle() {
    printf("Trans Rights.\n");
}

void runProgram(GLFWwindow *window) {
  // Enable depth (Z) buffer (accept "closest" fragment)
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  // Configure miscellaneous OpenGL settings
  glEnable(GL_CULL_FACE);

  // Set default colour after clearing the colour buffer
  glClearColor(0.3f, 0.5f, 0.8f, 1.0f);

  // Set up your scene here (create Vertex Array Objects, etc.)

  // Rendering Loop
  while (!glfwWindowShouldClose(window)) {
    // Clear colour and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw your scene here
    drawTriangle();

    // Handle other events
    glfwPollEvents();
    // handleKeyboardInput(window);

    // Flip buffers
    glfwSwapBuffers(window);
  }
}

void handleKeyboardInput(GLFWwindow *window) {
  // Use escape key for terminating the GLFW window
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window, GL_TRUE);
  }
}

GLFWwindow *initialise() {
  // Initialise GLFW
  if (!glfwInit()) {
    fprintf(stderr, "Could not start GLFW\n");
    exit(EXIT_FAILURE);
  }

  // Set core window options (adjust version numbers if needed)
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // Enable the GLFW runtime error callback function defined previously.
  glfwSetErrorCallback(glfwErrorCallback);

  // Set additional window options
  glfwWindowHint(GLFW_RESIZABLE, windowResizable);
  glfwWindowHint(GLFW_SAMPLES, windowSamples); // MSAA

  // Create window using GLFW
  GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight,
                                        windowTitle.c_str(), nullptr, nullptr);

  // Ensure the window is set up correctly
  if (!window) {
    fprintf(stderr, "Could not open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Let the window be the current OpenGL context and initialise glad
  glfwMakeContextCurrent(window);
  gladLoadGL();

  // Print various OpenGL information to stdout
  printf("%s: %s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
  printf("GLFW\t %s\n", glfwGetVersionString());
  printf("OpenGL\t %s\n", glGetString(GL_VERSION));
  printf("GLSL\t %s\n\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

  return window;
}

int main(int argc, char *argb[]) {
  // Initialise window using GLFW
  GLFWwindow *window = initialise();

  // Run an OpenGL application using this window
  runProgram(window);

  // Terminate GLFW (no need to call glfwDestroyWindow)
  glfwTerminate();

  return EXIT_SUCCESS;
}
