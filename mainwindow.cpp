#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFile file("Style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);


    ui->setupUi(this);

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(actionNewTriggered()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(close()));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::actionNewTriggered()
{
    QString yamlFilePath =QFileDialog::getOpenFileName(this,tr("Open yaml File"), "");
    ui->lYamlFilePath->setText(yamlFilePath);


    yamlFileParser();

}



void MainWindow::yamlFileParser()
{
    yamlDocument.clear();

    QFile yamlFile(ui->lYamlFilePath->text());
    yamlFile.open(QIODevice::ReadOnly);

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
              QString aaa=list.at(index);
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





//    QFile file("yaml.xml");
//    file.open(QIODevice::WriteOnly);
//    QTextStream stream(&file);
//    stream <<yamlDocument.toString();
//    file.close();


    buildTreeModel();

}

void MainWindow::buildTreeModel()
{
    while (ui->tWShapes->topLevelItemCount() > 0)
    {
        ui->tWShapes->takeTopLevelItem(0);
    }


    QDomElement root = yamlDocument.firstChildElement();

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



    QDomElement root = yamlDocument.firstChildElement();
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















