// BSD 2-Clause License

// Copyright (c) 2020, Alexander Agdgomlishvili
// cdevelopment@mail.com

// All rights reserved.

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/******************************************/
/*                                        */
/*        Alexander Agdgomlishvili        */
/*                                        */
/*         cdevelopment@mail.com          */
/*                                        */
/******************************************/

#ifndef CLIST_H
#define CLIST_H
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct CList
    {
        void (*add)(struct CList *l, void *o);                   /* Add object to the end of a list */
        void (*insert)(struct CList *l, void *o, int n);         /* Insert object at position 'n' */
        void (*replace)(struct CList *l, void *o, int n);        /* Replace object at position 'n' */
        void (*remove)(struct CList *l, int n);                  /* Remove object at position 'n' */
        void *(*at)(struct CList *l, int n);                     /* Get object at position 'n' */
        int (*realloc)(struct CList *l, int n);                  /* Reallocate list to 'size' items */
        int (*firstIndex)(struct CList *l, void *o);             /* Get first index of the object */
        int (*lastIndex)(struct CList *l, void *o);              /* Get last index of the object */
        int (*count)(struct CList *l);                           /* Get list size */
        void (*clear)(struct CList *l);                          /* Clear list */
        void (*free)(struct CList *l);                           /* Destroy struct CList and all data */
        void (*print)(struct CList *l, int n, const char *type); /* Print list data */
        void *priv;                                              /* NOT FOR USE, private data */
    } CList;

    CList *CList_Init(size_t objSize); /* Set list object size in bytes */

#ifdef __cplusplus
}
#endif

#endif /* CLIST_H */