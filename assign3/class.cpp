#include "class.h"

triangle::triangle() : base (1.0), height(1.0) {}
triangle::triangle(double base, double height) : base(base), height(height) {}

double triangle::area() const {
    return 0.5 * base * height;
}

double triangle::get_base() const {
    return base;
}
void triangle::set_base(double base){
    this->base = base;
}

double triangle::get_hei() const{
    return height; 
}
void triangle::set_hei(double height){
    this->height = height;
}

double triangle::get_area() const {
    return area();
}