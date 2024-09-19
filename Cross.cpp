#include <iostream>
#include <algorithm>
#include "Cross.h"
using namespace std;


// Cross is a child class to SuperClass ShapeTwoD, hence inheriting the name and containsWarpSpace:
Cross::Cross(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)
{

    for (int i = 0; i < 12; i++)
    {

        this->vertices[i] = vertices[i];

    } // end of for loop

}; // Cross(string * name, bool * containsWarpSpace, vertex_x_y_coordinate * vertices) : ShapeTwoD(name, containsWarpSpace)


string Cross::Get_X_Y_Vertices()
{

    // Return the vertices of the cross in the format (x, y):
    string results = "";

    for (int i = 0; i < 12; i++)
    {

        results += "Point [" + to_string(i) + "] : (" + to_string(this->vertices[i].x) + ", " + to_string(this->vertices[i].y) + ")\n";

    } // end of for loop

    return results;

}; // Get_X_Y_Vertices()


string Cross::toString()
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


void Cross::ComputeShapeRange()
{

    // Compute the range of the cross and store it in the object:
    this->min_x = vertices[0].x;
    this->min_y = vertices[0].y;
    this->max_x = vertices[0].x;
    this->max_y = vertices[0].y;


    for (int i = 0; i < 12; i++)
    {

        if (vertices[i].x > max_x)
        {
            
            this->max_x = vertices[i].x;

        } // end of if statement

        if (vertices[i].x < min_x)
        {

            this->min_x = vertices[i].x;

        } // end of if statement

        if (vertices[i].y > max_y)
        {

            this->max_y = vertices[i].y;

        } // end of if statement

        if (vertices[i].y < min_y)
        {

            this->min_y = vertices[i].y;

        } // end of if statement

    } // end of for loop

}; // ComputeShapeRange()


double Cross::computeArea()
{

    // Compute the range of the cross:
    ComputeShapeRange();

    // Calculate the area of the cross:
    double area = (max_x - min_x) * (max_y - min_y);
/*
    Variables that store the Coordinates
    ==================================
    |   temp_trx => top right x     |
    |   temp_try => top right y     |
    |   temp_tlx => top left x      |
    |   temp_tly => top left y      |
    |   temp_brx => bottom right x  |
    |   temp_bry => bottom right y  |
    |   temp_blx => bottom left x   |
    |   temp_bly => bottom left y   |
    ==================================
*/
    // Find the 4 inner corners of the cross:
    // Initialize the variables which will store the coordinates of the adjacent points of the inner corners:
    int temp_trx, temp_try, temp_tlx, temp_tly, temp_brx, temp_bry, temp_blx, temp_bly; 
    temp_trx = temp_try = temp_tlx = temp_tly = temp_brx = temp_bry = temp_blx = temp_bly = -1; // Initialize Variables to Store Inner Corner Coordinates

    // Find the Inner Corners of the Cross:
    for (int i = 0; i < 12; i++) // loops through all the 12 x,y coordinates to find the inner corners
    {

        if (vertices[i].y == min_y) // If the vertex is on the bottom edge:
        {

            if (temp_blx == -1)           // If the bottom left x coordinate has not been set
                temp_blx = vertices[i].x; // Set the bottom left x coordinate

            else
            {

                // Set the smaller x coordinate as the bottom left, and the larger x coordinate as the bottom right:
                
                if (temp_blx > vertices[i].x)
                {

                    temp_brx = temp_blx;
                    temp_blx = vertices[i].x;

                }
                else
                {

                    temp_brx = vertices[i].x;

                } // end of inner if else statement

            } // end of outer if else statement

        } // end of outer if else statement


        if (vertices[i].y == max_y) // If the vertex is on the top edge
        {

            if (temp_tlx == -1)           // If the top left x coordinate has not been set
                temp_tlx = vertices[i].x; // Set the top left x coordinate

            else
            {

                // Set the smaller x coordinate as the top left, and the larger x coordinate as the top right:
                if (temp_tlx > vertices[i].x)
                {

                    temp_trx = temp_tlx;
                    temp_tlx = vertices[i].x;

                }
                else
                {

                    temp_trx = vertices[i].x;

                } // end of inner if else statement

            } // end of outer if else statement

        } // end of outer if else statement


        if (vertices[i].x == min_x) // If the vertex is on the left edge
        {

            if (temp_bly == -1)           // If the bottom left y coordinate has not been set
                temp_bly = vertices[i].y; // Set the bottom left y coordinate

            else
            {

                // Set the smaller y coordinate as the bottom left, and the larger y coordinate as the top left:
                if (temp_bly > vertices[i].y)
                {

                    temp_tly = temp_bly;
                    temp_bly = vertices[i].y;

                }
                else
                {

                    temp_tly = vertices[i].y;

                } // end of inner if else statement

            } // end of outer if else statement

        } // end of outer if else statement


        if (vertices[i].x == max_x) // If the vertex is on the right edge
        {

            if (temp_bry == -1)           // If the bottom right y coordinate has not been set
                temp_bry = vertices[i].y; // Set the bottom right y coordinate

            else
            {

                // Set the smaller y coordinate as the bottom right, and the larger y coordinate as the top right
                if (temp_bry > vertices[i].y)
                {

                    temp_try = temp_bry;
                    temp_bry = vertices[i].y;

                }
                else
                {

                    temp_try = vertices[i].y;

                } // end of inner if else statement

            } // end of outer if else statement

        } // // end of outer if else statement

    } // end of for loop



    // Store the coordinates of the inner corners in the object
    this->topRight_x = temp_trx;
    this->topRight_y = temp_try;
    this->topLeft_x = temp_tlx;
    this->topLeft_y = temp_tly;
    this->bottomRight_x = temp_brx;
    this->bottomRight_y = temp_bry;
    this->bottomLeft_x = temp_blx;
    this->bottomLeft_y = temp_bly;



    // Calculate the area of the 4 squares
    this->subtractionAreas[0] = (max_x - topRight_x) * (max_y - topRight_y);
    this->subtractionAreas[1] = (max_x - bottomRight_x) * (bottomRight_y - min_y);
    this->subtractionAreas[2] = (topLeft_x - min_x) * (max_y - topLeft_y);
    this->subtractionAreas[3] = (bottomLeft_x - min_x) * (bottomLeft_y - min_y);



    // Subtract the areas of the 4 squares from the area of the cross
    for (int i = 0; i < 4; i++)
    {

        area -= subtractionAreas[i];

    }

    // Change status
    this->area_perimeter_IsProcessed = true;


    // Return calculated area
    return area;


}; // computeArea()


bool Cross::isPointInShape(int x, int y)
{

    if (x > min_x && x < max_x && y > min_y && y < max_y) // If the point is within the range of the cross (excluding the perimeter)
    {

        if (x >= topRight_x && x <= max_x && y >= topRight_y && y <= max_y) // If the point is within the top right subtraction square
        {

            return false;

        }
        else if (x >= min_x && x <= topLeft_x && y >= topLeft_y && y <= max_y) // If the point is within the top left subtraction square
        {

            return false;

        }
        else if (x >= bottomRight_x && x <= max_x && y >= min_y && y <= bottomRight_y) // If the point is within the bottom right subtraction square
        {

            return false;

        }
        else if (x >= min_x && x <= bottomLeft_x && y >= min_y && y <= bottomLeft_y) // If the point is within the bottom left subtraction square
        {

            return false;

        }
        else if (x == min_x || x == max_x || y == min_y || y == max_y) // If the point is on the perimeter of the cross
        {

            return false;

        }
        else // Else, the point is within the cross
        {

            return true;

        } // end of inner if else statement

    }
    else
    {

        return false;

    } // end of outer if else statement
}; //isPointInShape(int x, int y)


bool Cross::isPointOnShape(int x, int y)
{

    if (x >= min_x && x <= max_x && y >= min_y && y <= max_y) // If the point is within the range of the cross
    {

        if (y == topRight_y && x >= topRight_x && x <= max_x) // If the point is on the top right horizontal edge
        {

            return true;

        }
        else if (y == topLeft_y && x >= min_x && x <= topLeft_x) // If the point is on the top left horizontal edge
        {

            return true;

        }
        else if (y == bottomRight_y && x >= bottomRight_x && x <= max_x) // If the point is on the bottom right horizontal edge
        {

            return true;

        }
        else if (y == bottomLeft_y && x >= min_x && x <= bottomLeft_x) // If the point is on the bottom left horizontal edge
        {

            return true;

        }
        else if (x == topRight_x && y >= topRight_y && y <= max_y) // If the point is on the top right vertical edge
        {

            return true;

        }
        else if (x == topLeft_x && y >= topLeft_y && y <= max_y) // If the point is on the top left vertical edge
        {

            return true;

        }
        else if (x == bottomRight_x && y >= min_y && y <= bottomRight_y) // If the point is on the bottom right vertical edge
        {

            return true;

        }
        else if (x == bottomLeft_x && y >= min_y && y <= bottomLeft_y) // If the point is on the bottom left vertical edge
        {

            return true;

        }
        else if (x == min_x && y >= bottomLeft_y && y <= topLeft_y) // If the point is on the left edge
        {

            return true;

        }
        else if (x == max_x && y >= bottomRight_y && y <= topRight_y) // If the point is on the right edge
        {

            return true;

        }
        else if (y == min_y && x >= bottomLeft_x && x <= bottomRight_x) // If the point is on the bottom edge
        {

            return true;

        }
        else if (y == max_y && x >= topLeft_x && x <= topRight_x) // If the point is on the top edge
        {

            return true;

        }
        else
        {

            return false;

        } // end of inner if else statement
    }
    else
    {

        return false;

    } // end of outer if else statement

};// isPointOnShape(int x, int y)



bool Cross::IsVertex_X_Y_Coordinate(int x, int y)
{
    // Check if the point is a vertex of the cross
    for (int i = 0; i < 12; i++)
    {

        if (vertices[i].x == x && vertices[i].y == y)
        {

            return true;

        }// end of if else statement

    } // end of for loop


    return false;



};  // IsVertex_X_Y_Coordinate(int x, int y)



Cross::~Cross()
{
    // Deallocate the memory used by the vertices array
    delete[] vertices;
}; // end of destructor ~Cross()
