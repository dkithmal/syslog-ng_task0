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



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QTreeWidgetItem>
#include "yamlfilehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Init();
    
private:
    Ui::MainWindow *ui;
    void buildTreeModel();
    YamlFileHandler* yamlHandler;


private slots:
    void actionNewTriggered();
    void shapesTreeModelItemClicked(QTreeWidgetItem* qTreeWidgetItem,int index);
};

#endif // MAINWINDOW_H
