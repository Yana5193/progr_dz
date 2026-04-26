#include <iostream>
#include <vector>
#include <iomanip> 
#include "shape.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
	vector<Shape*> shapes;

    shapes.push_back(new Circle({ 0, 0 }, 2.0));
    shapes.push_back(new Ellips({ 0, 0 }, 5.0, 3.0));
    shapes.push_back(new Triangle({ 0, 0 }, { 10, 0 }, { 5, 10 }));
    shapes.push_back(new Rectangle({ 0, 0 }, { 4, 0 }, { 4, 4 }, { 0, 4 }));
    shapes.push_back(new Polygon("granitsy-uchastka2.txt"));

    double totalArea = 0.0;

    cout << fixed << setprecision(2); 
    cout << "Фигуры " << endl;

    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->name();
        double curArea = shapes[i]->calc_area();
        cout << "   Площадь: " << curArea << endl;
        cout << "   Периметр: " << shapes[i]->calc_perimeter() << endl;
        totalArea += curArea;
    }
    cout << "Сумма площадей: " << totalArea << endl;
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    shapes.clear();
    return 0;
}