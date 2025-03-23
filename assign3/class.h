// Class of calculate the area of a triangle
#ifndef CLASS_H
#define CLASS_H

class triangle{
private:
    double base;
    double height; 

    double area() const;

public:
    triangle();
    triangle(double base, double height);
    
    double get_base() const;
    void set_base(double base);

    double get_hei() const;
    void set_hei(double height);

    double get_area() const; 

};

#endif 