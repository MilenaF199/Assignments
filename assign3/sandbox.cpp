/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include <iostream>
#include "class.h"

void sandbox() {
  triangle triangle1;
  triangle deftriangle(8.8, 5.0);

  std::cout << "Default Triangle: Base = " << triangle1.get_base() 
            << ", Height = " << triangle1.get_hei() 
            << ", Area = " << triangle1.get_area() << std::endl;

  std::cout << "Triangle: Base = " << deftriangle.get_base() 
            << ", Height = " << deftriangle.get_hei() 
            << ", Area = " << deftriangle.get_area() << std::endl;

  triangle1.set_base(6.0);
  triangle1.set_hei(2.0);

  std::cout << "Updated Default Triangle: Base = " << triangle1.get_base() 
            << ", Height = " << triangle1.get_hei() 
            << ", Area = " << triangle1.get_area() << std::endl;

}