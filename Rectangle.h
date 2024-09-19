#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "ShapeTwoD.h"
using namespace std;


// Class Rectangle is the child class to SuperClass ShapeTwoD:
class Rectangle : public ShapeTwoD
{

private:
    vertex_x_y_coordinate * vertices = new vertex_x_y_coordinate[4];// An array of four vertices representing the corners of the rectangle. It dynamically allocates memory for the vertices.

public:

    //Define Constructor:
    Rectangle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices); // Constructor that initializes the rectangle with a name, warp space property, and vertices.

    //Define Methods:
    string Get_X_Y_Vertices(); // Returns a string representation of the rectangle's vertices.
    string toString(); // Returns a string representation of the rectangle, including its properties and vertices.
    void ComputeShapeRange(); // Computes the range (bounding box) of the rectangle based on its vertices.
    double computeArea(); // Computes and returns the area of the rectangle.
    bool isPointInShape(int x, int y); // Checks if a point (x, y) is inside the rectangle.
    bool isPointOnShape(int x, int y); // Checks if a point (x, y) is on the perimeter of the rectangle.
    bool IsVertex_X_Y_Coordinate(int x, int y); // Checks if a point (x, y) is one of the rectangle's vertices.

    //Define Destructor:
    ~Rectangle();//  Destructor to clean up dynamically allocated memory.


};



#endif