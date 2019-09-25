#ifndef EX8__CFRONT_ENCAPSULATION_DEFS_H
#define EX8__CFRONT_ENCAPSULATION_DEFS_H

#define NUM_BOXES  3

static const char* message = "The total volume held on the shelf is";

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


/* Box dec */
void _BoxpB(Box *const this);
void _BoxpBd(Box *const this, double dim);
void _BoxpBddd(Box *const this, double l, double w, double h);

void _d_BoxpB(Box *this);

void _printpB(const Box * const this);

Box* _multAssignpBd(Box *this, double mult);

Box _multpBd(const Box *this, double mult);



/* Shelf defs */
void _ShelfpS(Shelf * const this);

void _d_ShelfpS(Shelf * const this);

void _setBoxpSipB(Shelf * const this, int index, const Box* dims);

double _getVolumepS(const Shelf * const this);

void _printpS(const Shelf * const this);



#endif /*EX8__CFRONT_ENCAPSULATION_DEFS_H*/
