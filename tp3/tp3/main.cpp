#include <iostream>
#include <fstream>
#include "figure.hpp"
#include "rectangle.hpp"
#include "Circle.hpp"
#include "triangle.hpp"
#include "trapezoid.hpp"
#include "funcs.hpp"

using namespace std;

// Вариант 1. Создать абстрактный базовый класс с виртуальной функцией «Площадь». Создать производные классы «Прямоугольник», «Круг», «Прямоугольный треугольник», «Трапеция» со своими функциями площади и переменными. Для проверки определить массив ссылок на абстрактный класс, которым присваиваются адреса различных объектов.
int Figure::counter = 0;

int main ( void ) {
    int cnt = 0;
    int claro;
    int type;
    Figure** ARR = 0;
    cout << "Where do you want to get data from?\n 1 - From file\n 2 - Using keyboard\n 0 - Exit" << endl;
    cin >> claro;
    switch(claro){
        case 1:{
            string path = "data.txt";
            ifstream source_tr;
            source_tr.open(path);
            if (!source_tr.is_open())
            {
                cout << "File was not opened." << endl;
            }
            source_tr >> cnt;
            if ( cnt == 0) {
                cout << "File is empty." << endl;
                break;
            }
            ARR = new Figure*[cnt];
            float a,b,c;
            for (int i = 0; i < cnt; i ++){
                source_tr >> type;
                switch (type) {
                    case 1:{
                        source_tr >> a >> b;
                        ARR[i] = new Rectangle(a, b);
                        break;
                    }
                    case 2:{
                        source_tr >> a;
                        ARR[i] = new Circle(a);
                        break;
                    }
                    case 3:{
                        source_tr >> a >> b;
                        ARR[i] = new Triangle(a, b);
                        break;
                    }
                    case 4:{
                        source_tr >> a >> b >> c;
                        ARR[i] = new Trapezoid(a, b, c);
                        break;
                    }
                    default:break;
                }
               
            }
            source_tr.close();
            break;
        }
        case 2:{
            cout << "How many elements you want to add?" << endl;
            cin >> cnt;
            ARR = new Figure*[cnt];
            float a,b,c;
            for (int i = 0; i < cnt; i++ ){
                cout << "Which figure do you want to add?\n 1 - Rectangle\n 2 - Circle\n 3 - Right Triangle\n 4 - Trapezoid" << endl;
                cin >> type;
                switch(type){
                    case 1:{
                        cout << "Enter width and height: " << endl;
                        cin >> a >> b;
                        ARR[i] = new Rectangle(a, b);
                        break;
                    }
                    case 2:{
                        cout << "Enter radius: " << endl;
                        cin >> a;
                        ARR[i] = new Circle(a);
                        break;
                    }
                    case 3:{
                        cout << "Enter cathetuses: " << endl;
                        cin >> a >> b;
                        ARR[i] = new Triangle(a, b);
                        break;
                    }
                    case 4:{
                        cout << "Enter two bases and height: " << endl;
                        cin >> a >> b >> c;
                        ARR[i] = new Trapezoid(a, b ,c);
                        break;
                    }
                    default:break;
                }
            }
            break;
        }
        case 0: return 0;
    }
    cout << "This is what I got: " << endl;
    cout << "The number of figures: " << Figure::counter << endl;
    
    int flag = 1;
    while (flag == 1){
        showall(ARR, cnt);
        cout << "Choose the operation: \n 1 - Add element\n 2 - Delete element\n 3 - Edit element\n 0 - Exit" << endl;
        cin >> claro;
        
        switch(claro){
            case 1:{
                cout << "Which figure do you want to add?\n 1 - Rectangle\n 2 - Circle\n 3 - Right Triangle\n 4 - Trapezoid" << endl;
                cin >> type;
                float a,b,c;
                switch(type){
                    case 1:{
                        cout << "Enter width and height: " << endl;
                        cin >> a >> b;
                        add(ARR, cnt, a, b);
                        cnt++;
                        break;
                    }
                    case 2:{
                        cout << "Enter radius: " << endl;
                        cin >> a;
                        add(ARR, cnt, a);
                        cnt++;
                        break;
                    }
                    case 3:{
                        cout << "Enter cathetuses: " << endl;
                        cin >> a >> b;
                        addtr(ARR, cnt, a, b);
                        cnt++;
                        break;
                    }
                    case 4:{
                        cout << "Enter two bases and height: " << endl;
                        cin >> a >> b >> c;
                        add(ARR, cnt, a, b, c);
                        cnt++;
                        break;
                    }
                    default:break;
                }
                break;
            }
            case 2:{
                cout << "Enter the number of element you want to delete: " << endl;
                cin >> type;
                del(ARR, cnt, type-1);
                cnt--;
                Figure::counter--;
                break;
            }
            case 3:{
                cout << "Enter the number of element you want to edit: " << endl;
                cin >> type;
                swap(ARR, cnt, type - 1);
                break;
            }
            case 0:{
                flag = 0;
                break;
            }
            default:{
                flag = 0;
                break;
            }
        }
    }
    
    cout << "Do you want to write down new data to the file?\n 1 - Yes. Rewrite data.\n 2 - No. Leave it as it were." << endl;
    cin >> type;
    if (type == 1){
        ofstream path_out;
        path_out.open("data.txt");
        if (path_out.is_open())
        {
            path_out << Figure::counter << " ";
            for (int i = 0; i < Figure::counter; i++)
            {
                path_out << ARR[i]->getid() << " ";
                ARR[i]->fprint(path_out);
            }
        }
        path_out.close();
    }
    return 0;
}
