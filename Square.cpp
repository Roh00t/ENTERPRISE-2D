#include <cmath>
#include "Square.h"
using namespace std;

Square::Square(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)
{

    for (int i = 0; i < 4; i++)
    {

        this->vertices[i] = vertices[i];

    } // end of for loop


}; // Square(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)


string Square::Get_X_Y_Vertices()
{

    // Return the vertices of the square in the format (x, y):
    string results = "";

    for (int i = 0; i < 4; i++)
    {
        // results will get populated here and displayed on screen each time getVerices() is called in the toString():
        results += "Point [" + to_string(i) + "] : (" + to_string(this->vertices[i].x) + ", " + to_string(this->vertices[i].y) + ")\n"; 

    } // end of for loop

    return results;

}; // Get_X_Y_Vertices()


string Square::toString()
{

    string results = "";
    results += "Shape [" + to_string(GetShapeId()) + "]";
    results += "\nName : " + getName();
    results += "\nSpecial Type : " + (getContainsWarpSpace() ? string("WS") : string("NS"));
    results += "\nArea : " + to_string(int(area)) + " units square";
    results += "\nVertices : \n" + Get_X_Y_Vertices();
    results += "\nPoints on Perimeter : " + ShapeTwoD::getPointsOnPerimeter();
    results += "\n\nPoints within shape : " + ShapeTwoD::getPointsWithinShape() + "\n";
    return results;

}; // toString()


void Square::ComputeShapeRange()
{

    // Initializes min_x, min_y, max_x, and max_y to the coordinates of the first vertex:
    // Compute the range of the square and store it in the object:
    this->min_x = vertices[0].x; // used to access the members of the Square object via 'this' pointer.
    this->min_y = vertices[0].y;
    this->max_x = vertices[0].x;
    this->max_y = vertices[0].y;

    //The loop iterates through all four vertices of the square:
    //For each vertex, it updates max_x, min_x, max_y, and min_y if the current vertex's x or y coordinates are greater than or less than the current maximum or minimum values:
    for (int i = 0; i < 4; i++)
    {

        if (vertices[i].x > max_x)
        {

            max_x = vertices[i].x;

        } // end of first if loop

        if (vertices[i].x < min_x)
        {

            min_x = vertices[i].x;

        }// end of second if loop

        if (vertices[i].y > max_y)
        {

            max_y = vertices[i].y;

        }// end of third if loop

        if (vertices[i].y < min_y)
        {

            min_y = vertices[i].y;

        }// end of third if loop

    } // end of for loop

}; // ComputeShapeRange()


double Square::computeArea()
{

    // Compute the range of the square:
    ComputeShapeRange();

    // Change status
    this->area_perimeter_IsProcessed = true; // used to access the member, 'area_perimeter_IsProcessed' via 'this' pointer.

    // Calculate the area and return it:
    return pow(max_x - min_x, 2); // returns max_x - min_x to the power of 2. e.g (max_x - min_x)^2

}; //computeArea()


bool Square::isPointInShape(int x, int y)
{

    if (x > min_x && x < max_x && y > min_y && y < max_y) // If the point is within the range of square (excluding the perimeter)
    {

        return true;

    }
    else
    {

        return false;

    }

}; // isPointInShape(int x, int y)


bool Square::isPointOnShape(int x, int y)
{

    if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) // If the point is within the range of the square (including the perimeter)
    {

        if (x == min_x || x == max_x || y == min_y || y == max_y) // If the point is on the perimeter of the square
        {

            return true;

        }
        else
        {

            return false;

        }
    }
    else
    {

        return false;

    }

}; // isPointOnShape(int x, int y)


bool Square::IsVertex_X_Y_Coordinate(int x, int y)
{

    // Check if the point is a vertex of the square
    for (int i = 0; i < 4; i++)
    {

        if (vertices[i].x == x && vertices[i].y == y)
        {

            return true;

        }
        
    }

    return false;

}; // IsVertex_X_Y_Coordinate(int x, int y)


Square::~Square()
{

    // free up the memory used by the vertices
    delete[] vertices;

}; // Destructor ~Square()
