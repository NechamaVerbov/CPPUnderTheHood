#ifndef EX8__CFRONT_POLYMORPHISM_DEFS_H
#define EX8__CFRONT_POLYMORPHISM_DEFS_H

#define PrePostDollarFixer_DEFAULT_SYMBOL '$'
#define PrePostHashFixer_DEFAULT_SYMBOL '#'
#define PrePostFloatDollarFixer_DEFAULT_SYMBOL  '@'

#include <stdio.h>
#include <stdlib.h>

int next_id;

typedef void* (*ptrFuncVirtualTable[]) (void*, ...);

typedef struct
{
    ptrFuncVirtualTable* textFormatterVirtualTable;
}TextFormatter;


typedef struct
{
    TextFormatter textFormatter;
    int id;

    struct Ider
    {};

} DefaultTextFormatter;


typedef struct
{
    DefaultTextFormatter defaultTextFormatter;
    const char* pre;
    const char* post;

} PrePostFixer;

typedef struct
{
    PrePostFixer prePostFixer;

} PrePostDollarFixer;

typedef struct
{
    PrePostDollarFixer postDollarFixer;
    int precision;

}  PrePostHashFixer;

typedef struct
{
    PrePostDollarFixer prePostDollarFixer;

} PrePostFloatDollarFixer;

typedef struct
{
    PrePostFloatDollarFixer postFloatDollarFixer;

}PrePostChecker;

typedef struct
{
    DefaultTextFormatter defaultTextFormatter;
    int times;

}  Multiplier;



/*TextFormatter defs*/
void _d_TextFormatterpTextFormatter(TextFormatter * this);

/*DefaultTextFormatter defs*/
void _DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * const this);
void _DefaultTextFormatterpDefaultTextFormatterpDefaultTextFormatter
                    (DefaultTextFormatter * const this, const DefaultTextFormatter *);
DefaultTextFormatter *const _assignpDefaultTextFormatterpDefaultTextFormatter
                    (DefaultTextFormatter * const this, const DefaultTextFormatter* const);
void _d_DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * this);
void _printpDefaultTextFormatters(const DefaultTextFormatter * const this, const char* text);

/* global defs*/
DefaultTextFormatter* generateFormatterArray();

/* PrePostFixer defs*/
void _PrePostFixerpPrePostFixerss(PrePostFixer * const this, const char* prefix, const char* postfix);
void _d_PrePostFixerpPrePostFixer(PrePostFixer * this);
void _printpPrePostFixers(const PrePostFixer * const this, const char* text);
void _printpPrePostFixerlc(const PrePostFixer * const this, long num, char symbol /*= '\0'*/);
char _getDefaultSymbolpPrePostFixer(const PrePostFixer * const this);
/*
const char* _getPrefixpPrePostFixer(const PrePostFixer * const this);
const char* _getPostfixpPrePostFixer(const PrePostFixer * const this);
void _print_numpPrePostFixerl(const PrePostFixer * const this, long num);
void _print_numpPrePostFixerlc(const PrePostFixer * const this, long num, char symbol);
 */

/*PrePostDollarFixer defs*/
void PrePostDollarFixerpPrePostDollarFixerss(PrePostDollarFixer *const this, const char* prefix, const char* postfix);
void PrePostDollarFixerpPrePostDollarFixerpPrePostDollarFixer(PrePostDollarFixer *const this, const PrePostDollarFixer *const other);
void _d_PrePostDollarFixerpPrePostDollarFixer(PrePostDollarFixer * this);
void _printpPrePostDollarFixerlc(const PrePostDollarFixer *const this, long num, char symbol);
char _getDefaultSymbolpPrePostDollarFixer(const PrePostDollarFixer *const this);
void _printpPrePostDollarFixeric(const PrePostDollarFixer *const this, int num, char symbol);
void _printpPrePostDollarFixerdc(const PrePostDollarFixer *const this, double num, char symbol);


/*PrePostHashFixer defs*/
void _PrePostHashFixerpPrePostHashFixeri(PrePostHashFixer * const this, int prc/* = 4*/);
void _d_PrePostHashFixerpPrePostHashFixer(PrePostHashFixer * this);
void _printpPrePostHashFixerlc(PrePostHashFixer * const this, long num, char symbol);
char _getDefaultSymbolpPrePostHashFixer(const PrePostHashFixer * const this);
void _printpPrePostHashFixeric(const PrePostHashFixer * const this, int num, char symbol);

/*PrePostFloatDollarFixer defs*/
void _PrePostFloatDollarFixerpPrePostFloatDollarFixerss(PrePostFloatDollarFixer *const this, const char* prefix, const char* postfix);
void _d_PrePostFloatDollarFixerpPrePostFloatDollarFixer(PrePostFloatDollarFixer *);
char _getDefaultSymbolpPrePostFloatDollarFixer(const PrePostFloatDollarFixer *const this);
void _printpPrePostFloatDollarFixerf(const PrePostFloatDollarFixer *const this, float num);
void printpPrePostFloatDollarFixerfc(const PrePostFloatDollarFixer *const this, float num, char symbol);

/*PrePostChecker defs*/
void _PrePostCheckerpPrePostChecker(PrePostChecker * const this);
void _d_PrePostCheckerpPrePostChecker(PrePostChecker * this);
void _printThisSymbolUsingFuncpPrePostChecker(const PrePostChecker * const this);
void _printThisSymbolDirectlypPrePostChecker(const PrePostChecker * const this);
void _printDollarSymbolByCastUsingFuncpPrePostChecker(const PrePostChecker * const this);
void _printDollarSymbolByScopeUsingFuncpPrePostChecker(const PrePostChecker * const this);
void _printDollarSymbolByCastDirectlypPrePostChecker(const PrePostChecker * const this);
void _printDollarSymbolByScopeDirectlypPrePostChecker(const PrePostChecker * const this);


/*Multiplier defs*/
void _MultiplierpMultiplieri(Multiplier *const, int t);

void _MultiplierpMultiplierpMultiplier(Multiplier *const, Multiplier *const);

void _d_MultiplierpMultiplier(Multiplier *const);

void _printpMultipliers(Multiplier *const this, const char* mes);

#endif /*EX8__CFRONT_POLYMORPHISM_DEFS_H*/
