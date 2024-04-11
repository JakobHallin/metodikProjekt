#ifndef API_H
#define API_H
#include <QString>
class Api{
private:
    QString key = ("87dc9fae84c01694a27ab719891dce48");
    //private $price;

public:
    //double getPrice(QString shortName);
    int  getPrice(QString shortName);
};
#endif // API_H
