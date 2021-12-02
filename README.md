# Integral-A -> Fate/Grand Order Manager
Erick Alfredo García Huerta - A01708119
## Correcciones
* Se implementó el primer avance en el archivo sorts.h
* Se implementó el segundo avance en el archivo estructuraslineales.h
* Se implementó el tercer avance en el archivo trees.h
## Contexto: 
El popular Gacha-JRPG para móviles Fate/Grand Order cuenta con un total de 276 de personajes jugables (en el servidor inglés) llamados Servants, divididos en siete clases principales: archer, lancer, saber, assasin, caster, rider y berserker; además de clases cinco clases extra: moon cancer, ruler, avenger, alter ego y foreigner; todos estos contando con distintas habilidades, estadísticas, rarezas, rasgos y hasta el nivel que pueden alcanzar por medios normales. Además, el sistema de juego permite una party de hasta 5 servants propios y un sexto  de soporte dado por el juego mismo con fines de historia o prestado de otro jugador que se tenga en la lista de amigo o aleatorio.
Esto llama a la necesidad de una herramienta que permita a los jugadores encontrar una forma sencilla para ordenar a los servants en base a las necesidades de la party como un servant con mucha salud para tomar el daño de los jefes por el equipo o un servant con alta estadística de daño para servir como dps. De  la misma forma incluso aunque haya dos servants de la misma clase, sus estadísticas pueden variar en base a varios factores.
## Consideraciones:
Este programa da por hecho que usted conoce de ante mano el nombre completo del servant y deberá ser escrito idénticamente para las funciones que requieren el nombre del servant. Si el servant posee más de un nombre o un apellido, separarlos con '_', de lo contrario recibirá error. Al inicio del programa se le dará la oportunidad de imprimir los nombres de los servants.
## Competencia:
### SICT0301B Evalúa los componentes
* Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
   * Se implementaron los casos de prueba como la opción 4 del primer menú de opciones.
* Hace un análisis de complejidad correcto y completo para todo el programa y sus compenetes [NOTA DEL ALUMNO:para un análisis más detallado, leer los comentarios en cada clase]
   * Sort: Esta función permite al usuario ordenar de menor a mayor los servants de acuerdo a una estadística previamente ingresada en el programa, así como consultar los datos de la posición de los servants en la misma. Esta estructura presenta una complejidad de O(n log n) por ser un merge sort
     - string printArray() -> brief Función que almacena los datos del arreglo en un string stream y lo imprime / complejidad: O(n) porque usa un ciclo for ligado al tamaño de un arreglo.
     - vector< struct servant> merge(int) -> brief Función principal que usa un merge sort para ordenar los datos de acuerdo a un cierto parámetro que se decide con el int op. / Complejidad O(n*log(n)) al ser un merge sort y dividir una parte de los datos en función de si cumplen o no las condiciones de > o <.
   * List: Esta función permite al usuario crear su propia party, además de buscar qué datos están o no en ella, imprimir los datos completos de la misma, etc. La estructura al ser una double linked list, presenta una complejidad tanto de navegación como de consulta de O(n)
     - add(vector<vector< string>> servantdb, string name) -> brief Función que valida si la lista no está llena y en caso de estar vacía, llama a la función addfirst(); extrae sus datos de la base de datos general y la almacena en un vector que después será almacenado en la lista. / Complejidad: O(n) -> uso de un ciclo for.
     - printParty() -> brief Función que convierte los datos del vector de datos del servant en un string stream y lo imprime. / Complejidad: O(n) -> uso de un ciclo for
     - search(string name) -> brief Función que busca nodo por nodo el nombre del servant que se necesitay regresa sus datos completos. De no encontrarse el servant, se envía un mensaje de error. / complejidad: O(n^2) -> uso de dos ciclos for anidados
     - remove(string name) -> brief: Función que elimina un elemento dado de la lista tras validar que no está vacía y diferencía entr el primer elemento de la misma y cualquier otro. / omplejidad: O(n) -> uso de un ciclo for dependiente del tamaño del arreglo
   * Tree: Esta función recibe la clase de un servant y una estadística que será el criterio por el que serán ordenado. Presenta una complejidad de O(log n) en la mayoría de sus funciones debido a que con cada ciclo recursivo se ignora la mitad mayor o menor de los datos según el caso.
     - find(string, int) -> brief Función que toma el nombre de un servant y los coteja con la base de datos completa para encontrar el arreglo completo donde se encuentran todos sus datos y lo envía a la dunción find de TreeNode / complejidad: O(n) -> implementación de dos ciclos for, uno con parámetros fijos (O(1)) y otro del tamaño del array (O(n)). O(1) + O(n) = O(n)
     - printServant() const -> brief función que guarda los datos de un servant en un string stream / complejidad: O(n) -> presencia de ciclo recursivo que recorre todo el árbol
### SICT0302B Toma decisiones 
* Selecciona un algoritmo de ordenamiento adecuado al problema
  * Se seleccionó un merge sort debido a que de acuerdo a las simulaciones (ver referencias) es la estructura de datos que mejor se acopla a un arreglo de datos ordenado aleatoriamente como el que se tiene en el proyecto.
* Selecciona y usa una estructura lineal adecuada al problema
  * Se seleccionó esta estructura gracias a la facilidad que brinda para modificar los datos independientemene de su posición en la lista y su navegación en ambos sentidos-
* Usa un árbol adecuado para resolver un problema
  * Se seleccionó el BST debido a su fácilidad de construcción para el almacenamiento de grandes cantidades de datos, ya que el resto de árboles ocuparían demasiado tiempo reordenándose.
### SICT0303B Implementa acciones científicas
* Implementa mecanismos para consultar información de las estructras correctos
  * Tanto el árbol como la lista doblemente ligada cuentan con herramientas para la consulta de información tanto global como individual. find() y search() para el bst y la lista doblemente ligada respectivamente en el apartado individual, y en apartado global inorder() y printparty() para el bst y la lista doblemente ligada respectivamente. Además de que cuentan con elementos para borrar datos.
* Implementa mecanismos de lectura de archivos correctos
  * Tanto en sorts.h como en tree.h se implementaron mecanismos para leer los datos del archivo .csv, sin embargo estos son bastante complejos gracias al enorme volumen de datos que se manejan.
## Alumno:
@alfredohuerta Erick Alfredo García Huerta - A01708119
## Referencias: 
https://www.cs.usfca.edu/~galles/visualization/Algorithms.html -> simulaciones de sorts
https://github.com/WeebMogul/Fate--Grand-Order-Servant-Data-Extractor -> adquisición de base de datos de servants
