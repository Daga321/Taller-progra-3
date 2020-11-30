# Taller-progra-3

Este proyecto está desarrollado en C y tiene como fin practicar y comprender la temática de  manejo de cadenas mediante 9 distintos ejercicios los cuales podrán encontrarse en el siguiente menú 
1) Convertir en nombre Propio el contenido de la cadena
2) Contar el numero de veces que existe una palabra en una cadena
3) Encriptar cadena 
4) Desencriptar 
5) Llenar caracteres por Izquierda o por Derecha 
6) Borrar caracteres de una cadena
7) Intersección
8) Diferencia entre dos cadenas
9) Borrar caracteres Izquierda o Derecha 

A continuación se podrá dar una breve explicación de cómo es el funcionamiento de cada uno. 

Función N° 1: Para convertir la cadena ingresada en nombre/s propio/s se realizó mediante sumas con los valores ASCII de cada carácter, teniendo en cuenta una sería de condiciones ya establecidas, como por ejemplo: determinar si la palabra era mayor de dos caracteres, si está condición se cumple, obtendremos como resultado que el primer carácter sera convertido en mayúscula, por otro lado si la palabra era menor de un carácter y a su lado izquierdo y derecho se encuentra un espacio vacío, como resultado obtendremos un carácter en minúscula, estas son algunas de las condiciones. 

Funcion N° 2: Para buscar una cadena existente en una cadena superior, se utilizo otra función para  convertir las cadenas  en su totalidad a minusculas para poder realizar la comparación sin tener en cuenta las mayusculas y minusculas, luego se compara la cadena uno posicion a posicion mediante un ciclo for, y mediante un if comparar las dos cadenas .

Funcion N° 3: Efl sistema de encriptado está desarrollado en 3 partes, la primera orientada a transformar las letras a un número según el concepto de escritura de mensaje para aquellos celulares que no son smartphone, es decir mostrar el equivalente numérico a las veces que se oprimió n numero(en caso de ser mayúscula este número se convertiría en negativo para poder identificarlo después); la segunda parte es transformar todo carácter especial a su código ascii, en caso de ser un espacio en blanco se reemplaza por el número 0; por último la tercera parte fue asignado un delimitador(*) entre cada valor numérico que representaba a su respectivo carácter. Esto es posible empleando condicionales que permitieran identificar cada caso y ciclos for que permitirán recorrer la cadena que se desencripta.

Funcion N° 4: Teniendo en cuenta el sistema de encriptado explicado en la función anterior se plantearon unas pequeñas condicionales, la primera y más importante de todas fue aquella que permitiría identificar si es una letra basado en un patrón que posee el número, de ser así se transforma dicho valor mediante operaciones matemáticas en el código ascii correspondiente a la letra encriptada; la segunda fue identificar si era un espacio en blanco; la tercera identificar si era un código ascii. Una vez determinado a qué caso pertenece el código a desencriptar se procede a imprimir el carácter correspondiente; en caso de presentar condiciones que no están planteadas en el sistema de encriptación se suspenderá el proceso y mostrará un mensaje de error. 

Funcion N° 5: Mediante unas pequeñas condicionales y un ciclo for se copia y concatena el contenido respectivo(cadena y carácter a repetir) en una cadena independiente qué después será impresa mostrando n veces el carácter a repetir al costado indicado por el usuario junto a la cadena.

Función N° 6: Para esta función "Borrar un carácter de una cadena previamente ingresada", se utilizo un ciclo for para poder recorrer la cadena y mediante un condicional determinar si en alguna posición de la cadena se encontraba el carácter, de ser así se le asigna a ese espacio de la cadena un asterisco '*', para luego utilizar un método de ordenamiento (burbuja) para poder ordenar la cadena con el fin de que los asteriscos quedarán al final, finalmente se utilizo un condicional if para determinar si se encontraban asteriscos, de ser así se les asignaba un espacio vacío. 

Funcion N° 7: La función requiere de dos cadenas para  comparar que caracteres tienen en común representado por un conjunto interseccion, primero se utiliza el metodo de convertir a minusculas las dos cadenas para facilitar la comparación, luego se compara mediante  dos ciclos for para recorrer las dos cadenas y despues mediante un if y la llamada al metodo findChar permite saber si el nuevo caracter interseccion ya existe en el conjunto interseccion para no agregarlo dos veces.

Función N° 8: Para la función 8 "diferencia entre dos cadenas" fue necesario implementar dos ciclos for con el fin de recorrer las dos cadenas, esto con el fin de ir comparando los caracteres de la cadena dos en la cadena uno, en dicho caso de que exista el carácter en la cadena uno se le asignará un asterisco '*', una vez terminados los ciclos se implementó un método de ordenamiento en el cual posiciona los asteriscos al final de la cadena, finalmente con un ciclo se recorre la cadena uno final y en caso de que se encuentren posiciones con asteriscos se les asigna un espacio vacío. 

Funcion N° 9:En la función numero 9, a diferencia de las demás son necesarias tres entradas, cadenaUno, cadenaDos y izquierdaDerecha que determina por que lado de la cadena se va a borrar, en esta función a l igual que en la 2 y en la 7 se usa la función que permite convertir toda la cadena a minúsculas, para efectuar mejor la comparación,  utiliza un while que permite avanzaren posicion de las cadenas mientras los caracteres sean iguales, acción que es comparada con la función  findChar, luego dentro del while se utiliza un if para saber si borrar por derecha o por izquierda, después de este while se utiliza otro while para reorganizar la cadena resultado, finalmente imprime el resultado de  la función.
