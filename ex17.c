/* ************************************************************************ *
 *    Calculadora Polonesa, VERSION 0.1                                     *
 *    Calcula uma equacao na notacao polonesa usando pilha                  *
 *                                                                          *
 *    Copyright (C) 2015 by Ricardo Henrique Simplicio Dimas                *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Ricardo Henrique Simplicio Dimas <rhenrique.dimas@gmail.com>          *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99730-4919                                            *
 *                                                                          *
 *    Milena Maria Costa Pininga <milena.pininga@gmail.com>                 *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99834-5265                                            *
 * ************************************************************************ *
 * 
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define INFO_SIZE 10

struct StackStruct {
    char* info;
    struct StackStruct *next;
};

typedef struct StackStruct Satck;

void push (Stack** stackHeader, char* newItem)
{
    Stack* p_aux;
    p_aux = (Stack *)malloc(sizeof(Stack));

    p_aux->info = (char*)malloc(sizeof(char) * INFO_SIZE);
    strcpy(p_aux->info, newItem);
    p_aux->next = *stackHeader;

    *stackHeader = p_aux;
}

char* pop (Stack** stackHeader)
{
    char* info;
    info = (char*)malloc(sizeof(char) * INFO_SIZE);

    if (stackHeader == NULL)
        return NULL;

    Stack* p_aux;

    strcpy(info, (*stackHeader)->info);
    p_aux = *stackHeader;
    *stackHeader = (*stackHeader)->next;

    free(p_aux);
    return info;
}

void operation (Stack** stackHeader, char op)
{
    double right, left, result;
    right = atof(pop(&(*stackHeader)));
    left = atof(pop(&(*stackHeader)));

    switch (op)
    {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/':result = left / right; break;
    }

    char* buffer;
    buffer = (char*)malloc(sizeof(char) * INFO_SIZE);

    sprintf(buffer, "%4.8f", result);
    push(&(*stackHeader), buffer);
}

stack* expression_data()
{
    char data[INFO_SIZE];
    Stack* Stack* stackHeader;
    stackHeader = (Stack*)malloc(sizeof(Stack));
}

