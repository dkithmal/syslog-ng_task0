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


#ifndef YAMLPARSER_H
#define YAMLPARSER_H

#include <QObject>
#include "mainwindow.h"

class YamlParser : public QObject
{
    Q_OBJECT
public:
    explicit YamlParser(QObject *parent = 0);
     void Init();


protected:
    MainWindow* mainWindow;


private:
    void LoadStyleSheet();

    
};

#endif // YAMLPARSER_H
