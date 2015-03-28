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


#include "yamlparser.h"

YamlParser::YamlParser(QObject *parent) :
    QObject(parent)
{
}

void YamlParser::Init()
{
    mainWindow=new MainWindow();

    LoadStyleSheet();

    mainWindow->Init();
    mainWindow->show();

}


void YamlParser::LoadStyleSheet()
{
    QFile stylesheet("Style.qss");
    if (stylesheet.exists())
    {
       if (stylesheet.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           QString styleSheet = QLatin1String(stylesheet.readAll());
           stylesheet.close();
           mainWindow->setStyleSheet(styleSheet);
       }

    }


}
