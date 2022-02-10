#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Raytracer; }
QT_END_NAMESPACE

class Raytracer : public QMainWindow
{
    Q_OBJECT

public:
    Raytracer(QWidget *parent = nullptr);
    ~Raytracer();

private:
    Ui::Raytracer *ui;
};
#endif // RAYTRACER_HPP
