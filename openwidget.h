#ifndef OPENWIDGET_H
#define OPENWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include<QtWidgets>
#include <QMatrix4x4>


class Openwidget : public QOpenGLWidget, public QOpenGLFunctions
{
public:
    Openwidget(QWidget *parent = 0);
    ~Openwidget();

    int dx,dy;
    QPoint p1;
    int count;
    QLabel *label,*label1;

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;

    void paintGL() override;
    QPoint m_lastPos;
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
    QOpenGLShaderProgram *m_program;
   // void resizeGL(int width, int height) override;

    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    //void wheelEvent(QWheelEvent *) override;
};


#endif // OPENWIDGET_H
