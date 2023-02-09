#include "mainwindow.h"
#include "qboxlayout.h"
#include "qpainter.h"


QImage blurImage(QImage source, int deep){
    if(source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(deep);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0,0,source.width(), source.height()));
    return result;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget w;
    QVBoxLayout layout(&w);
    auto *button = new QPushButton("Open", &w);
    auto *slider = new QSlider(&w);
    auto *label = new QLabel();

    slider->setOrientation(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(8);

    layout.addWidget(label);
    layout.addWidget(slider);
    layout.addWidget(button);


    QString filename;

    QObject::connect(button, &QPushButton::clicked, [&filename, &label]{
        filename = QFileDialog::getOpenFileName(nullptr, "open img", "./C", "Images (*.png *.xpm *.jpg)");
        QPixmap img(filename);
        label->setPixmap(img);
    });

    QObject::connect(slider, &QSlider::valueChanged, [&label, &filename, &slider]{
        QImage img(filename);
        label->setPixmap(QPixmap::fromImage(blurImage(img, slider->value()).scaled(
                                            label->width(),
                                            label->height(), Qt::KeepAspectRatio)));

    } );

    w.show();
    return a.exec();
}
