#ifndef FILES_H
#define FILES_H

#include <QObject>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QXmlStreamWriter>
#include <QtXml/QDomElement>
#include <QtXml/qdom.h>

#include "items/target.h"
#include "items/position.h"

#include <QDebug>

class Files
{
public:
    Files();
    void xml_writer(QString fileName);
    Target *xml_reader(QString fileName);
    void position_writer();
    void position_reader();
};

#endif // FILES_H
