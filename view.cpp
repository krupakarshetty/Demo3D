#include "view.h"
#include<QWheelEvent>
view::view()
{

}


void view::wheelEvent(QWheelEvent *event)
{

   setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
   double scaleFactor=1.16;

   if(event->angleDelta().x()>0||event->angleDelta().y()>0)
   {
       scale(scaleFactor,scaleFactor);

   }

   else
   {
       scale(1/scaleFactor,1/scaleFactor);
   }
}
