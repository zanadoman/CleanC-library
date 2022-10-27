/* CleanC.h - 2022Q4 - Version beta
Developed by: Doman Zana, for the sake of humanity
and to make C a clean and modern programming language. */


// Constants
#define PI 3.141593

// Types in bytes
#define CHAR 1
#define SHORT 2
#define INT 3
#define LONG 4
#define FLOAT 5
#define DOUBLE 6


// Bool definition
#define true 1
#define false 0
typedef char bool;

// List definition
struct listNode
{
    double lValue;
    struct listNode *lPrev;
    struct listNode *lNext;
};
typedef struct listNode list;


// IO functions
int scanvoid();

// Variable functions
int swap(void *a, void *b, char type);

// Array functions
int areverse(void *first, void *last, char type);
int asort(void *first, void *last, char type);
long strint(char *a);
double strdouble(char *a);

// List functions (Declaring a list: list *listname = NULL;)
int ladd(list **listptr, double value);
int linsert(list *listptr, int index, double value);
int lremove(list **listptr, int index);
double lvalue(list *listptr, int index);
int lchange(list *listptr, int index, int value);
int llength(list *listptr);
bool lcontains(list *listptr, double value);
int lreverse(list *listptr, int first, int last);

// Math functions
double root(double radicand, double index);


// math.h functions
double sin(double x);
double asin(double x);
double sinh(double x);
double cos(double x);
double acos(double x);
double cosh(double x);
double atan(double x);
double atan2(double y, double x);
double tanh(double x);
double exp(double x);
double frexp(double x, int *exponent);
double ldexp(double x, int exponent);
double log(double x);
double log10(double x);
double modf(double x, double *integer);
double fmod(double x, double y);
double pow(double x, double y);
double ceil(double x);
double floor(double x);
double fabs(double x);