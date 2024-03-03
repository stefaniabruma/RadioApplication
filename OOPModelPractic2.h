#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OOPModelPractic2.h"

class OOPModelPractic2 : public QMainWindow
{
    Q_OBJECT

public:
    OOPModelPractic2(QWidget *parent = nullptr);
    ~OOPModelPractic2();

private:
    Ui::OOPModelPractic2Class ui;
};
