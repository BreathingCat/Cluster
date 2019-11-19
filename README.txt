La base de datos utiliza el servidor MYSQL desplegado en una máquina de amazon
remota. Para conectarse a ella, el servidor web utiliza la ipv4 privada
de la subred en la que se encuentran las 2 maquinas.

Para realizar la conexion con el servidor MYSQL, se ha creado un usuario
administrador con todos permisos.

La base de datos en la que se almacenan los usuarios y las contrasenias consta
de una tabla USERS que la forman 2 atributos:

	-name VARCHAR(20), almacena el nombre de usuario
	-password VARCHAR(20), se almacena la contrasenia cifrada
