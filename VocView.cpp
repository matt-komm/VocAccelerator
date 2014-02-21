#include "VocView.hpp"

#include "ui_default.h"

VocView::VocView(QWidget * parent, Qt::WindowFlags f):
    QWidget(parent,f)
{
    Ui_Form defaultUI;
    defaultUI.setupUi(this);
}

VocView::~VocView()
{
}


