#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include <string>
// #include "vertex_x_y_coordinate.h" // stores the x and y coordinates
using namespace std;


//Define a struct to store the x and y value coordinates
// This struct is called the the ShapeTwoD.h
struct vertex_x_y_coordinate
{
    int x;
    int y;
};


//This class represents a two-dimensional shape and includes various attributes and methods related to the shape's properties and behaviors:
class ShapeTwoD
{
// Protected Methods:
protected:
    int id; // An identifier for the shape.
    string name; // The name of the shape.
    bool containsWarpSpace;// Indicates whether the shape contains warp space (a specific characteristic).
    double area = 0.0; // The area of the shape, initialized to 0.0.
    int min_x, max_x, min_y, max_y; //  Coordinates defining the bounding box of the shape.
    //For area and perimeter processing:
    bool area_perimeter_IsProcessed = false; // A flag indicating whether the shape's area and perimeter have been processed.

public:
    ShapeTwoD(string * name, bool * containsWarpSpace); // Constructor that initializes the shape with a name and warp space property.
    virtual ~ShapeTwoD(); // Virtual destructor to ensure proper cleanup of derived class objects.

    // Define Getters:
    int GetShapeId(); // Returns the shape's ID.
    string getName(); // Returns the shape's name. 
    bool getContainsWarpSpace(); // Returns whether the shape contains warp space.
    double getArea(); // Returns the shape's area.
    virtual string Get_X_Y_Vertices(); // Virtual method to get the vertices of the shape (to be overridden by derived classes).
    virtual string toString(); // Virtual method that returns a string representation of the shape (to be overridden by derived classes).

    //Computational Methods:
    virtual double computeArea(); // Virtual method to compute the shape's area (to be overridden by derived classes).
    virtual bool isPointInShape(int x, int y); // Virtual method to check if a point is inside the shape (to be overridden by derived classes).
    virtual bool isPointOnShape(int x, int y);// Virtual method to check if a point is on the shape (to be overridden by derived classes).
    string getPointsOnPerimeter();// Returns points on the shape's perimeter.
    string getPointsWithinShape();// Returns points within the shape.
    virtual bool IsVertex_X_Y_CoordinateXYCoordinate(int x, int y); // Virtual method to check if a point is a vertex of the shape (to be overridden by derived classes).
    

    //Define Setters:
    void SetShapeId(int id); // Sets the shape's ID.
    void setName(string name); // Sets the shape's name.
    void setContainsWarpSpace(bool containsWarpSpace); // Sets whether the shape contains warp space.
    void setArea(double area); // Sets the shape's area.
};
#endif