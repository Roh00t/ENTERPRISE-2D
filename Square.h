#ifndef SQUARE_H
#define SQUARE_H
#include "ShapeTwoD.h"
using namespace std;

// Class Square is the child class to SuperClass ShapeTwoD:
class Square : public ShapeTwoD
{

private:
    vertex_x_y_coordinate * vertices = new vertex_x_y_coordinate[4]; // An array of four vertices representing the corners of the square. It dynamically allocates memory for the vertices.


public:

    //Define Constructor:
    Square(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices); // Constructor that initializes the square with a name, warp space property, and vertices.

    //Define Methods: 
    string Get_X_Y_Vertices(); // Returns a string representation of the square's vertices.
    string toString(); // Returns a string representation of the square, including its properties and vertices.
    void ComputeShapeRange(); // Computes the range (bounding box) of the square based on its vertices.
    double computeArea(); // Computes and returns the area of the square.
    bool isPointInShape(int x, int y); // Checks if a point (x, y) is inside the square.
    bool isPointOnShape(int x, int y); // Checks if a point (x, y) is on the perimeter of the square.
    bool IsVertex_X_Y_Coordinate(int x, int y); // Checks if a point (x, y) is one of the square's vertices.


    //Define Destructor:
    ~Square(); //  Destructor to clean up dynamically allocated memory.

};


#endif