#ifndef ENCODINGS_H
#define ENCODINGS_H

#include <QDataStream>

class Encodings
{
public:
    Encodings(QDataStream*);
    void universalEncoding(char, int, int);
private:
    QDataStream* output;
};

#endif // ENCODINGS_H
