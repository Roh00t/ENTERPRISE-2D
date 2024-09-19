#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)
{

    for (int i = 0; i < 4; i++)
    {

        this->vertices[i] = vertices[i];

    }

}; // Rectangle(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)


string Rectangle::Get_X_Y_Vertices()
{

    // Return the vertices of the rectangle in the format (x, y)
    string results = "";

    for (int i = 0; i < 4; i++)
    {

        results += "Point [" + to_string(i) + "] : (" + to_string(this->vertices[i].x) + ", " + to_string(this->vertices[i].y) + ")\n";

    }

    return results;

}; // Get_X_Y_Vertices()


string Rectangle::toString()
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
    
}; //toString()

void Rectangle::ComputeShapeRange()
{

    // Compute the range of the rectangle and store it in the object
    this->min_x = vertices[0].x;
    this->min_y = vertices[0].y;
    this->max_x = vertices[0].x;
    this->max_y = vertices[0].y;

    for (int i = 0; i < 4; i++)
    {

        if (vertices[i].x > max_x)
        {

            max_x = vertices[i].x;

        }

        if (vertices[i].x < min_x)
        {

            min_x = vertices[i].x;

        }

        if (vertices[i].y > max_y)
        {

            max_y = vertices[i].y;

        }

        if (vertices[i].y < min_y)
        {

            min_y = vertices[i].y;

        }

    }

}; // ComputeShapeRange()


double Rectangle::computeArea()
{

    // Compute the range of the rectangle
    ComputeShapeRange();

    // Change status
    this->area_perimeter_IsProcessed = true;

    // Calculate the area and return it
    return (max_x - min_x) * (max_y - min_y);

}; // computeArea()


bool Rectangle::isPointInShape(int x, int y)
{

    if (x > min_x && x < max_x && y > min_y && y < max_y) // If the point is within the range of rectangle (excluding the perimeter)
    {

        return true;

    }
    else
    {

        return false;

    }

}; //isPointInShape(int x, int y)


bool Rectangle::isPointOnShape(int x, int y)
{

    if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) // If the point is within the range of rectangle (including the perimeter)
    {

        if (x == min_x || x == max_x || y == min_y || y == max_y) // If the point is on the perimeter of the rectangle
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


bool Rectangle::IsVertex_X_Y_Coordinate(int x, int y)
{
    // Check if the point is a vertex of the rectangle
    for (int i = 0; i < 4; i++)
    {

        if (x == vertices[i].x && y == vertices[i].y)
        {

            return true;

        }

    }

    return false;

};
Rectangle::~Rectangle()
{

    // Free up the memory used by the vertices array
    delete[] vertices;

}; // Destructor ~Rectangle()
