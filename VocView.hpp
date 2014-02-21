#ifndef __VOCVIEW_H__
#define __VOCVIEW_H__

#include <QWidget>

class VocView:
    public QWidget
{
    Q_OBJECT

    protected:
    public:
        VocView(QWidget * parent = 0, Qt::WindowFlags f = 0);
        ~VocView();
};

#endif

