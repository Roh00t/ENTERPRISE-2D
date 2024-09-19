#ifndef CROSS_H
#define CROSS_H
#include "ShapeTwoD.h"
using namespace std;

// Class Cross is the child class of SuperClass ShapeTwoD:

class Cross : public ShapeTwoD
{
private:
    vertex_x_y_coordinate * vertices = new vertex_x_y_coordinate[12]; // An array of four vertices representing the corners of the cross. It dynamically allocates memory for the vertices.

    // Stores the inner corner vertices of the cross:
    int topRight_x, topRight_y, topLeft_x, topLeft_y, bottomRight_x, bottomRight_y, bottomLeft_x, bottomLeft_y;
    double subtractionAreas[4];

public:

    //Define Constructor:
    Cross(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices); // Constructor that initializes the cross with a name, warp space property, and vertices.

    //Define Methods: 
    string Get_X_Y_Vertices(); // Returns a string representation of the cross's vertices.
    string toString(); // Returns a string representation of the cross, including its properties and vertices.
    void ComputeShapeRange(); // Computes the range (bounding box) of the cross based on its vertices.
    double computeArea(); // Computes and returns the area of the cross.
    bool isPointInShape(int x, int y); // Checks if a point (x, y) is inside the cross.
    bool isPointOnShape(int x, int y); // Checks if a point (x, y) is on the perimeter of the cross.
    bool IsVertex_X_Y_Coordinate(int x, int y); // Checks if a point (x, y) is one of the cross's vertices.

    //Define Destructor:
    ~Cross(); // Destructor to clean up dynamically allocated memory.
};
#endif