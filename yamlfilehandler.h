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

#ifndef YAMLFILEHANDLER_H
#define YAMLFILEHANDLER_H

#include <QObject>
#include <QString>
#include <QDomDocument>
#include <QFile>
#include <QStringList>
#include <QTextStream>
class YamlFileHandler : public QObject
{
    Q_OBJECT
public:
    explicit YamlFileHandler(QString path,QObject *parent = 0);
    void Init();
    QDomDocument getYamlDocument();
    QDomDocument yamlDocument;


private:
    void ParseYamlFile();
    QString yamlFilePath;

    
};

#endif // YAMLFILEHANDLER_H
