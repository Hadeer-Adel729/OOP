/*
Name: Marwa Shaban Eid           ID: 20200516
Name: Hadeer Adel Mahmoud        ID: 20201210
Section: S(31)
*/


#include <iostream>
#include <windows.h>


using namespace std;

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}


class ColoredBox
{

private:
    int length ;
    int width;
    int color;
    char character;
    char** arr = new char*[length];
    char** transpose = new char*[length];
    static int MaxArea;
    int Area;

public:

    ColoredBox(int len, int wid)
    {

        length = len;
        width = wid;
        color = 15;
        character = '#';
        MaxArea = length * width;

    }
    ColoredBox(int len, int wid, int col, char chara)
    {
        length = len;
        width = wid;
        color = col;
        character = chara;
    }

    void setlength(int length)
    {
        this->length = length;
    }

    void setwidth(int width)
    {
        this->width = width;
    }

    void setColor(int color)
    {
        this->color = color;
    }

    void setcharacter(char character)
    {
        this->character = character;
    }

    int getcolor()
    {
        return color;
    }

    char getcharacter()
    {
        return character;
    }
//Function getArea to calculate the area
    int getArea()
    {
        Area = length * width;
        return Area;
    }
// Function display that prints the box (2D Dynamic array)

    void display()
    {

        for(int i = 0; i < length; ++i)
            arr[i] = new char[width];


        for(int i = 0; i < length; ++i)
            for(int j = 0; j < width; ++j)
                arr[i][j] = character;

        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                cout << arr[i][j] ;
            }
            cout << endl;
        }

    }

//Function displayTransposed displays the box transposed

    void displayTransposed()
    {

        for(int i = 0; i < width; ++i)
            transpose[i] = new char[length];


        for(int i = 0; i < width; ++i)
            for(int j = 0; j < length; ++j)
                transpose[i][j] = arr[j][i];

        for(int i = 0; i < width; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                cout << transpose[i][j];
            }
            cout << endl;
        }

    }

// Function displayWider that displays the box on a wider scale

    void displayWider()
    {
        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < width; ++j)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

//Function displayChess that displays the box as a chess board

    void displayChess(int color2)
    {

        for(int i = 0; i<length; ++i)
        {
            for(int j = 0; j<width; ++j)
            {
                if (i%2 != j%2)
                {
                    SetColor(color2);
                    cout << arr[i][j] ;
                }
                else if(i%2 == j%2)
                {
                    SetColor(color);
                    cout << arr[i][j];
                }
            }
            cout << endl;
        }
        SetColor(15);
    }

//Function getMaxArea that returns the maximum (Length * width)

    int getMaxArea()
    {
        if (MaxArea > Area)
            return MaxArea;
        else
            return Area;
    }


//Destructor to deallocate memory

    ~ColoredBox()
    {

        for(int i = 0; i < length; ++i)
            delete [] arr[i];
        delete [] arr;


        for (int i=0; i<length; i++)
            delete [] transpose[i];
        delete [] transpose;
    }

};

int ColoredBox::MaxArea = 0;

int main()
{
    int len,wid,col,col2;
    char boxChar;
    cout<<"Enter length and width of the box separated by a space: ";
    cin>>len>>wid;
    cout << endl;
    ColoredBox* cb1;
    cb1 = new ColoredBox(len,wid);
    cb1->display();
    SetColor(15);
    cout << endl;
    cout<<"Set the box to another color: ";
    cin>>col;
    cb1->setColor(col);
    SetColor(15);
    cout << endl;
    cout<<"Displaying Transposed: "<<endl;
    SetColor(col);
    cb1->displayTransposed();
    SetColor(15);
    cout<<"Displaying Wider: "<<endl;
    SetColor(col);
    cb1->displayWider();
    SetColor(15);
    cout<<"Displaying Chess, enter the other color: "<<endl;
    cin>>col2;
    cb1->displayChess(col2);
    cout<<endl<<"Area = "<<cb1->getArea();
    cout<<endl<<"Max Area = "<<cb1->getMaxArea();
    delete cb1;



    SetColor(15);
    cout<<endl << endl<<"Enter length,width,color,character of the box separated by spaces: ";
    cin>>len>>wid>>col>>boxChar;
    ColoredBox* cb2;
    SetColor(col);
    cb2 = new ColoredBox(len,wid,col,boxChar);
    cb2->display();
    SetColor(15);
    cout<<"Displaying Transposed: "<<endl;
    SetColor(col);
    cb2->displayTransposed();
    SetColor(15);
    cout<<"Displaying Wider: "<<endl;
    SetColor(col);
    cb2->displayWider();
    SetColor(15);
    cout<<"Displaying Chess, enter the other color: "<<endl;
    SetColor(15);
    cin>>col2;
    SetColor(col);
    cb2->displayChess(col2);
    SetColor(15);
    cout<<"Displaying original again:"<<endl;
    SetColor(col);
    cb2->display();
    SetColor(15);
    cout<<endl<<"Area = "<<cb2->getArea();
    cout<<endl<<"Max Area = "<<cb2->getMaxArea();
    delete cb2;



    return 0;
}
