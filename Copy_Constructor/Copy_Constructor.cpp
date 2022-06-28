#include <iostream>
using namespace std;

class  dot {
private:
    int x;
    int y;

public:
    const int t; //sınıfların sabit (const )
    int* z; //pointer z
    dot(); //prototip //fonksiyon
    dot(int, int, int);
    dot(const dot& n );
    ~dot(); //yapıcı fonk kendisi olabilir

    int getX() const ;
    int getY() const ;

    void setX(int);
    void setY(int);

    void WriteToScreen();
    bool beginning();


};

dot::dot() : t(0) {
    //t= 0 hatalı bir kullanım 
     //başlangıç değerleri daima 0 dır  parametresizdir
    cout << "parameterless constructor " << x << " " << endl;
    x = 0;
    y = 0;
    z = new int(5);
}
dot::dot(int x, int y = 8, int t = 0) : t(t) { //y= 8 varsayılan değer//

    this->x = x;// bu sınıfta üretilen x değeri olarak ata 
    this->y = y;
    // this->t = t; hatalı kullanım  constlarda int verilerinde yaptığımız gibi yapmıyoruz
    cout << "parameter constructor " << x << " " << y << endl;
    //z = new int(6);


}
dot::dot(const dot& n) :t(n.t) {
    x = n.x;
    y = n.y;
    z = new int(*n.z);
    cout << "Copy Constructor" <<x<<" "<<y<< endl;

}
dot::~dot() {
    cout << "destructor " << x << " " << y << endl;
    delete z; //sistemden kaldırma z yoluyla
}

void dot::setX(int x) {
    //  x = _x; b şekilde de olabilir aslında
      //thisi işaretçi diyebiliriz
      //thisbir anahtar kelime dersek this.x diyemeyiz

    this->x = x;



}
void dot::setY(int _y) {
    if (_y > 5)
        y = _y;
    else
        y = 2;
}
void dot::WriteToScreen() {
    cout << x << "," << y << endl;

}
bool dot::beginning() {
    return x == 0 && y == 0;


}



int main()
{
    dot n1(1, 10, 10);

    return 0;
}
