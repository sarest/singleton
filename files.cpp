#include "files.h"
#include "mediator.h"

Files::Files()
{

}

void Files::xml_writer(QString fileName)
{
    qDebug()<<"xml_writer";
    Mediator *mediator = Mediator::Instance();
    Target *mytarget = mediator->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("target");
    xmlWriter.writeAttribute("id",mytarget->getID());
    if(!segment_list.isEmpty()){
        xmlWriter.writeStartElement("segments");
        for(int i=0; i<segment_list.count(); i++){
            xmlWriter.writeStartElement("segment");
            xmlWriter.writeAttribute("type",segment_list.at(i)->getType());
            xmlWriter.writeStartElement("parameters");
            if(segment_list.at(i)->getType()=="curve"){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","angle");
                xmlWriter.writeCharacters(segment_list.at(i)->getAngle());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","radius");
                xmlWriter.writeCharacters(segment_list.at(i)->getRadius());
                xmlWriter.writeEndElement();
                if(segment_list.at(i)->getVelocity_curve()!=""){
                    xmlWriter.writeStartElement("parameter");
                    xmlWriter.writeAttribute("id","velocity");
                    xmlWriter.writeCharacters(segment_list.at(i)->getVelocity_curve());
                    xmlWriter.writeEndElement();
                }
                else{
                    xmlWriter.writeStartElement("parameter");
                    xmlWriter.writeAttribute("id","acceleration");
                    xmlWriter.writeCharacters(segment_list.at(i)->getAcceleration_curve());
                    xmlWriter.writeEndElement();
                }
            }
            else if(segment_list.at(i)->getType()=="straight"){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","length");
                xmlWriter.writeCharacters(segment_list.at(i)->getLength());
                xmlWriter.writeEndElement();
                if(segment_list.at(i)->getVelocity_straight()!=""){
                    xmlWriter.writeStartElement("parameter");
                    xmlWriter.writeAttribute("id","velocity");
                    xmlWriter.writeCharacters(segment_list.at(i)->getVelocity_straight());
                    xmlWriter.writeEndElement();
                }
                else{
                    xmlWriter.writeStartElement("parameter");
                    xmlWriter.writeAttribute("id","acceleration");
                    xmlWriter.writeCharacters(segment_list.at(i)->getAcceleration_straight());
                    xmlWriter.writeEndElement();
                }
            }
            xmlWriter.writeEndElement(); //end of parameters
            xmlWriter.writeEndElement(); //end of segment
        }
        xmlWriter.writeEndElement(); //end of segments
    }
    else{
        qDebug()<<"no segments in list";
    }
    xmlWriter.writeEndElement(); // end of target
    xmlWriter.writeEndDocument();
}

Target *Files::xml_reader(QString fileName)
{
    qDebug()<<"xml_reader";
    Target *mytarget = new Target;

    QFile file(fileName);
    file.open(QFile::ReadOnly);

    QDomDocument doc("mydocument");
    doc.setContent(&file);
    QDomElement docElem = doc.documentElement();

    mytarget->setID(docElem.attributes().namedItem("id").nodeValue());


    QDomNodeList segment_nodelist = docElem.elementsByTagName("segment");
    if(segment_nodelist.count()>0){
        for(int i=0; i<segment_nodelist.count();i++){
            Segment *mysegment = new Segment;
            QString length="",angle="",radius="",acceleration="",velocity="";
            QDomNodeList segment_parameters = segment_nodelist.at(i).firstChild().childNodes();
            for(int j=0; j<segment_parameters.count(); j++){
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="length")
                    length = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="angle")
                    angle = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="radius")
                    radius = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="acceleration")
                    acceleration = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="velocity")
                    velocity = segment_parameters.at(j).toElement().text();
            }
            if(segment_nodelist.at(i).attributes().namedItem("type").nodeValue()=="curve")
                mysegment->setValues_curve("curve",angle,radius,acceleration,velocity);
            else
                mysegment->setValues_straight("straight",length,acceleration,velocity);

            mytarget->addSegment(mysegment);
        }
    }
    file.close();
    return mytarget;
}
