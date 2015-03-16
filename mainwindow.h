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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QDomDocument yamlDocument;
    void yamlFileParser();
    void buildTreeModel();


private slots:
    void actionNewTriggered();
    void shapesTreeModelItemClicked(QTreeWidgetItem* qTreeWidgetItem,int index);
};

#endif // MAINWINDOW_H
