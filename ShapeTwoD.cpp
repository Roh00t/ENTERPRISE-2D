

//Preprocessors Directives:
#include <sstream>
#include <iomanip>
#include <string>
#include "ShapeTwoD.h"
using namespace std;

//Defination of constructors:
ShapeTwoD::ShapeTwoD(string * name, bool * containsWarpSpace)
{
    this->name = * name;
    this->containsWarpSpace = * containsWarpSpace;
} // ShapeTwoD

int ShapeTwoD::GetShapeId()
{
    return id;
} // GetShapeId()


string ShapeTwoD::getName()
{
    return name;
}// getName()

bool ShapeTwoD::getContainsWarpSpace()
{

    return containsWarpSpace;

}// getContainsWarpSpace()

double ShapeTwoD::getArea()
{

    return area;

} //getArea()


string ShapeTwoD::Get_X_Y_Vertices()
{

    // Virtual method that should be overridden
    return "should be overridden";

} //Get_X_Y_Vertices()


string ShapeTwoD::toString()
{


    // toString method without printing vertices
    string results = "";
    string name = getName();
    string areaString = "";
    double area = getArea();
    string uppercase_name = name;
    for (auto &c : uppercase_name)
        c = toupper(c);


    if (uppercase_name == "CIRCLE") // If the shape is circle, print 2 decimal places
    {
        ostringstream oss;
        oss << fixed << setprecision(2) << area;
        areaString = oss.str();
    } 
    else
    {
        areaString = to_string(int(area));
    } // end of if else loop


    results += "Shape ID \t:" + to_string(GetShapeId()) + "\n";
    results += "Name \t\t:" + name + "\n";
    results += "Special Type \t:" + (getContainsWarpSpace() == true ? string("WS") : string("NS")) + "\n";
    results += "Area \t\t:" + areaString + " unit(s) square\n";
    return results;


} // toString()


double ShapeTwoD::computeArea()
{


    // Virtual method that should be overridden
    return 0;


} // computeArea()


bool ShapeTwoD::isPointInShape(int x, int y)
{

    // Virtual method that should be overridden
    return false;

} // isPointInShape(int x, int y)



bool ShapeTwoD::isPointOnShape(int x, int y)
{

    // Virtual method that should be overridden
    return false;

}// isPointOnShape(int x, int y)


string ShapeTwoD::getPointsOnPerimeter()
{

    string results = "";


    if (area_perimeter_IsProcessed)
    {
        
        results = "";
        for (int x = min_x; x <= max_x; x++)
        {
            for (int y = min_y; y <= max_y; y++)
            {
                if (isPointOnShape(x, y) && !IsVertex_X_Y_CoordinateXYCoordinate(x, y))
                {
                    if (results.length() > 0)
                    {
                        results += ", ";
                    }
                    results += "(" + to_string(x) + ", " + to_string(y) + ")";
                }
            }
        }
        if (results == "")
        {
            results = "none!";
        }
    }
    else
    {
        results = "Press [2] in menu to view points";
    }


    return results;


}; // getPointsOnPerimeter()


string ShapeTwoD::getPointsWithinShape()
{

    string results = "";


    if (area_perimeter_IsProcessed)
    {
        for (int x = min_x; x <= max_x; x++)
        {
            for (int y = min_y; y <= max_y; y++)
            {
                if (isPointInShape(x, y))
                {
                    if (results.length() > 0)
                    {
                        results += ", ";
                    }
                    results += "(" + to_string(x) + ", " + to_string(y) + ")";
                }
            }
        }
        if (results == "")
        {
            results = "none!";
        }
    }
    else
    {
        results = "Press [2] in menu to view points";
    } // end of if else loop


    return results;


}; // getPointsWithinShape()



bool ShapeTwoD::IsVertex_X_Y_CoordinateXYCoordinate(int x, int y)
{

    // Virtual method that should be overridden
    return false;

} // IsVertex_X_Y_CoordinateXYCoordinate(int x, int y)


void ShapeTwoD::SetShapeId(int id)
{

    this->id = id;

} // SetShapeId(int id)


void ShapeTwoD::setName(string name)
{

    this->name = name;

} // setName(string name)


void ShapeTwoD::setContainsWarpSpace(bool containsWarpSpace)
{

    this->containsWarpSpace = containsWarpSpace;

} // setContainsWarpSpace(bool containsWarpSpace)


void ShapeTwoD::setArea(double area)
{

    this->area = area;

} // setArea(double area)


ShapeTwoD::~ShapeTwoD(){};
