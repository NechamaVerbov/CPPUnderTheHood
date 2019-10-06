#ifndef EX8__CFRONT_ENCAPSULATION_DEFS_H
#define EX8__CFRONT_ENCAPSULATION_DEFS_H

#define NUM_BOXES  3

const char* message;

typedef enum {false, true} bool;

typedef struct {
    double width;
    double height;
    double length;
} Box;

typedef struct {
    Box boxes[NUM_BOXES];
} Shelf;


/* Name mangling: underscore, name of function or its meaning if its a operator,
 * initials of argument types- p for pointer*/


/* Box defs */
void _BoxpBOXd(Box *const this, double dim);

void _BoxpBOXddd(Box *const this, double l, double w, double h);

void _d_BoxpBOX(Box *this);

void _printpBOX(const Box * const this);

Box* _multAssignpBOXd(Box *this, double mult);

Box _multpBOXd(const Box *this, double mult);



/* Shelf defs */
void _ShelfpSHELF(Shelf * const this);

void _d_ShelfpSHELF(Shelf * const this);

void _setBoxpSHELFipBOX(Shelf * const this, int index, const Box* dims);

double _getVolumepSHELF(const Shelf * const this);

void _printpSHELF(const Shelf * const this);

void _setMessagepC(const char* msg);




#endif /*EX8__CFRONT_ENCAPSULATION_DEFS_H*/
