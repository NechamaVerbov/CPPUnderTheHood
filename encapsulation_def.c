#include <stdio.h>
#include "encapsulation_defs.h"


static const char* message = "The total volume held on the shelf is";

/* Box def */
void _BoxpBOX(Box *const this)
{
    this->width = 1;
    this->height= 1;
    this->length = 1;

    _printpBOX(this);
}

void _BoxpBOXd(Box *const this, double dim)
{
    this->width = dim;
    this->height= dim;
    this->length = dim;

    _printpBOX(this);
}

void _BoxpBOXddd(Box *const this, double l, double w, double h)
{
    this->width = w;
    this->height= h;
    this->length = l;

    _printpBOX(this);
}

void _copy_BoxpBOXpBOX(Box* const this, const Box* const other)
{
    this->length = other->length;
    this->height = other->height;
    this->width = other->width;
}

void _assignpBOXpBOX(Box* const this, const Box* const other)
{
    this->length = other->length;
    this->height = other->height;
    this->width = other->width;
}

void _d_BoxpBOX(Box *this)
{
    printf("Box destructor, %f x %f x %f\n", this->width, this->height, this->length);
}

Box* _multAssignpBOXd(Box *this, double mult)
{
    this->width *= mult;
    this->height *= mult;
    this->length *= mult;

    return this;
}

Box _multpBOXd(const Box *this, double mult)
{
    Box ret = *this;
    _multAssignpBOXd(&ret, mult);
    return ret;

}

void _printpBOX(const Box * const this)
{
    printf("Box: %f x %f x %f\n", this->length, this->width, this->height);
}

/* Shelf def */
void _ShelfpSHELF(Shelf * const this)
{
    int i;
    for (i = 0; i < NUM_BOXES; ++i) {
        _BoxpBOXd(&this->boxes[i], 1);
    }
}

void _d_ShelfpSHELF(Shelf * const this)
{
    int i;
    for (i = NUM_BOXES - 1; i >= 0; --i) {
        _d_BoxpBOX(&this->boxes[i]);
    }
}

void _setBoxpSHELFipBOX(Shelf * const this, int index, const Box* dims)
{
    this->boxes[index] = *dims;
}

double _getVolumepSHELF(const Shelf * const this)
{
    double vol = 0;
    int i;
    for (i = 0; i < NUM_BOXES; ++i)
        vol += (this->boxes[i].width * this->boxes[i].length * this->boxes[i].height);

    return vol;
}

void _printpSHELF(const Shelf * const this)
{
    printf("%s %f\n", message, _getVolumepSHELF(this));
}

void _setMessagepC(const char* msg)
{
    message = msg;
}

