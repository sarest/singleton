#include "files.h"
#include "mediator.h"

Files::Files()
{

}

void Files::xml_writer(QString fileName)
{
    qDebug()<<"xml_writer";
    Target *mytarget = Mediator::Instance()->getTarget();
    QList<Segment*> segment_list = mytarget->getSegment();

    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("target");
    xmlWriter.writeAttribute("id",mytarget->getID());
    xmlWriter.writeAttribute("start_velocity",mytarget->getStartVelocity());
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
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","x");
                xmlWriter.writeCharacters(segment_list.at(i)->getX_curve());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","y");
                xmlWriter.writeCharacters(segment_list.at(i)->getY_curve());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","time");
                xmlWriter.writeCharacters(segment_list.at(i)->getTime_curve());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","velocity");
                xmlWriter.writeCharacters(segment_list.at(i)->getVelocity_curve());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","acceleration");
                xmlWriter.writeCharacters(segment_list.at(i)->getAcceleration_curve());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","out_angle");
                xmlWriter.writeCharacters(segment_list.at(i)->getOutAngle_curve());
                xmlWriter.writeEndElement();
            }
            else if(segment_list.at(i)->getType()=="straight"){
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","length");
                xmlWriter.writeCharacters(segment_list.at(i)->getLength());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","x");
                xmlWriter.writeCharacters(segment_list.at(i)->getX_straight());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","y");
                xmlWriter.writeCharacters(segment_list.at(i)->getY_straight());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","time");
                xmlWriter.writeCharacters(segment_list.at(i)->getTime_straight());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","velocity");
                xmlWriter.writeCharacters(segment_list.at(i)->getVelocity_straight());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","acceleration");
                xmlWriter.writeCharacters(segment_list.at(i)->getAcceleration_straight());
                xmlWriter.writeEndElement();
                xmlWriter.writeStartElement("parameter");
                xmlWriter.writeAttribute("id","out_angle");
                xmlWriter.writeCharacters(segment_list.at(i)->getAngle_straight());
                xmlWriter.writeEndElement();
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
    mytarget->setStartVelocity(docElem.attributes().namedItem("start_velocity").nodeValue());

    QDomNodeList segment_nodelist = docElem.elementsByTagName("segment");
    if(segment_nodelist.count()>0){
        for(int i=0; i<segment_nodelist.count();i++){
            Segment *mysegment = new Segment;
            QString length="",angle="",radius="",acceleration="",velocity="",x="",y="",time="",out_angle="";
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
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="x")
                    x = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="y")
                    y = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="time")
                    time = segment_parameters.at(j).toElement().text();
                if(segment_parameters.at(j).attributes().namedItem("id").nodeValue()=="out_angle")
                    out_angle = segment_parameters.at(j).toElement().text();
            }
            if(segment_nodelist.at(i).attributes().namedItem("type").nodeValue()=="curve"){
                mysegment->setValues_curve("curve",angle,radius,acceleration,velocity,x,y,time);
                mysegment->setOutAngle_curve(out_angle);
            }
            else{
                mysegment->setValues_straight("straight",length,acceleration,velocity,x,y,time);
                mysegment->setAngle_straight(out_angle);
            }

            mytarget->addSegment(mysegment);
        }
    }
    file.close();
    return mytarget;
}

void Files::position_writer()
{
    QList<Position*> mylist = Mediator::Instance()->getPositions();
    QFile file("/home/antgon/proyects_interface/interface_singleton/positions.xml");
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("positions");
    for(int i=0; i<mylist.count(); i++){
        xmlWriter.writeStartElement("position");
        xmlWriter.writeAttribute("name",mylist.at(i)->getName());
        xmlWriter.writeAttribute("longitude",mylist.at(i)->getLongitude());
        xmlWriter.writeAttribute("latitude",mylist.at(i)->getLatitude());
        xmlWriter.writeAttribute("direction",mylist.at(i)->getDirection());
        xmlWriter.writeAttribute("height",mylist.at(i)->getHeight());
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    xmlWriter.writeEndDocument();
}

void Files::position_reader()
{
    QFile file("/home/antgon/proyects_interface/interface_singleton/positions.xml");
    file.open(QFile::ReadOnly);
    QDomDocument doc("mydocument");
    doc.setContent(&file);
    QDomElement docElem = doc.documentElement();
    QDomNodeList positions_nodelist = docElem.elementsByTagName("position");
    if(positions_nodelist.count()>0){
        for(int i=0; i<positions_nodelist.count(); i++){
            Position *myposition = new Position;
            myposition->setPosition(positions_nodelist.at(i).attributes().namedItem("name").nodeValue(),positions_nodelist.at(i).attributes().namedItem("longitude").nodeValue(),
                                    positions_nodelist.at(i).attributes().namedItem("latitude").nodeValue(),positions_nodelist.at(i).attributes().namedItem("direction").nodeValue(),
                                    positions_nodelist.at(i).attributes().namedItem("height").nodeValue());
            Mediator::Instance()->addPosition(myposition);
        }
    }

}

