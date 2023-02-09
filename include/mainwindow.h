#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsBlurEffect>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
