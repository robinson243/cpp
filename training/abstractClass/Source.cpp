#include <iostream>

// Classes abtraite
class Shape {
  protected:
	float x, y;

  public:
	Shape(float X, float Y) : x(X), y(Y) {};
	// Tout les enfants doivent avoir implementer cette fonction
	virtual void draw() const = 0;
};

class Cercle : public Shape {
  protected:
	float rayon;

  public:
	Cercle(float x, float y, float RADIUS) : Shape(x, y), rayon(RADIUS) {
	}
	virtual void draw() const {
		std::cout << "position x : " << x << std::endl;
		std::cout << "position y : " << y << std::endl;
		std::cout << "rayon est : " << rayon << std::endl;
	}
};

int main() {
	Cercle circle(1.0f, 2.5f, 3.0f);
	circle.draw();
}