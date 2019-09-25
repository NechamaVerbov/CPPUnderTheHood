#include <stdio.h>
#include "encapsulation_defs.h"

/* Box def */

void _BoxpB(Box *const this)
{
    this->width = 1;
    this->height= 1;
    this->length = 1;

    _printpB(this);
}

void _BoxpBd(Box *const this, double dim)
{
    this->width = dim;
    this->height= dim;
    this->length = dim;

    _printpB(this);
}

void _BoxpBddd(Box *const this, double l, double w, double h)
{
    this->width = w;
    this->height= h;
    this->length = l;

    _printpB(this);
}

void _d_BoxpB(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box* _multAssignpBd(Box *this, double mult)
{
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

Box _multpBd(const Box *this, double mult)
{
    Box ret = *this;
    _multAssignpBd(&ret, mult);
    return ret;

}

void _printpB(const Box * const this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}

/* Shelf def */
void _ShelfpS(Shelf * const this)
{
    int i;
    for (i = 0; i < NUM_BOXES; ++i) {
        _BoxpB(&this->boxes[i]);
    }
}

void _d_ShelfpS(Shelf * const this)
{
    int i;
    for (i = NUM_BOXES - 1; i >= 0; --i) {
        _d_BoxpB(&this->boxes[i]);
    }
}

void _setBoxpSipB(Shelf * const this, int index, const Box* dims)
{
    this->boxes[index] = *dims;
}

double _getVolumepS(const Shelf * const this)
{
    double vol = 0;
    int i;
    for (i = 0; i < NUM_BOXES; ++i)
        vol += (this->boxes[i].width * this->boxes[i].length * this->boxes[i].height);

    return vol;
}

void _printpS(const Shelf * const this)
{
    printf("%s %f\n", message, _getVolumepS(this));
}


