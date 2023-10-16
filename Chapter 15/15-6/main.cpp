import shape;
import shape.circle;
import shape.rectangle;

import <iostream>;
import <memory>;
import <vector>;


double calculateSumAreas(const std::vector<Shape*>& shapes)
{
    double sum = 0;

    for (auto* shape : shapes)
    {
        sum += shape->area();
    }

    return sum;
}


double calculateSumPerimeters(const std::vector<Shape*>& shapes)
{
    double sum {};

    for (auto* shape : shapes)
    {
        sum += shape->perimeter();
    }

    return sum;
}


void printSums(const std::vector<Shape*>& shapes)
{
    std::cout << "Sum of areas: " << calculateSumAreas(shapes) << std::endl;
    std::cout << "Sum of perimeters: " << calculateSumPerimeters(shapes) << std::endl;
}


int main()
{
    Circle c1 { {1, 1}, 1 };
    Circle c2 { {2, 2}, 2 };
    Circle c3 { {3, 3}, 3 };
    Rectangle r1 { {4, 5}, 4, 5 };
    Rectangle r2 { {6, 7}, 6, 7 };
    Rectangle r3 { {8, 9}, 8, 9 };

    std::vector<Shape*> shapes = { &c1, &r1, &r2, &c2, &c3, &r3 };

    printSums(shapes);

    for (auto* shape : shapes)
    {
        shape->scale(1.5);
    }

    std::cout << std::endl;

    printSums(shapes);
}