#include "inheritance_defs.h"


void _PhysicalBoxpPHYSICALBOXddd(PhysicalBox *const this, double l, double w, double h)
{
    _BoxpBOXddd(&this->box, l, w, h);

    this->material.material = OTHER;
    printf("Material created, set to %s\n","Other");

    _printppPHYSICALBOX(this);
}

void _PhysicalBoxpPHYSICALBOXdddTYPES(PhysicalBox *const this, double l, double w, double h, Types t)
{
    _BoxpBOXddd(&this->box, l, w, h);

    this->material.material = t;

    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n",names[this->material.material]);

    _printppPHYSICALBOX(this);
}

void _PhysicalBoxpPHYSICALBOXTYPES(PhysicalBox *const this, Types t)
{
    _BoxpBOXd(&this->box, 1);

    this->material.material = t;

    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("Material created, set to %s\n",names[this->material.material]);

    _printppPHYSICALBOX(this);
}

void d_PhysicalBoxpPHYSICALBOX(PhysicalBox *this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox dtor, %f x %f x %f, %s; ",
            this->box.length,  this->box.width,  this->box.height, names[this->material.material]);

    _d_BoxpBOX(&this->box);
}

void _printppPHYSICALBOX(const PhysicalBox *const this)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    printf("PhysicalBox, made of %s; ",  names[this->material.material]);
    _printpBOX(this);
}

void _WeightBoxpWEIGHTBOXdddd(WeightBox * const this, double l, double w, double h, double wgt)
{
    _BoxpBOXddd(&this->box, l, w, h);

    this->weight = wgt;

    _printwpWEIGHTBOX(this);
}

void _copy_WeightBoxpWEIGHTBOX(WeightBox * const this, const WeightBox *other)
{
    _BoxpBOXd(&this->box, 1);

    this->weight = other->weight;

    _printwpWEIGHTBOX(this);
}

void _d_WeightBoxpWEIGHTBOX(WeightBox * const this)
{
    printf("Destructing WeightBox; ");
    _printwpWEIGHTBOX(this);

    _d_BoxpBOX(&this->box);
}

const WeightBox* _assignpWEIGHTBOXdddd(WeightBox * const this, const WeightBox *other)
{
    this->box.length = 1;
    this->box.width = 1;
    this->box.height = 1;

    this->weight = other->weight;

    return this;
}

void _printwpWEIGHTBOX(const WeightBox * const this)
{
    printf("WeightBox, weight: %f; ", this->weight);
    _printpBOX(this);
}