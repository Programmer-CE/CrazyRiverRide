#include "qrect.h"
#include "qpixmap.h"
#ifndef PAINTTASK_H
#define PAINTTASK_H

class PaintTask
{
    QRect rec;
    QPixmap *pix;
public:
    PaintTask();
    PaintTask(QRect pRec,QPixmap *pPix);
    PaintTask(const PaintTask &pt);
    QRect getRec() const;
    void setRec(const QRect &value);
    QPixmap *getPix() const;
    void setPix(QPixmap *value);
    ~PaintTask();
};

#endif // PAINTTASK_H
