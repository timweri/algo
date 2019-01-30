// Given the following structs of Rectangle and Circle

#include <math.h>
#include <utility>

using namespace std;

struct Rect {
  float left, right, top, bottom;
};

struct Circle {
  float x, y, radius;
};

// Write 3 functions that return true if
//      - 2 Rects overlap
//      - 2 Circles overlap
//      - A Circle and a Rect overlap

bool overlap(const Rect &f1, const Rect &f2) {
  bool x_overlap = !((f1.right <= f2.left) || (f1.left >= f2.right));
  bool y_overlap = !((f1.top <= f2.bottom) || (f1.bottom >= f2.top));
  return x_overlap && y_overlap;
}

bool overlap(const Circle &f1, const Circle &f2) {
  float d = sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y));
  return d < f1.radius + f2.radius;
}

bool overlap(const Rect &f1, const Circle &f2) {
  // Get the four corners of the Rect
  pair<float, float> corners[] = {{f1.left, f1.top},
                                  {f1.left, f1.bottom},
                                  {f1.right, f1.top},
                                  {f1.right, f1.bottom}};
  // Check if the corners lies in the circle
  for (auto &p : corners) {
    float d = sqrt((p.first - f2.x) * (p.first - f2.x) +
                   (p.second - f2.y) * (p.second - f2.y));
    if (d < f2.radius)
      return true;
  }

  bool x_overlap = !((f1.right <= f2.x - f2.radius) || (f1.left >= f2.x + f2.radius));
  bool y_overlap = !((f1.top <= f2.y - f2.radius) || (f1.bottom >= f2.y + f2.radius));

  return x_overlap && y_overlap;
}

bool overlap(const Circle &f1, const Rect &f2) { return overlap(f2, f1); }