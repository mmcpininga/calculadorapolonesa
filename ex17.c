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

#include <stdio.h>
#include <stdlib.h>

typedef struct /*estrutura com os elementos da pilha*/
    {
    char c;
    } elementosp;

struct dado_pilha /*estrutura com os dados da pilha*/
    {
    elementosp info;
    struct dado_pilha *prox;
    };

typedef struct dado_pilha pilha; /*dados da pilha*/
void push(pilha **, elementosp); /*add elemento na pilha*/
elementosp pop (pilha **); /*retira elemento da pilha*/

void push (pilha ** pil, elementosp item)
{
    pilha * p_aux;
    p_aux = (pilha *) malloc (sizeof(pilha));

    p_aux-> info = item;
    p_aux-> prox = * pil;
    * pil = p_aux;
}

elementosp pop (pilha ** pil)
{
    pilha * p_aux;
    elementosp item = {0};
    
    if (pil == NULL)
        return item;

    item = (* pil)-> info;
    p_aux = * pil;
    * pil = (*pil)-> prox;
    free(p_aux);
    return item;
}


int main(int argc, char *argv)
{
    return 0;
}

