#include"openwidget.h"
#include <QtOpenGL>
#include <iostream>
#include <QDebug>

Openwidget::Openwidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    setFormat(QSurfaceFormat::defaultFormat());
    count=0;
}

Openwidget::~Openwidget()
{
}

static const char *vertexShaderSource =
    "attribute highp vec4 posAttr;\n"
    "attribute lowp vec4 colAttr;\n"
    "varying lowp vec4 col;\n"
    "uniform highp mat4 matrix;\n"
    "void main() {\n"
    "   col = vec4(1, 0, 0, 1);\n"
    "   gl_Position = matrix * posAttr;\n"
    "}\n";

static const char *fragmentShaderSource =
    "varying lowp vec4 col;\n"
    "void main() {\n"
    "   gl_FragColor = col;\n"
    "}\n";

void Openwidget::initializeGL()
{
    makeCurrent();
    initializeOpenGLFunctions();
    // Create Shader (Do not release until VAO is created)
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->attributeLocation("matrix");

    m_program->release();

}




void Openwidget::mousePressEvent(QMouseEvent *event)
{
    //m_lastPos = event->pos();
    //p1=QCursor::pos();


    dx=event->pos().x();
    dy=event->pos().y();
    //dx=event->pos().x();
    //dy=event->pos().y();

    if(event->button()== Qt::LeftButton)
    {
        count=1;

    }


    else
    {
        count=0;
    }


    label1=new QLabel();
    label=new QLabel();
    QString s=QString::number(dx);
    QString s1=QString::number(dy);

    label->setText("X:"+s);
    label1->setText("Y:"+s1);

    //label->show();
    label1->show();
}

void Openwidget::mouseMoveEvent(QMouseEvent *event)
{


}


void Openwidget::resizeGL(int w, int h)
{
    int side = qMin(w, h);
    glViewport(width() - side / 2,height() - side / 2,600,600);
}


void Openwidget::paintGL()
{

    if(count==1)
    {


    glPointSize(20);
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0, 0.0);
    glVertex2f(dx,dy);
    glEnd();
    glFlush();


    }
else
    {
        auto label=new QLabel;
        QString s=QString::number(count);
        label->setText(s);

    }
}

