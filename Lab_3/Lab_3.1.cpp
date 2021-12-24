#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

#define M_PI 3.14159265358979323

using namespace std;
using namespace sf;

class Exception 
{
public:

    string a;

public:

    void error()
    {
        cout << a << endl;
    }

    Exception(string text) 
    {
        a = text;
    }
};

class Figure
{

public:

    virtual string String() const = 0;
    virtual double calc_square() const = 0;
    virtual void Move(double x, double y) = 0;
    virtual void Draw() const = 0;
};


class Triangle : public Figure
{

public:

    double x1, x2, x3, y1, y2, y3;

public:

    string String() const
    {
        string a;
        a = "Triangle:   x1 = " + to_string(x1) + "  y1 = " + to_string(y1) + "  " + "x2 = " + to_string(x2) + "  " + "y2 = " + to_string(y2) + "  " + "x3 = " + to_string(x3) + "  " + "y3 = " + to_string(y3);
        return a;
    }

    void Move(double x, double y) 
    {
        x1 = x1 + x;
        x2 = x2 + x;
        y1 = y1 + y;
        y2 = y2 + y;
        x3 = x3 + x;
        y3 = y3 + y;
    }

    double calc_square() const
    {
        double a, b, c, s;
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        double p = (a + b + c) / 2;
        s = sqrt(p * (p - a) * (p - b) * (p - c));
        return s;
    }

    void Draw() const
    {
        RenderWindow window(VideoMode(500, 300), "Figure");
        ConvexShape convex;
        convex.setPointCount(3);
        convex.setPoint(0, Vector2f(x1, y1));
        convex.setPoint(1, Vector2f(x2, y2));
        convex.setPoint(2, Vector2f(x3, y3));
        convex.setFillColor(Color::Green);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(convex);
            window.display();
        }
    }

    Triangle(double side_x1, double side_x2, double side_x3, double side_y1, double side_y2, double side_y3)
        : x1(side_x1), x2(side_x2), x3(side_x3), y1(side_y1), y2(side_y2), y3(side_y3) 
    {
        if (side_x1 == 0 and side_x2 == 0 and side_y1 == 0 and side_y2 == 0 and side_x3 == 0)
            throw Exception("Ошибка: Неверное значение координат треугольника");
    }

    ~Triangle() {}
};

class Ellipse : public Figure
{

public:

    double x1, x2, y1, y2, x3, x4, y3, y4;

public:

    string String() const
    {
        string a;
        a = "Ellips:   x1 = " + to_string(x1) + "  y1 = " + to_string(y1) + "  " + "x2 = " + to_string(x2) + "  " + "y2 = " + to_string(y2) + "  " + "x3 = " + to_string(x3) + "  " + "y3 = " + to_string(y3) + "  " + "x4 = " + to_string(x4) + "  " + "y4 = " + to_string(y4);
        return a;
    }

    void Move(double x, double y) 
    {
        x1 = x1 + x;
        x2 = x2 + x;
        y1 = y1 + y;
        y2 = y2 + y;
        x3 = x3 + x;
        y3 = y3 + y;
        x4 = x4 + x;
        y4 = y4 + y;
    }

    double calc_square() const
    {
        double a, b, s;
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / 2;
        b = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3)) / 2;
        s = a * b * M_PI;
        return s;
    }

    void Draw() const
    {
        RenderWindow window(VideoMode(200, 200), "SFMLworks");;
        float radius_x = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / 2;
        float radius_y = sqrt((x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3)) / 2;
        unsigned short quality = 70;
        ConvexShape ellipseslav;
        ellipseslav.setPointCount(quality);

        for (unsigned short i = 0; i < quality; ++i) {
            float rad = (360. / quality * i) / (360. / M_PI / 2.);
            float x = cos(rad) * radius_x;
            float y = sin(rad) * radius_y;

            ellipseslav.setPoint(i,Vector2f(x, y));
        };
        ellipseslav.setFillColor(Color::Green);
        ellipseslav.setPosition(100, 100);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type ==Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(ellipseslav);
            window.display();
        }
    }

    Ellipse()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        x3 = 0;
        x4 = 0;
        y3 = 0;
        y4 = 0;
    }

    Ellipse(double side_x1, double side_x2, double side_y1, double side_y2, double side_x3, double side_x4, double side_y3, double side_y4)
        : x1(side_x1), x2(side_x2), y1(side_y1), y2(side_y2), x3(side_x3), x4(side_x4), y3(side_y3), y4(side_y4)
    {
        if (side_x1 == 0 and side_x2 == 0 and side_y1 == 0 and side_y2 == 0 and side_x3 == 0 and side_x4 == 0 and side_y3 == 0 and side_y4 == 0)
            throw Exception("Ошибка: Неверное значение координат эллипса");
    }

    ~Ellipse() {}
};

class Circle : public Ellipse
{

public:

    double x1, x2, y1, y2;

public:

    string String() const
    {
        string a;
        a = "Circle:   x1 = " + to_string(x1) + "  y1 = " + to_string(y1) + "  " + "x2 = " + to_string(x2) + "  " + "y2 = " + to_string(y2);
        return a;
    }

    void Move(double x, double y) 
    {
        x1 = x1 + x;
        x2 = x2 + x;
        y1 = y1 + y;
        y2 = y2 + y;
    }

    double calc_square() const
    {
        double r, s;
        r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        s = M_PI * r * r;
        return s;
    }

    void Draw() const
    {
        double r;
        r = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        RenderWindow window(VideoMode(200, 200), "SFMLworks");
        CircleShape shape(r);
        shape.setFillColor(Color::Green);

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
        }
    }

    Circle()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
    }

    Circle(double side_x1, double side_x2, double side_y1, double side_y2)
        : x1(side_x1), x2(side_x2), y1(side_y1), y2(side_y2) 
    {
        if (side_x1 == 0 and side_x2 == 0 and side_y1 == 0 and side_y2 == 0)
            throw Exception("Ошибка: Неверное значение координат окружности");
    }

    ~Circle() {}
};

class Rectangle : public Figure
{

public:

    double x1, x2, x3, x4, y1, y2, y3, y4;

public:

    string String() const
    {
        string a;
        a = "Rectangle:   x1 = " + to_string(x1) + "  y1 = " + to_string(y1) + "  " + "x2 = " + to_string(x2) + "  " + "y2 = " + to_string(y2) + "  " + "x3 = " + to_string(x3) + "  " + "y3 = " + to_string(y3) + "  " + "x4 = " + to_string(x4) + "  " + "y4 = " + to_string(y4);
        return a;
    }

    void Move(double x, double y) 
    {
        x1 = x1 + x;
        x2 = x2 + x;
        y1 = y1 + y;
        y2 = y2 + y;
        x3 = x3 + x;
        y3 = y3 + y;
        x4 = x4 + x;
        y4 = y4 + y;
    }

    double calc_square() const
    {
        double a, b, s;
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        s = a * b;
        return s;
    }

    void Draw() const
    {
        RenderWindow window(VideoMode(500, 300), "Figure");
        ConvexShape convex;
        convex.setPointCount(4);
        convex.setPoint(0, Vector2f(x1, y1));
        convex.setPoint(1, Vector2f(x2, y2));
        convex.setPoint(2, Vector2f(x3, y3));
        convex.setPoint(3, Vector2f(x4, y4));
        convex.setFillColor(Color::Green);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(convex);
            window.display();
        }
    }

    Rectangle()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        x3 = 0;
        x4 = 0;
        y3 = 0;
        y4 = 0;
    }

    Rectangle(double side_x1, double side_x2, double side_y1, double side_y2, double side_x3, double side_x4, double side_y3, double side_y4)
        : x1(side_x1), x2(side_x2), y1(side_y1), y2(side_y2), x3(side_x3), x4(side_x4), y3(side_y3), y4(side_y4) 
    {
        if (side_x1 == 0 and side_x2 == 0 and side_y1 == 0 and side_y2 == 0 and side_x3 == 0 and side_x4 == 0 and side_y3 == 0 and side_y4 == 0)
            throw Exception("Ошибка: Неверное значение координат прямоугольника");
    }

    ~Rectangle() {}
};

class Square : public Rectangle
{
public:

    double x1, x2, x3, x4, y1, y2, y3, y4;

public:

    string String() const
    {
        string a;
        a = "Square:   x1 = " + to_string(x1) + "  y1 = " + to_string(y1) + "  " + "x2 = " + to_string(x2) + "  " + "y2 = " + to_string(y2) + "  " + "x3 = " + to_string(x3) + "  " + "y3 = " + to_string(y3) + "  " + "x4 = " + to_string(x4) + "  " + "y4 = " + to_string(y4);
        return a;
    }

    void Move(double x, double y) 
    {
        x1 = x1 + x;
        x2 = x2 + x;
        y1 = y1 + y;
        y2 = y2 + y;
        x3 = x3 + x;
        y3 = y3 + y;
        x4 = x4 + x;
        y4 = y4 + y;
    }

    double calc_square() const
    {
        double a, s;
        a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        s = a * a;
        return s;
    }

    void Draw() const
    {
        RenderWindow window(VideoMode(500, 300), "Figure");
        ConvexShape convex;
        convex.setPointCount(4);
        convex.setPoint(0, Vector2f(x1, y1));
        convex.setPoint(1, Vector2f(x2, y2));
        convex.setPoint(2, Vector2f(x3, y3));
        convex.setPoint(3, Vector2f(x4, y4));
        convex.setFillColor(Color::Green);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.clear();
            window.draw(convex);
            window.display();
        }
    }

    Square()
    {
        x1 = 0;
        x2 = 0;
        y1 = 0;
        y2 = 0;
        x3 = 0;
        x4 = 0;
        y3 = 0;
        y4 = 0;
    }

    Square(double side_x1, double side_x2, double side_y1, double side_y2, double side_x3, double side_x4, double side_y3, double side_y4)
        : x1(side_x1), x2(side_x2), y1(side_y1), y2(side_y2), x3(side_x3), x4(side_x4), y3(side_y3), y4(side_y4) 
    {
        if (side_x1 == 0 and side_x2 == 0 and side_y1 == 0 and side_y2 == 0 and side_x3 == 0 and side_x4 == 0 and side_y3 == 0 and side_y4 == 0)
            throw Exception("Ошибка: Неверное значение координат квадрата");
    }

    ~Square() {}
};

template <class T>
class Prism
{
public:

    T* f;
    double h;

public:
    double Calc_Volume()
    {
        return h * (f->calc_square());
    }

    Prism(double h, T* f)
    {
        if (h < 0)
            throw Exception("Ошибка: Неверное значение высоты");
        this->h = h;
        this->f = f;
    }

    ~Prism() {}
};

int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    do
    {
        cout << "Введите номер задания 1-4 (введите '0' для выхода)" << endl;
        cin >> a;

        try 
        {
            if ((a > 4 or a < 1) and a != 0) throw "Неверрно введён номер задания";
        }
        catch (const char* exception)
        {
            cout << "Ошибка: " << exception << endl;
            cin >> a;
        }

        switch (a)
        {
        case 1:
        {
            Figure** figure = new Figure * [5];
            cout << "\nFigure #1 (triangle):";

            try
            {
                figure[0] = new Triangle(0, 0, 30, 0, 40, 0);
                cout << figure[0]->String() << endl;
                cout << "\nSquare: ";
                cout << figure[0]->calc_square();

                cout << "\n\nFigure #2 (circle):";
                figure[1] = new Circle(0, 0, 0, 20);
                cout << figure[1]->String() << endl;
                cout << "\nSquare: ";
                cout << figure[1]->calc_square();

                cout << "\n\nFigure #3 (ellipse):";
                figure[2] = new Ellipse(0, 0, 50, -30, 30, -20, 0, 0);
                cout << figure[2]->String() << endl;
                cout << "\nSquare: ";
                cout << figure[2]->calc_square();

                cout << "\n\nFigure #4 (rectangle):";
                figure[3] = new Rectangle(0, 0, 0, 50, 40, 40, 50, 0);
                cout << figure[3]->String() << endl;
                cout << "\nSquare: ";
                cout << figure[3]->calc_square();

                cout << "\n\nFigure #5 (square):";
                figure[4] = new Square(0, 0, 0, 50, 50, 50, 50, 0);
                cout << figure[4]->String() << endl;;
                cout << "\nSquare: ";
                cout << figure[4]->calc_square();
            }
            catch (Exception Exception) 
            {
                Exception.error();
                exit(1);
            }

            delete figure[0];
            delete figure[1];
            delete figure[2];
            delete figure[3];
            delete figure[4];
            delete[] figure;
            cout << endl;
        }
        break;
        case 2:
        {
            int b;
            do
            {
                cout << "Введите номер фигуры, которую хотите переместить 1-5 (введите '0' для выхода)" << endl;
                cin >> b;

                try
                {
                    if ((b > 5 or b < 1) and b != 0) throw "Неверрно введён номер фигуры";
                }
                catch (const char* exception)
                {
                    cout << "Ошибка: " << exception << endl;
                    cin >> b;
                }

                switch (b)
                {
                case 1:
                {
                    double x, y;
                    cout << "Введите координаты, x и y" << endl;
                    cin >> x;
                    cin >> y;
                    Figure** figure = new Figure * [1];
                    cout << "\nFigure #1 (triangle):";

                    try
                    {
                        figure[0] = new Triangle(0, 0, 30, 0, 40, 0);
                    }
                    catch (Exception Exception) 
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Move(x, y);
                    cout << figure[0]->String();
                    cout << endl;
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 2:
                {
                    double x, y;
                    cout << "Введите координаты, x и y" << endl;
                    cin >> x;
                    cin >> y;
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #2 (circle):";

                    try
                    {
                        figure[0] = new Circle(0, 0, 0, 20);
                    }
                    catch (Exception Exception) 
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Move(x, y);
                    cout << figure[0]->String();
                    cout << endl;
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 3:
                {
                    double x, y;
                    cout << "Введите координаты, x и y" << endl;
                    cin >> x;
                    cin >> y;
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #3 (ellipse):";

                    try
                    {
                        figure[0] = new Ellipse(0, 0, 50, -30, 30, -20, 0, 0);
                    }
                    catch (Exception Exception) 
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Move(x, y);
                    cout << figure[0]->String();
                    cout << endl;
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 4:
                {
                    double x, y;
                    cout << "Введите координаты, x и y" << endl;
                    cin >> x;
                    cin >> y;
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #4 (rectangle):";

                    try
                    {
                        figure[0] = new Rectangle(0, 0, 0, 50, 40, 40, 50, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Move(x, y);
                    cout << figure[0]->String();
                    cout << endl;
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 5:
                {
                    double x, y;
                    cout << "Введите координаты, x и y" << endl;
                    cin >> x;
                    cin >> y;
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #5 (square):";

                    try
                    {
                        figure[0] = new Square(0, 0, 0, 50, 50, 50, 50, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Move(x, y);
                    cout << figure[0]->String();
                    cout << endl;
                    delete figure[0];
                    delete[] figure;
                }
                break;
                }
            } while (b != 0);
        }
        break;
        case 3:
        {
            Prism<Figure>** prism = new Prism<Figure> * [5];
            Figure** figure = new Figure * [5];
            cout << "\nFigure #1 (triangle):";

            try
            {
                figure[0] = new Triangle(0, 0, 30, 0, 40, 0);
                prism[0] = new Prism<Figure>(5, figure[0]);
                cout << figure[0]->String();
                cout << "\nVolume: ";
                cout << prism[0]->Calc_Volume();


                cout << "\n\nFigure #2 (circle):";
                figure[1] = new Circle(0, 0, 0, 20);
                prism[1] = new Prism<Figure>(5, figure[1]);
                cout << figure[1]->String();
                cout << "\nVolume: ";
                cout << prism[1]->Calc_Volume();


                cout << "\n\nFigure #3 (ellipse):";
                figure[2] = new Ellipse(0, 0, 50, -30, 30, -20, 0, 0);
                prism[2] = new Prism<Figure>(5, figure[2]);
                cout << figure[2]->String();
                cout << "\nVolume: ";
                cout << prism[2]->Calc_Volume();


                cout << "\n\nFigure #4 (rectangle):";
                figure[3] = new Rectangle(0, 0, 0, 50, 40, 40, 50, 0);
                prism[3] = new Prism<Figure>(5, figure[3]);
                cout << figure[3]->String();
                cout << "\nVolume: ";
                cout << prism[3]->Calc_Volume();


                cout << "\n\nFigure #5 (square):";
                figure[4] = new Square(0, 0, 0, 50, 50, 50, 50, 0);
                prism[4] = new Prism<Figure>(5, figure[4]);
            }
            catch (Exception Exception)
            {
                Exception.error();
                exit(1);
            }
            cout << figure[4]->String();
            cout << "\nVolume: ";
            cout << prism[4]->Calc_Volume();

            delete figure[0];
            delete figure[1];
            delete figure[2];
            delete figure[3];
            delete figure[4];
            delete[] figure;

            delete prism[0];
            delete prism[1];
            delete prism[2];
            delete prism[3];
            delete prism[4];
            delete[] prism;

            cout << endl;
        }
        break;
        case 4:
        {
            int с;
            do
            {
                cout << "Введите номер фигуры, которую хотите нарисовать 1-5 (введите '0' для выхода)" << endl;
                cin >> с;

                try
                {
                    if ((с > 5 or с < 1) and с != 0) throw "Неверрно введён номер фигуры";
                }
                catch (const char* exception)
                {
                    cout << "Ошибка: " << exception << endl;
                    cin >> с;
                }

                switch (с)
                {
                case 1:
                {
                    
                    Figure** figure = new Figure * [1];
                    cout << "\nFigure #1 (triangle):";

                    try
                    {
                        figure[0] = new Triangle(0, 0, 30, 0, 40, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Draw();
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 2:
                {
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #2 (circle):";

                    try
                    {
                        figure[0] = new Circle(0, 0, 0, 20);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Draw();
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 3:
                {
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #3 (ellipse):";

                    try
                    {
                        figure[0] = new Ellipse(0, 0, 50, -30, 30, -20, 0, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Draw();
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 4:
                {
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #4 (rectangle):";

                    try
                    {
                        figure[0] = new Rectangle(0, 0, 0, 50, 40, 40, 50, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Draw();
                    delete figure[0];
                    delete[] figure;
                }
                break;
                case 5:
                {
                    Figure** figure = new Figure * [1];
                    cout << "\n\nFigure #5 (square):";

                    try
                    {
                        figure[0] = new Square(0, 0, 0, 50, 50, 50, 50, 0);
                    }
                    catch (Exception Exception)
                    {
                        Exception.error();
                        exit(1);
                    }

                    cout << figure[0]->String();
                    cout << endl;
                    figure[0]->Draw();
                    delete figure[0];
                    delete[] figure;
                }
                break;
                }
            } while (с != 0);
        }
        break;
        }
    } while (a != 0);
    return 0;
}