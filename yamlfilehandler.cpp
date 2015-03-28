/*
    Copyright (C) 2015 by Damitha Kithmal <dkithmalfit@gmail.com>
    This file is part of GSOC 2015 syslog-ng task0

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the COPYING file for more details.
*/

#include "yamlfilehandler.h"

YamlFileHandler::YamlFileHandler(QString path,QObject *parent) :
    QObject(parent)
{
    yamlFilePath=path;
}

void YamlFileHandler::Init()
{
    ParseYamlFile();

}

void YamlFileHandler::ParseYamlFile()
{
    yamlDocument.clear();

    QFile yamlFile(yamlFilePath);
    if(yamlFile.open(QIODevice::ReadOnly))
    {
        QStringList list;


        QTextStream yamlFileTextStream(&yamlFile);
        while(!yamlFileTextStream.atEnd())
        {
            list.append(yamlFileTextStream.readLine());

        }

        yamlFile.close();


        QDomElement root = yamlDocument.createElement("Shapes");

        int index=0;

        while(index<list.size())
        {

            QDomElement element= yamlDocument.createElement(list.at(index).split(':').at(0));
            element.setAttribute("name",list.at(index).split(':').at(1));

            index=index+2;

            while(true)
            {

              if((index+1)==list.size())
              {
                  QDomElement childElement=yamlDocument.createElement(list.at(index).split(':').at(0));
                  childElement.setAttribute("value",list.at(index).split(':').at(1));

                  element.appendChild(childElement);
                  index++;
                  break;
              }
              else if (list.at(index+1)!="properties:")
              {
                  QDomElement childElement=yamlDocument.createElement(list.at(index).split(':').at(0));
                  childElement.setAttribute("value",list.at(index).split(':').at(1));

                  element.appendChild(childElement);
                  index++;

              }
              else
              {
                 break;
              }


            }

             root.appendChild(element);


        }


        yamlDocument.appendChild(root);

    }


//    QFile file("yaml.xml");
//    file.open(QIODevice::WriteOnly);
//    QTextStream stream(&file);
//    stream <<yamlDocument.toString();
//    file.close();

}



QDomDocument YamlFileHandler::getYamlDocument()
{
    return this->yamlDocument;
}
