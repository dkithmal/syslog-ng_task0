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


#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::Init()
{
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(actionNewTriggered()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));

}


void MainWindow::actionNewTriggered()
{
    QString yamlFilePath =QFileDialog::getOpenFileName(this,tr("Open yaml File"), "");
    ui->lYamlFilePath->setText(yamlFilePath);

    yamlHandler= new YamlFileHandler(yamlFilePath,this);
    yamlHandler->Init();

    buildTreeModel();


}


void MainWindow::buildTreeModel()
{
    while (ui->tWShapes->topLevelItemCount() > 0)
    {
        ui->tWShapes->takeTopLevelItem(0);
    }


    QDomElement root =yamlHandler->getYamlDocument().firstChildElement();

    QDomNodeList nodeList=root.childNodes();

    for(int x=0; x<nodeList.count();x++)
    {
        if((ui->tWShapes->findItems(nodeList.at(x).nodeName(),Qt::MatchStartsWith)).isEmpty())
        {
            QTreeWidgetItem *item = new QTreeWidgetItem( ui->tWShapes);
            item->setText(0,nodeList.at(x).nodeName());

            QTreeWidgetItem *subItem =new QTreeWidgetItem(item);
            subItem->setText(0,nodeList.at(x).toElement().attribute("name"));

        }
        else
        {
            QTreeWidgetItem *subItem =new QTreeWidgetItem(ui->tWShapes->findItems(nodeList.at(x).nodeName(),Qt::MatchStartsWith).at(0));
            subItem->setText(0,nodeList.at(x).toElement().attribute("name"));

        }

    }

}


void MainWindow::shapesTreeModelItemClicked(QTreeWidgetItem* qTreeWidgetItem,int index)
{
    while (ui->tWProperties->rowCount() > 0)
    {
        ui->tWProperties->removeRow(0);
    }



    QDomElement root = yamlHandler->getYamlDocument().firstChildElement();
    QDomNodeList nodeList=root.childNodes();


    if ( qTreeWidgetItem->parent() != NULL ) {

        for(int x=0; x<nodeList.count();x++)
        {
            if(nodeList.at(x).nodeName()==qTreeWidgetItem->parent()->text(0))
            {
                if(nodeList.at(x).toElement().attribute("name")==qTreeWidgetItem->text(0))
                {
                     QDomNodeList subNodeList=nodeList.at(x).toElement().childNodes();

                     for(int y=0;y<subNodeList.size();y++)
                     {
                         ui->tWProperties->insertRow(ui->tWProperties->rowCount());
                         ui->tWProperties->setItem(y,0, new QTableWidgetItem(subNodeList.at(y).nodeName()));
                         ui->tWProperties->setItem(y,1, new QTableWidgetItem(subNodeList.at(y).toElement().attribute("value")));
                     }

                    break;
                }
            }

        }
    }

}















