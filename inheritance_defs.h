

#ifndef EX8__CFRONT_INHERITANCE_DEFS_H
#define EX8__CFRONT_INHERITANCE_DEFS_H

#include <stdio.h>
#include "encapsulation_defs.h"

typedef enum { PLASTIC, METAL, WOOD, PAPER, OTHER } Types;

typedef struct
{
} Materials;

typedef struct
{
    Materials materials;
    Types material;

} Material_t;

typedef struct
{
    Box box;
    Material_t material;

} PhysicalBox;

typedef struct
{
    Box box;
    double weight;

} WeightBox;

/* Name mangling: underscore, name of function or its meaning if its a operator,
 * initials of argument types- p for pointer, built in types in capital */

/* PhysicalBox defs*/
void _PhysicalBoxpPHYSICALBOXddd(PhysicalBox *const this, double l, double w, double h);
void _PhysicalBoxpPHYSICALBOXdddTYPES(PhysicalBox *const this, double l, double w, double h, Types t);
void _PhysicalBoxpPHYSICALBOXTYPES(PhysicalBox *const this, Types t);

void d_PhysicalBoxpPHYSICALBOX(PhysicalBox *this);

void _printppPHYSICALBOX(const PhysicalBox *const this);

/* WeightBox defs*/

void _WeightBoxpWEIGHTBOXdddd(WeightBox * const this, double l, double w, double h, double wgt);
void _copy_WeightBoxpWEIGHTBOX(WeightBox * const this, const WeightBox *other);

void _d_WeightBoxpWEIGHTBOX(WeightBox * const this);

const WeightBox* _assignpWEIGHTBOXdddd(WeightBox * const this, const WeightBox *other);

void _printwpWEIGHTBOX(const WeightBox * const this);








#endif /*EX8__CFRONT_INHERITANCE_DEFS_H*/
