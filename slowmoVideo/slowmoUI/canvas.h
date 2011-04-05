/*
slowmoUI is a user interface for slowmoVideo.
Copyright (C) 2011  Simon A. Eugster (Granjow)  <simon.eu@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
*/

#ifndef CANVAS_H
#define CANVAS_H


#include <QWidget>
#include <QList>

class QPoint;
class QPointF;

namespace Ui {
    class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

protected:
    void paintEvent(QPaintEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void leaveEvent(QEvent *);

private:
    Ui::Canvas *ui;
    QPoint m_lastMousePos;
    bool m_mouseWithinWidget;
    unsigned int m_distLeft;
    unsigned int m_distBottom;
    float m_t0x;
    float m_t0y;
    float m_tmaxx;
    float m_tmaxy;
    unsigned int m_secResX;
    unsigned int m_secResY;

    QList<QPointF> m_nodes;

    const QPointF convertCanvasToTime(const QPoint &p) const;
    const QPoint convertTimeToCanvas(const QPointF &p) const;
};

#endif // CANVAS_H