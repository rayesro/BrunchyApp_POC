# Aplicación para programa de lealtad

## Contexto

Un programa de lealtad o programa de fidelización es una estrategia para aumentar las ventas de un negocio, cuyo propósito es premiar el comportamiento de compra de los clientes, lo que lleva a producir en ellos un sentido de lealtad y fidelidad hacia la marca. 

Dentro de las ventajas que encontramos en implementar un programa de lealtad son:
- Primeramente, estimular en los clientes la compra o el consumo de un producto o servicio.
- En segunda, permite generar información respecto al consumo de los clientes lo cual a su vez favorece:
  - Conocer a nuestro cliente.
  - Segmentar los clientes.
  - Definir estrategias en base a la generación de dicha información.


Hay diversos sistemas que se pueden aplicar para un programa de lealtad, uno de los más comunes es el sistema de puntos, el cual en básicamente funciona así: 
1. El cliente hace la compra y obtiene puntos. 
2. La cantidad depende que obtiene el cliente del monto o total del consumo. 
3. El cliente puede canjear o redimir sus puntos por alguna recompensa.

Normalmente, los puntos tienen fecha de caducidad (por ejemplo: de 5 días a 3 semanas) para estimular a los clientes a comprar para no perderlos; o un sistema de niveles en el cual los miembros más recientes reciben bonificaciones pequeñas, ya sea cantidad de puntos, monto de cashback o un descuento personalizado. Al aumentar el importe total de compras, el cliente pasa a un nivel más alto con el respectivo aumento de descuentos, cantidad de puntos, etc.

## Nuestro cliente

El restaurante BrunchyTime es un restaurante que ofrece comida TexMex, tiene un par de años en el mercado y durante este tiempo ha tenido muy buen recibimiento con sus clientes, muchos de ellos acuden con cierta frecuencia al restaurante y ordenan comida a domicilio.

### Sistema actual

Sabiendo esto, el dueño de BrunchyTime, mejor conocido como "Don Brunch", ha implementado un sistema de lealtad. Su sistema consta de una serie de tarjetas que cuentan con 10 espacios para 10 sellos; cada que un cliente asiste a una de las sucursales, el o la cajera le pregunta al cliente si ya cuenta con su BrunchyCard y le ofrece una en caso de no contar con una.
Después de cada compra en cualquier sucursal, la cajera sella la BrunchyCard del cliente sí la compra fue igual a mayor a 150 MXN.
Cuando el cliente llena la tarjeta de sellos, es acreedor a un platillo gratis y se le otorga una nueva BrunchyCard.

Aunque ha dado buenos resultados este sistema, Don Brunch ha notado algunas desventajas, por ejemplo:
* Al ser una tarjeta física, hay ocasiones en las que el cliente pierde la tarjeta y la única forma de validar los sellos que tenía la BrunchyCard es pedirle al cliente alguna foto reciente de la tarjeta.
* La solución anterior es una solución a medias, ya que hay que confiar en que el cliente este mostrando una foto que el mismo haya tomado y no sea una foto de una BrunchyCard más llena de sellos.
* Los sellos solo se pueden poner de forma física, es decir, si el cliente pide comida a domicilio no hay forma de hacerle sellarle la BrunchyCard.
* No importa la cantidad de consumo, el sello aplica si consumes $150 o $800 pesos, no hay una recompensa mayor por mayor consumo.
* La BrunchyCard no tiene vigencia: no hay un incentivo para consumir más o perder los sellos porque no hay una caducidad como tal.
* No hay un registro de la información de los sellos, es decir, solo existe un sello como prueba de una compra en alguna sucursal, pero no se tiene registro de cuál fue el monto de la compra de algún sello, cuando se realizó, en que sucursal se hizo la compra.
* No hay un registro de cuantas tarjetas ha canjeado un cliente.
* Solo hay una promoción o beneficio que se puede obtener al canjear la BrunchyCard una vez llenado los sellos.

### Solicitud de nuevo sistema

Gracias al networking que hemos hecho, tuvimos la oportunidad de conocer y tener una junta con el Don Brunch en la cual nos presentamos, hablamos de nuestra experiencia como ingenieros de software, y nos platicó acerca de su negocio y su sistema actual. 
Después de una larga charla en la que le planteamos los beneficios de llevar su sistema de lealtad a una aplicación, nos contrató para desarrollar una aplicación que le ayude a administrar su programa de lealtad actual además de incorporar mejoras en el mismo.
Sabemos que los negocios cambian constantemente por diversos factores, y eso mismo le hicimos saber eso a Don Brunch, que nuestra aplicación le permitirá tener un mayor control sobre su proceso actual y la robustez de nuestro sistema permitirá adicionar nuevas funcionalidades en el futuro, pero primero necesitamos partir de unos requerimientos base los cuales necesitamos definirlos junto con Don Brunch para tener claras las expectativas de la aplicación.

Después de varias semanas de entablar comunicación con el dueño, en la cual estuvimos acordando cuales son las necesidades principales por cubrir en la aplicación, y luego de la resolución de algunas dudas que tuvimos respecto al modelo y reglas de su negocio, así como proponer interfaces de usuario, llegamos a una serie de requisitos para esta primera etapa. Además, Don Brunch ya tenía nombre para la aplicación: la BrunchyApp.

# BrunchyApp

Junto con Don Brunch, establecimos la serie de funcionalidades que debe de tener esta primera etapa, pero antes de definirlas necesitamos saber el contexto de los actores que intervienen en el sistema actual de BrunchyTime.


## Actores o entidades

Para efectos de tener una mejor comunicación con Don Brunch, y saber ambas partes de lo que se está hablando, se estableció la lista de actores u entidades que interactúan en la aplicación. Tener esta información nos ayudará a evitar malos entendidos entre ambas partes, a agilizar el desarrollo y que el contexto de las reglas de negocio del BruncyTime se permeé sin complicaciones en nuestro equipo de desarrollo.

| Actor            | Descripción                                                                                                        |
| ---------------- | ------------------------------------------------------------------------------------------------------------------ |
| Usuario          | Un usuario es cualquier empleado de BrunchyTime que puede hacer uso de esta aplicación                             |
| Cliente          | Un cliente es una persona que asiste o llama al restaurante para ordenar comida                                    |
| Sucursal         | Representa un restaurante físico                                                                                   |
| BrunchyPunto     | Representa un punto obtenido por una compra realizada (1 BrunchyPunto por cada $10 MXN)                            |
| BrunchyPromocion | Representa una promoción que es un beneficio que se otorga al cliente luego de cierta cantidad de puntos obtenidos |

Las especificaciones de cada entidad se definen más abajo en este documento.


# Fases de desarrollo

Junto con Don Brunch, acordamos que el desarrollo de la primera etapa quedará dividido en 3 fases:

## Fase 1 - Programación de servicios de BrunchyApp (usando "dummy data")

Es esta primera fase del desarrollo, consistirá en desarrollar toda la lógica de servicios de la BrunchyApp, usando datos de prueba, en la cual se puedan simular los procesos que tendrá la BrunchyApp pero a través de una aplicación de línea de comandos (aplicación de consola). 
Al finalizar esta fase, tendremos todos los servicios que darán soporte a la BrunchyApp, los cuales permitirán que se pueda visualizar la información en diversos módulos y pantallas del sistema. 
Las condiciones de esta fase son:
- Todos los datos de las entidades serán información de prueba o "dummy data", ya que aún no se cuenta con los procesos para gestionar esa información. 
- El proceso de canje se podrá simular en la aplicación, de tal forma que se podrá visualizar el proceso una vez terminada la BrunchyApp, pero no habrá registro del canje.
- La simulación del proceso de inicio se sesión se hará con la "dummy data". Hay que considerar que un usuario (administrador o cajero) puede ingresar a cualquier sucursal, es decir, un empleado se puede mover a trabajar a cualquier sucursal).
- La información tanto de usuarios, clientes, sucursales, brunchypuntos y brunchypromos podrá ser vista desde las pantallas de listados.
- Si el tiempo lo permite, la "dummy data" puede provenir de una base de datos.

## Fase 2 - Gestión de información

El entregable de la segunda fase consiste es la versión inicial de la interfaz de usuario la cual permita gestionar la información (dar de alta, dar baja y modificar registros), realizar el proceso de de canje de puntos, el inicio de sesión e identificación del usuario, y el registro en una base de datos de la información.
Las condiciones de esta fase son:
- La aplicación debe tener una interfaz visual a través de la cual se pueda interactuar (ya no se permite una aplicación de línea de comandos).
- La información deberá poderse registrar en una base de datos (ya no será permitido el uso de "dummy data"). 
- El proceso de alta de todas las entidades es requerido, las bajas y modificaciones son opcionales.
- Las pantallas requeridas son todas las que intervienen en el proceso de ingreso al sistema, alta de registros, listados y canje de puntos. El resto de las pantallas son opcionales.
- Se debe distinguir que usuario está utilizando la aplicación.
- Se requiere que el proceso de canje de puntos este presente en esta fase, y que su información se guarde en base de datos.
- Las validaciones de la información son opcionales.

## Fase 3 - Permisos y reportes

Para la última fase, se desarrollarán las validaciones de la información que se registra, además de complementar con la generación de reportes y la restricción de funciones por tipo de usuario.

*Un wizard o asistente por pasos es un tipo de interfaz de usuario el cual consta de una serie de ventanas, en las cuales se le presenta al usuario un formulario por ventana y le solicitan ingresar cierto tipo de información antes de proceder al siguiente paso hasta llegar al final de las ventanas.*

Cada reporte consta de 2 partes, una obligatoria y una opcional:
- Debe tener una pantalla donde se puede visualizar la información del reporte
- Se puede tener una opción/botón dentro de dicha pantalla para generar un archivo CSV para su uso posterior en Excel.

Los reportes por generar son:
1. Reporte de los clientes con puntos ordenados de mayor cantidad de puntos a menor cantidad.
2. Reporte de las BrunchyPromocion canjeadas ordenadas de mayorer veces canjeada a menor cantidad de canjes.
3. Reporte de los clientes con monto total de compras hechas de mayor a menor monto.
  
Las condiciones de esta fase son:
- Toda la información se deberá guardar en una base de datos o archivo.
- Los procesos de alta, baja y modificación son requeridos.
- Todas las pantallas de alta, baja y modificación de registros son requeridos.
- El uso de fotografías de los usuarios es opcional.
- Al menos un reporte es requerido, cualquiera, los otros son opcionales.
- Las validaciones de la información en las pantallas de alta y modificación de registros son requeridas.
- La aplicación debe poder cargar los datos desde la base de datos automáticamente, y tener una función para guardar los datos manualmente de forma opcional.

## QA - Evaluación

Para la revisión de cada una de las fases establecimos un sencillo sistema de puntaje, de 0 a 100, donde hay puntos obligatorios y puntos requeridos, debemos completar los requeridos por lo menos para poder tener producto mínimo viable.

### Evaluación de fase 1
| Tipo      | Descripción                                                     | Puntos |
| --------- | --------------------------------------------------------------- | ------ |
| Requerido | Inicio de sesión                                                | 5      |
| Requerido | Simulación de captura de Brunchypuntos por venta                | 40     |
| Requerido | Dummy data de 10 registros de cada entidad                      | 5      |
| Requerido | Pantallas de listado, alta y modificación de cliente            | 10     |
| Opcional  | Pantallas de listado, alta y modificación de BrunchyPromo       | 10     |
| Opcional  | Pantallas de listado, alta, baja y modificación de usuario      | 10     |
| Opcional  | Pantallas de listado, alta y modificación de sucursales         | 10     |
| Opcional  | Lectura y escritura de clientes en archivo binario              | 10     |

### Evaluación de fase 2
| Tipo      | Descripción                                                                                | Puntos |
| --------- | ------------------------------------------------------------------------------------------ | ------ |
| Requerido | Lectura y escritura de clientes en archivo binario                                         | 15     |
| Requerido | Pantalla funcional de captura de Brunchypuntos por venta                                   | 25     |
| Requerido | Inicio de sesión funcional                                                                 | 5      |
| Requerido | Identificación del usuario en sesión                                                       | 5      |
| Requerido | Pantallas funcionales de alta de clientes, usuarios, sucursales y BrunchyPromos            | 15     |
| Opcional  | Pantallas no funcionales de listado de clientes, usuarios, sucursales y BrunchyPromos      | 10     |
| Opcional  | Pantallas no funcionales de baja usuarios                                                  | 5      |
| Opcional  | Pantallas no funcionales de modificación de clientes, usuarios, sucursales y BrunchyPromos | 10     |
| Opcional  | Validación en pantallas de alta de clientes, usuarios, sucursales y BrunchyPromos          | 10     |


### Evaluación de fase 3
| Tipo      | Descripción                                                                             | Puntos |
| --------- | --------------------------------------------------------------------------------------- | ------ |
| Requerido | Validación en pantallas de alta y modificación de clientes                              | 5      |
| Requerido | Reporte de clientes con puntos                                                          | 10     |
| Requerido | Pantallas funcionales de listado de clientes, usuarios, sucursales y BrunchyPromos      | 5      |
| Requerido | Pantallas funcionales de baja de clientes, usuarios, sucursales y BrunchyPromos         | 5      |
| Requerido | Pantallas funcionales de modificacion de clientes, usuarios, sucursales y BrunchyPromos | 5      |
| Requerido | Restricción de pantallas al cajero por permisos                                         | 15     |
| Opcional  | Validación en pantallas de alta y modificación de Usuarios                              | 5      |
| Opcional  | Validación en pantallas de alta y modificación de sucursales                            | 5      |
| Opcional  | Validación en pantallas de alta y modificación de BrunchyPromos                         | 5      |
| Opcional  | Reporte de clientes con monto total de compras                                          | 10     |
| Opcional  | Reporte de BrunchyPromos                                                                | 10     |
| Opcional  | Uso de fotos en la identificación del usuario en sesión                                 | 10     |
| Opcional  | Exportar a CSV el reporte de clientes con monto total de compras                        | 5      |
| Opcional  | Exportar a CSV el reporte de BrunchyPromos                                              | 5      |
| Opcional  | Exportar a CSV el reporte de clientes con puntos                                        | 5      |


# Anexos

## Especificaciones de las entidades

Para el desarrollo de la funcionalidad de alta y modificación de información, hay una serie de datos requeridos que deben existir para poder generar un registro de la entidad en cuestión. Si alguno de los dichos campos requeridos no está presente se debe mostrar un error de validación al usuario.
Por otra parte, los campos no requeridos u opcionales se pueden omitir al momento de dar de alta o modificar una entidad.

*NOTA*

_A continuación se definen las propiedades necesarias para administrar la información de la aplicación, mas no se definen las entidades y/o propiedades necesarias para la generación de reportes. Dichas definiciones quedan a discreción del programador._


### Usuario

| Campo             | Reglas                                                                                                                                                                                           | Requerido |
| ----------------- | --------------------------------------------------------------                                                                                                                                   | --------- |
| Nombre completo   | Solo caracteres alfabéticos y espacios, mínimo 5 y máximo 50                                                                                                                                     | Si        |
| Nombre de usuario | Solo caracteres alfanuméricos, mínimo 5 y máximo 20                                                                                                                                              | Si        |
| Alias del usuario | Solo se permite caracteres alfanuméricos, mínimo 3 y máximo 10                                                                                                                                   | No        |
| Contraseña        | Mínimo 3 y máximo 10 caracteres, se debe solicitar una letra, un número y un carácter especial como mínimo, si no cuenta con estos requisitos entonces será considerada una contraseña inválida. | Si        |
| Tipo de usuario   | Para este campo puede ser un listado, radio buttons pero no campos de textos, ya que se le debe indicar al usuario los tipos disponibles sin dejar que los edite                                 | Si        |
| Sucursal          | Para este campo puede ser un listado con las sucursales disponibles. Es la sucursal a la que se asigna al empleado                                                                                                                              | No        |
| Foto              | Cargar una imagen de perfil para el usuario                                                                                                                                                      | No        |
*El nombre ni el tipo de usuario no se puede editar una vez dado de alta.*

### Cliente

| Campo    | Reglas                                                                                          | Requerido |
| -------- | ---------------------------------------------------------------------------------------------   | --------- |
| Nombre   | Solo caracteres alfabéticos y espacios, mínimo 5 y máximo 50                                    | Si        |
| Alias    | Solo caracteres alfabéticos y espacios, mínimo 5 y máximo 15                                    | No        |
| Telefono | Solo caracteres numéricos, de exactamente 10 caracteres                                         | No        |
| Email    | Validación de formato email, mínimo 5 y máximo 25                                               | Si        |
| Sucursal | Este campo debe estar prellenado con el mismo comercio del usuario logeado, es de solo lectura. | Si        |
| BrunchyPuntos | Se le asigna valor automáticamente, es de solo lectura.                         | Si        |
| Fecha    | Este campo debe estar prellenado con la fecha del sistema, es de solo lectura.                  | Si        |

*La sucursal del cliente no se puede editar, ya que este dato refleja donde fue dado de alta.*
*Los BrunchyPuntos no se pueden editar ni dar de alta ya que se calculan de forma automática.*

### BrunchyPromos

| Campo                   | Reglas                                                                                                        | Requerido |
| ----------------------- | ------------------------------------------------------------------------------------------------------------- | --------- |
| Nombre                  | Solo caracteres alfabéticos y espacios, mínimo 5 y máximo 50                                                  | Si        |
| Punto requerido         | Solo números no negativos                                                                                     | Si        |
| Porcentaje de descuento | Cantidad decimal, mayor a 0 y menor a 100                                                                     | Si        |
| Estatus                 | Mostrar un listbox, un par de radio buttons o un checkbox para indicar si esta activa o inactiva la promoción | Si        |

*El nombre de las BrunchyPromos no se puede editar.*

### Sucursales

| Campo                   | Reglas                                                                                                        | Requerido |
| ----------------------- | ------------------------------------------------------------------------------------------------------------- | --------- |
| Nombre                  | Solo caracteres alfabéticos y espacios, mínimo 5 y máximo 50                                                  | Si        |
| Dirección               | Texto de cualquier longitud                                                                                   | No        |

*El nombre de las sucursales no se puede editar.*

## Permisos de pantallas para tipos de usuario

Los permisos que tiene cada tipo de usuario se asignan de la siguiente forma:

| Permiso                       | Administrador | Cajero |
| ----------------------------- | ------------- | ------ |
| Alta de clientes              | ✔             | ✔      |
| Modificación de clientes      | ✔             | ✔      |
| Listado de clientes           | ✔             | ✔      |
| --                            | --            | --     |
| Alta de usuarios              | ✔             |
| Baja de usuarios              | ✔             |
| Modificación de usuarios      | ✔             |
| Listado de usuarios           | ✔             | ✔      |
| --                            | --            | --     |
| Alta de sucursales            | ✔             |
| Modificación de sucursales    | ✔             |
| Listado de sucursales         | ✔             | ✔      |
| --                            | --            | --     |
| Alta de BrunchyPromos         | ✔             |
| Modificación de BrunchyPromos | ✔             |
| Listado de BrunchyPromos      | ✔             | ✔      |
| --                            | --            | --     |
| Canje de BrunchyPuntos        | ✔             | ✔      |
| --                            | --            | --     |
| Reportes                      | ✔             |



## Mockups de aplicación 

![Diseño de pantallas](/Mockups_BrunchyApp.png)
