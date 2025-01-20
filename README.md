The .h files are the headers, they contain the definition of the classes (with their methods and the internal classes that access the memory) while the files ending with .cpp contain the implementation of the class methods.

# English  

(debajo esta la descripcion de las estructuras en español).

# 💡 Data Structures  
Welcome to the Data Structures repository! Here you will find implementations of various structures that are fundamental for efficient and scalable programming.

🟢 Vector: 
The Vector is a linear container (meaning each element is arranged sequentially in memory) and has the particularity that each element is stored one next to the other in memory (contiguously). This brings advantages, such as random access, allowing very efficient access to an element in the vector (computational order O(1)). However, not everything is advantageous. The continuity of the data brings problems when inserting new elements, as it requires removing the data and requesting a larger memory space.
A "solution" (which I implemented in this repository) is to have the size represent the number of elements, not the memory size of the vector. This allows insertion to be less costly in cases where the capacity (which truly represents the amount of contiguous available space) is not exceeded.

🔵 Singly Linked List:
The Singly Linked List is a linear container, but with the advantage (or disadvantage, depending on the case) that elements are not stored contiguously. Instead, they are linked using nodes, where each node contains the value and a reference to the next node.
This makes insertion and deletion of elements very efficient (O(1)) because other elements do not need to be moved or rearranged—only references are adjusted.
However, accessing a node at a specific position is more costly (O(n)) because it is necessary to traverse the list from the beginning to the desired position (this is the downside of having non-contiguous elements).
Additionally, obtaining the previous node to a given node is also costly (O(n/2) on average), which limits some operations compared to other linear structures.
This structure is ideal when elements are frequently inserted or removed in arbitrary positions, and fast access by index is not prioritized.

🔗 Doubly Linked List:
The Doubly Linked List is similar to the singly linked list but with the added feature that each node contains references to both the next and the previous nodes.
This enables efficient insertion, deletion, and traversal in both directions (O(1)) and eliminates the cost of accessing the previous node, as seen in the singly linked list.
While it is more efficient in terms of bidirectional access, it also requires more memory because each node has two references instead of one.
This structure is useful when fast access to both the next and the previous nodes is required, such as in search algorithms.

🟡 Queue:
The Queue is a data structure that follows the FIFO (First In, First Out) principle, meaning the first element added is the first one removed.
In simple terms, it is like a queue at a supermarket or a waiting line.
Elements are added to the end of the queue and removed from the front, ensuring access in the order they arrived.
In this repository, the queue is implemented using a list, allowing all its operations (insertion, removal, and front access) to execute with O(1) time complexity, making them very efficient.
The Queue is useful in scenarios like task management or parallel processing, where elements must be processed in the same order they arrive.

🟠 Stack:
The Stack is another data structure that follows the LIFO (Last In, First Out) principle, meaning the last element added is the first one removed.
A good example is a stack of plates or books: the last one you place is the first one to be removed.
In this repository, the stack is implemented, like the queue, using a list, allowing insertion, removal, and top access operations to be performed with O(1) time complexity.
The Stack can be used in algorithms for undo/redo functionality in applications like Word, where each action is stored in the stack, and the last added element is removed whenever the undo action is performed.

🌳 Tree:
A Tree is a hierarchical data structure where each element has a "parent" and can have "children," creating a branching structure.
Unlike linear structures like vectors or lists, trees are ideal for representing hierarchical relationships, such as a family tree or the directory structure of a file system.
Trees are commonly traversed recursively, making them especially suitable for programming techniques like recursion.
There are different types of trees, such as binary trees and binary search trees, which optimize the access and insertion of elements.
Trees are fundamental in various applications, such as databases, index structures, and file systems.

🌲 Binary Tree
The Binary Tree is a specific type of tree data structure where each node can have at most two children: a left child and a right child.
In this structure, insertions occur in non-dereferenceable positions within the tree, as each position is predefined.
It is widely used in computer science due to its efficiency in retrieving information, especially when implemented as a Binary Search Tree (BST). In a BST, elements are organized so that the left child has a value less than its parent node, while the right child has a greater value. This organization optimizes operations such as searching, inserting, and deleting.

🗺️ Map:
A Map is a data structure that associates unique keys with values.
In this repository, the map is implemented using a sorted vector of pairs (key-value).
A function is used to find the appropriate position in the vector to insert the new key-value pair, enabling efficient key lookup (with O(log(n)) complexity using binary search).
This structure is very useful when elements need to be associated with unique identifiers, like in a dictionary.

🎨 Collaboration:
Feel free to explore the repository and contribute your ideas! If you have suggestions or find any errors, don't hesitate to open an issue or send a pull request. 💻✨








# Español

(The English description is above)

# 💡 Estructuras de Datos
¡Bienvenido al repositorio de Estructuras de Datos! Aquí encontrarás implementaciones de diversas estructuras que son fundamentales para la programación eficiente y escalable.

🟢 Vector:
El Vector es un contenedor lineal (es decir, cada elemento está organizado de manera ordenada en memoria) y tiene la particularidad de que cada elemento se almacena uno al lado del otro en memoria (de manera continua). Esto trae consigo ventajas, tales como el acceso aleatorio, permitiendo que se pueda acceder a un elemento del vector de manera muy eficiente (orden computacional O(1)). Sin embargo, no todo son ventajas. La continuidad de los datos trae problemas a la hora de insertar elementos nuevos, ya que es necesario eliminar los datos y solicitar un espacio de memoria más grande.
Hay una "solución" (la cual implementé en el repositorio), que consiste en que el size no sea el tamaño del vector en memoria, sino únicamente la cantidad de elementos. Esto permite que la inserción sea menos costosa en casos donde no se supera la capacity (que realmente representa la cantidad de espacio contiguo disponible).

🔵 Singly Linked List:
La Lista Simplemente Enlazada es un contenedor lineal, pero con la ventaja (o desventaja, dependiendo del caso) de que los elementos no están guardados de forma continua. En cambio, están enlazados mediante celdas, donde cada una contiene el valor y una referencia al siguiente nodo.
Esto hace que la inserción y eliminación de elementos sea muy eficiente (O(1)), ya que no se requiere mover o reorganizar otros elementos; solo se ajustan las referencias.
Sin embargo, acceder a una celda en una posición específica es más costoso (O(n)), porque es necesario recorrer la lista desde el principio hasta la posición deseada (esta es la desventaja de que los elementos no estén continuos).
Además, obtener el nodo previo a un nodo también es costoso (O(n/2) en promedio), lo que limita algunas operaciones en comparación con otras estructuras lineales.
Esta estructura es ideal cuando se necesita insertar y eliminar elementos continuamente en posiciones arbitrarias, pero no se prioriza el acceso rápido por índice.

🔗 Double Linked List:
La Lista Doblemente Enlazada es similar a la lista simplemente enlazada, pero con la particularidad de que cada nodo contiene referencias tanto al nodo siguiente como al nodo anterior.
Esto permite que la inserción, eliminación y recorrido hacia adelante y hacia atrás sean eficientes (O(1)), y se evita el costo de acceder al nodo previo, como ocurre en la lista simplemente enlazada.
Aunque es más eficiente que la lista simplemente enlazada en términos de acceso bidireccional, también requiere más memoria, ya que cada nodo tiene dos referencias en lugar de una.
Esta estructura es útil cuando se requiere un acceso rápido tanto al siguiente como al nodo anterior, por ejemplo, en la implementación de algoritmos de búsqueda.

🟡 Queue:
La Queue (o cola) es una estructura de datos que sigue el principio FIFO (First In, First Out), es decir, el primer elemento en entrar es el primero en salir.
En términos simples, es como una fila o cola en un supermercado o una cola de espera.
Los elementos se insertan al final de la cola y se eliminan desde el frente, lo que garantiza un acceso en orden de llegada.
En este repositorio, la implementación de la cola se realiza utilizando una lista, lo que permite que todas sus operaciones (inserción, eliminación y acceso al frente) se ejecuten con una complejidad de tiempo O(1), es decir, de manera muy eficiente.
La Queue es útil en casos como el manejo de tareas o procesos en paralelo, donde los elementos deben ser procesados en el mismo orden en que llegaron.

🟠 Stack:
La Stack (o pila) es otra estructura de datos que sigue el principio LIFO (Last In, First Out), es decir, el último elemento en entrar es el primero en salir.
Un buen ejemplo de esto es una pila de platos o libros: el último que pongas será el primero en ser retirado.
En este repositorio, la implementación de la pila se realiza, al igual que con la cola, utilizando una lista, lo que permite que las operaciones de inserción, eliminación y acceso al tope de la pila se realicen con una complejidad de tiempo O(1).
La Stack se podría utilizar en algoritmos de hacer/deshacer en aplicaciones como Word, donde cada acción se almacena en la pila y se elimina el último elemento insertado cada vez que se realiza la acción de deshacer.

🌳 Tree:
Un Tree (árbol) es una estructura de datos jerárquica en la que cada elemento tiene un "padre" y puede tener "hijos", lo que crea una estructura de ramificación.
A diferencia de las estructuras lineales, como los vectores o listas, los árboles son ideales para representar relaciones jerárquicas, como un árbol genealógico o la estructura de directorios en un sistema de archivos.
Los árboles se recorren comúnmente de forma recursiva, lo que hace que el manejo de estas estructuras sea especialmente adecuado para técnicas de programación como la recursión.
Existen diferentes tipos de árboles, como los árboles binarios y los árboles de búsqueda binaria, que optimizan el acceso y la inserción de elementos.
Los árboles son fundamentales en diversas aplicaciones, como bases de datos, estructuras de índices y sistemas de archivos.

🌲 Binary Tree
El Binary Tree (o Árbol Binario) es un caso particular de la estructura de datos árbol, donde cada nodo puede tener como máximo dos hijos: un hijo izquierdo y un hijo derecho.
En esta estructura, las inserciones se realizan en posiciones no dereferenciables dentro del árbol, ya que cada posición del árbol está previamente definida.
Es ampliamente utilizado en informática por su eficiencia para recuperar información, especialmente cuando se implementa como un Árbol Binario de Búsqueda (BST). En un BST, los elementos se organizan de manera que el hijo izquierdo tiene un valor menor que el nodo padre, mientras que el hijo derecho tiene un valor mayor. Esto permite optimizar las operaciones de búsqueda, inserción y eliminación.

🗺️ Map:
Un Map (o mapa) es una estructura de datos que asocia claves únicas con valores.
En este repositorio, el mapa se implementa utilizando un Vector ordenado de pares (clave-valor).
Se utiliza una función que busca la posición adecuada en el vector para insertar el nuevo par clave-valor, lo que permite que la búsqueda de una clave sea eficiente (con complejidad O(log(n)) utilizando búsqueda binaria).
Esta estructura es muy útil cuando se necesita asociar elementos con identificadores únicos, como en un diccionario.

🎨 Colaboración:
¡Siéntete libre de explorar el repositorio y contribuir con tus ideas! Si tienes sugerencias o encuentras algún error, no dudes en abrir un issue o enviar un pull request. 💻✨


