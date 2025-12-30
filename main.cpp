#include "functions.h"
#include "Circle.h"
#include "Renderer.h"
#include<thread>

int main() {
     std::vector<BaseLayer*> layers;
    Circle* c1=new Circle(10, 10, 5); // Add a circle
    Circle *c2=new Circle(30, 10, 8); // Add another on top

    Renderer r;

      for (double t = 0.0; t <= 1.0; t += 0.05) {
        std::cout << "\033[H";
    // 1. Calculate the "bent" time using your easing library
    double easedT = Interpolators::easeOutQuad(t);

    // 2. Calculate the new position
    double newX = Interpolators::lerp(0, 50, easedT);
    c1->setX(newX);

    // 3. Render the frame
    std::cout << "\033[H"; // Reset cursor
    r.render(60,20, layers);

    // 4. Slow it down so you can see it
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
      }
    for (auto l : layers) delete l;

    return 0;
}
