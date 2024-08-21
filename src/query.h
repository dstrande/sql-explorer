#ifndef QUERY_H
#define QUERY_H

#include <QObject>

class Query : public QObject
{
    Q_OBJECT

public:
    QString query() const {return queryText;}
 
private:
    QString queryText="SELECT * FROM language\nLIMIT 10;";
};

#endif // PERSON_H
