#ifndef FILES_H
#define FILES_H

#include <QObject>
#include <QFile>
#include <QtXml/QDomDocument>
#include <QXmlStreamWriter>
#include <QtXml/QDomElement>
#include <QtXml/qdom.h>

#include "items/target.h"

#include <QDebug>

class Files
{
public:
    Files();
    void xml_writer(QString fileName);
    Target *xml_reader(QString fileName);
};

#endif // FILES_H
