#ifndef CIRCLE_H
#define CIRCLE_H
#include "ShapeTwoD.h"
using namespace std;



class Circle : public ShapeTwoD
{
private:
    vertex_x_y_coordinate vertex;// An array of four vertices representing the corners of the circle. It dynamically allocates memory for the vertices.
    int radius; // An int to take in the radius user input

public:

    //Define Constructor:
    Circle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate vertex, int radius);

    //Define Methods: 
    string Get_X_Y_Vertices(); // Returns a string representation of the circle's vertices.
    string toString(); // Returns a string representation of the circle, including its properties and vertices.
    double computeArea(); // Computes and returns the area of the circle.
    bool isPointInShape(int x, int y); // Checks if a point (x, y) is inside the circle.
    bool isPointOnShape(int x, int y); // Checks if a point (x, y) is on the perimeter of the circle.
    bool IsVertex_X_Y_Coordinate(int x, int y); // Checks if a point (x, y) is one of the circle's vertices.

    //Define Destructor:
    ~Circle(); // Destructor to clean up dynamically allocated memory.
};

#endif