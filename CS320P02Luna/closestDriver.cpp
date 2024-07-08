#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <cmath>
#include "Point.h"
#include "mergeSort.h"

using namespace std;

pair<Point, Point> min(pair<Point, Point> x, pair<Point, Point> y);

pair<Point, Point> bruteForce(const vector<Point>& vectP, size_t low, size_t high);

pair<Point, Point> stripClosest(const vector<Point>& strip, size_t size, double min);

pair<Point, Point> closest(const vector<Point>& vectP, size_t low, size_t high);

pair<Point, Point> closest(vector<Point> vectP);

int main()
{
    string fileName;
    ifstream inputFile;
    double numInput, numInput2;
    Point numPoint;
    vector<Point> pointVect;

    pair<Point, Point> pt1, pt2;

    cout << "Enter Filename: ";
    cin >> fileName;
    inputFile.open(fileName+".txt"); // The name of the file you set up.

    while (inputFile >> numInput >> numInput2)
    {
        numPoint.setX(numInput);
        numPoint.setY(numInput2);
        pointVect.push_back(numPoint);
    }

    inputFile.close();

    pair<Point, Point> p1 = closest(pointVect);
    cout << "Closest points are: " << p1.first << " and " << p1.second << " with distance = " << p1.first.distance(p1.second) << endl;

    return 0;
}

pair<Point, Point> min(pair<Point, Point> xl, pair<Point, Point> xr){

    return (xl.first.distance(xl.second) < xr.first.distance(xr.second)) ? xl : xr;
}

pair<Point, Point> bruteForce(const vector<Point>& vectP, size_t low, size_t high) {

    int n = high - low + 1;
    double distance;
    double minDistance = DBL_MAX;

    Point p1;
    Point p2;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distance = vectP[low + i].distance(vectP[low + j]);
            if (distance < minDistance) {
                minDistance = distance;
                p1 = vectP[low + i];
                p2 = vectP[low + j];
            }
        }
    }
    return pair<Point, Point>(p1, p2);
}

pair<Point, Point> stripClosest(const vector<Point>& strip, size_t size, double min)
{
   
    pair<Point, Point> pair1 (Point(0, 0), Point(INT16_MAX, INT16_MAX));
    
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size && (strip[j].getY() - strip[i].getY()) < min; j++)
            if ((strip[i].distance(strip[j]) < min) ) {
                min = strip[i].distance(strip[j]);
                pair1.first = strip[i];
                pair1.second = strip[j];
            }
    return pair1;
}

pair<Point, Point> closest(const vector<Point>& vectP, size_t low, size_t high) {
    if (high - low <= 4)
        return bruteForce(vectP, low, high);

    int mid = ceil((high-low) / 2) +1;
    Point midPoint = vectP[low+mid];
    
    pair<Point, Point> dl = closest(vectP, low, low + mid - 1);
    pair<Point, Point> dr = closest(vectP, low + mid, high);
    pair<Point, Point> minimum = min(dl, dr);

    vector<Point> strip;
    int d = minimum.first.distance(minimum.second);
    int j = 0;
    for (int i = 0; i < high - low; i++)
        if (abs(vectP[low+i].getX() - midPoint.getX()) < d) {
            strip.push_back(vectP[low+i]);
            j++;
        }

    mergeSort(strip, Point::CompareYCoordinate());
    minimum = min(minimum, stripClosest(strip, j, d));
   
   return minimum;

}

pair<Point, Point> closest(vector<Point> vectP) {

    if (vectP.size() < 1)
        return pair<Point, Point>(Point(0, 0), Point(INT16_MAX, INT16_MAX));
    
    mergeSort(vectP, Point::CompareXCoordinate());

    return closest(vectP, 0, vectP.size()-1);
}

