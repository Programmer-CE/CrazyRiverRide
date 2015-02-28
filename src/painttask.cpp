#include "painttask.h"


QRect PaintTask::getRec() const
{
    return rec;
}

void PaintTask::setRec(const QRect &value)
{
    rec = value;
}

QPixmap *PaintTask::getPix() const
{
    return pix;
}

void PaintTask::setPix(QPixmap *value)
{
    pix = value;
}

PaintTask::~PaintTask()
{

}
PaintTask::PaintTask()
{

}

PaintTask::PaintTask(QRect pRec,QPixmap *pPix):rec(pRec)
{
    pix = pPix;
}

PaintTask::PaintTask(const PaintTask &pt):rec(pt.rec)
{
    pix = pt.pix;
}
