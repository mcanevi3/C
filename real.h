#ifndef REAL_H
#define REAL_H

#define real float
#define Error(msg) fprintf(stderr, msg, "string format", 30);

//List of elements
#define List(...) (real[]){__VA_ARGS__}

//List with size is a Vector
#define Vector(...) (real[]){__VA_ARGS__},sizeof((real[]){__VA_ARGS__})/sizeof(real) 

#endif


