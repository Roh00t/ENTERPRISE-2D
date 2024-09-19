#include <sstream>
#include <iomanip>
#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate vertex, int radius) : ShapeTwoD(name, containsWarpSpace)
{

    this->vertex = vertex;
    this->radius = radius;

}; // Circle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate vertex, int radius) : ShapeTwoD(name, containsWarpSpace)


string Circle::Get_X_Y_Vertices()
{

    // Return the center of the circle in the format (x, y), and radius
    return "Center : (" + to_string(this->vertex.x) + ", " + to_string(this->vertex.y) + ")\nRadius : " + to_string(this->radius) + "\n";

}; // Get_X_Y_Vertices()


string Circle::toString()
{

    ostringstream oss;
    string areaString = "";
    oss << fixed << setprecision(2) << area; // returns 2 decimal places
    areaString = oss.str();


    string results = "";
    results += "Shape [" + to_string(GetShapeId()) + "]";
    results += "\nName : " + getName();
    results += "\nSpecial Type : " + (getContainsWarpSpace() ? string("WS") : string("NS"));
    results += "\nArea : " + areaString + " units square";
    results += "\nVertices : \n" + Get_X_Y_Vertices();
    results += "\nPoints on Perimeter : " + ShapeTwoD::getPointsOnPerimeter();
    results += "\n\nPoints within shape : " + ShapeTwoD::getPointsWithinShape() + "\n";

    return results;

};// toString()


double Circle::computeArea()
{

    // Compute the range of the circle and store it in the object
    this->min_x = vertex.x - radius;
    this->min_y = vertex.y - radius;
    this->max_x = vertex.x + radius;
    this->max_y = vertex.y + radius;


    // Compute the area of the circle
    double area = radius * radius * 3.14;


    // Change status
    this->area_perimeter_IsProcessed = true;


    // Round to 2 decimal places
    return ceil(area * 100) / 100;


}; // computeArea()


bool Circle::isPointInShape(int x, int y)
{

    // Check if the point is within the circle
    if (sqrt(pow(x - vertex.x, 2) + pow(y - vertex.y, 2)) < radius) // If the distance between the point and the center of the circle is less than the radius
    {

        return true; // The point is within the circle

    }
    else // Else, the point is not within the circle
    {

        return false;

    } // end of if else statement


}; // isPointInShape(int x, int y)



bool Circle::isPointOnShape(int x, int y)
{
    // Check if the point is on the circle
    if (vertex.x == x && vertex.y + radius == y) // (Center X, Center Y + Radius) : North
    {

        return true;

    }
    else if (vertex.x == x && vertex.y - radius == y) // (Center X, Center Y - Radius) : South
    {

        return true;

    }
    else if (vertex.x + radius == x && vertex.y == y) // (Center X + Radius, Center Y) : East
    {

        return true;

    }
    else if (vertex.x - radius == x && vertex.y == y) // (Center X - Radius, Center Y) : West
    {

        return true;

    }
    else
    {

        return false;

    }// // end of if else statement

    
};  // isPointOnShape(int x, int y)


bool Circle::IsVertex_X_Y_Coordinate(int x, int y)
{

    return !isPointOnShape(x, y);

};// IsVertex_X_Y_Coordinate(int x, int y)


Circle::~Circle(){};
