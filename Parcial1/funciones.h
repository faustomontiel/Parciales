
typedef struct{

    int codProvedor;
    char nombreProvedor[50];


}eProvedor;

typedef struct{

    int codProducto;
    char nombreProducto[50];
    float importe;
    int idProvedor;
    int cantidad;
    int estado;


}eProducto;

int menu();
/** \brief inicializa los productos en 0.
 * \param se ingresa un vector de tipo eProducto y un tamanio entero.
 */

void inicializarProductos(eProducto vec[], int tam);
/** \brief muestra todos los productos cargadas.
 * \param se ingresa un vector de tipo eProducto y un tamanio entero, un vector de tipo eProvedor y su tamanio.
 */
void mostrarProductos(eProducto vec[], int tamProd, eProvedor provedores[],int tamProv);
/** \brief muestra un solo producto.
 * \param se ingresa un vector de tipo eProducto , un tamanio entero y un vector de tipo eProvedor
 */

void mostrarProducto(eProducto prod, eProvedor [], int tam);
/** \brief busca una pocision libre en el array de productos.

 * \param se ingressa un array de ePoducto y su tamanio en entero.
 * \return retorna el valor 0 si esta libre.
 */

int buscarLibre(eProducto vec[], int tam);
/** \brief busca un producto en una pocision determinda.

 * \param se ingressa un array de ePoducto , su tamanio en entero y el codigo.
 * \return retorna el valor 1 si esta ocupado y se encontro el producto.
 */

int buscarProducto(eProducto vec[], int tam, int codigo);
/** \brief valida que el ingreso sea solo de palabras.

 * \param se ingresa una cadena de caracteres.
 * \return retorna el valor 1 si es una palabra.
 */

int validarString (char cadena[]);
/** \brief valida que el ingreso se solo numeros.

 * \paramse ingresa una cadena de caracteres.
 * \return retorna el valor 1 si es un numero.
 */

int validarNumero (char numero[]);
/** \brief busca una pocision libre en el array de productos.

 * \param se ingressa un array de ePoducto y su tamanio en entero.
 * \return retorna el valor 0 si esta libre.
 */

int pedirProvedor(eProvedor provedores[], int tam);
/** \brief agrega un producto.
 * \param se ingressa un array de ePoducto y su tamanio en entero, y un array eprovedor y un entero de su tamanio.
 */
void altaProducto(eProducto prod[], int tamProd, eProvedor provedores[], int tamProv);
/** \brief modifica un producto.
 * \param se ingressa un array de ePoducto y su tamanio en entero, y un array eprovedor y un entero de su tamanio.
 */
void modificarProducto(eProducto prod[],int tamprod,eProvedor provedor[],int tamprov);
/** \brief elimina un producto.
 * \param se ingressa un array de ePoducto y su tamanio en entero, y un array eprovedor y un entero de su tamanio.
 */
void eliminarProducto(eProducto prod[],int tam,eProvedor[],int);
/** \brief informa .
 * \param se ingressa un array de ePoducto y su tamanio en entero, y un array eprovedor y un entero de su tamanio.
 */
void informar(eProducto produc[],int);
/** \brief calcula el total de los importes y los promedios.
 * \param se ingressa un array de ePoducto y su tamanio en entero.
 */
void total_PromedioImportes(eProducto [],int );
/** \brief se encarga de calcular la cantidad de productos.
 * \param se ingressa un array de ePoducto y su tamanio en entero.
 */
void cantidadProductos(eProducto[],int);
/** \brief ordena los productos por importe y por nombre.
 * \param se ingressa un array de ePoducto y su tamanio en entero, y un array eprovedor y un entero de su tamanio.
 */
void ordenarProductos(eProducto [],int,eProvedor[],int);
void CantidadProductosXProvedor(eProducto gente[], int tamEmp, eProvedor sectores[], int tamSec);
void productoMasCaro(eProducto prod[],int tam,eProvedor prov[],int tamp);

