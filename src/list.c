/*
 * Copyright (C) 2002  Erik Fears
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 *
 *       Foundation, Inc.
 *       59 Temple Place - Suite 330
 *       Boston, MA  02111-1307, USA.
 *
 *
 */


#include "opm_common.h"
#include "malloc.h"

node_t *node_create(void *data)
{
   node_t *node = MyMalloc(sizeof(node_t));
   node->next = 0;
   node->prev = 0;  
   node->data = (void *) data;

   return node;
}

list_t *list_create()
{
   list_t *list = MyMalloc(sizeof(list_t));

   list->head = 0;
   list->tail = 0;
   list->elements = 0;

   return list;
}

node_t *list_add(list_t *list, node_t *node)
{

   if(!list || !node)
      return 0;   

   if(!list->tail)
   {
      list->head = node;
      list->tail = node;
      node->next = 0;
      node->prev = 0;
   }
   else
   {
      node->prev = list->tail;
      list->tail->next = node;
      list->tail = node;
      node->next = 0;
   }

   list->elements++;
   return node;
}

node_t *list_remove(list_t *list, node_t *node)
{
   node_t *p;

   if(!list || !node)
      return 0;

   if(node == list->head)
   {
      list->head = node->next;

      if(node->next)
         node->next->prev = 0;
      else
         list->tail = 0;
 
      list->elements--;

      return node;
   }
   else if(node == list->tail)
   {
      list->tail = list->tail->prev;
      list->tail->next = 0;
  
      list->elements--;

      return node;
   }


   for(p = list->head; p; p = p->next)
   {
      if(p == node)
      {        
         p->prev->next = p->next;
         p->next->prev = p->prev;
         list->elements--;
         return p;
      }
   }

   return 0;
}

void list_free(list_t *list)
{
   MyFree(list);
}

void node_free(node_t *node)
{
   MyFree(node);
}
