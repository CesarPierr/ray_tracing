#include "raytracer.hpp"
#include "ui_raytracer.h"

Raytracer::Raytracer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Raytracer)
{
    ui->setupUi(this);
}

Raytracer::~Raytracer()
{
    delete ui;
}

