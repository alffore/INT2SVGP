<?php

//codigo básico para generar el script "estático base de Mapael"

//print_r($argv);
echo "Creación del Script de Mapael\n";

$archivo_sal = $argv[1] . $argv[2] . ".js";

//definimos array de variables a sustituir
$aV = [];
$aV["CE"] = $argv[2];
$aV["DIMX"] = $argv[3];
$aV["DIMY"] = $argv[4];

//recuperamos los PATHS

$alineas = file($argv[1] . $argv[2] . ".jsvg");

$aV["PATHS"] = implode(",", $alineas);


//recuperamos el buffer del modelo
$buffer = file_get_contents("modelo.js.txt");


//realizamos las sustituciones
foreach ($aV as $k => $v) {

    $buffer = sustituyeCad($buffer, $k, $v);
             
}

//escribimos archivo
escribeBuffer($buffer, $archivo_sal);

/**
 * Funcion que sustituye la variable por su valor correspondiente
 * @param type $buffer
 * @param type $variable
 * @param type $valor
 * @return type
 */
function sustituyeCad($buffer, $variable, $valor) {

    return str_replace("%%" . $variable . "%%", $valor, $buffer);
}

/**
 * Funcion que escribe el archivo con los resultados 
 * @param type $buffer
 * @param type $archivo
 */
function escribeBuffer($buffer, $archivo) {

    $fh = fopen($archivo, "w");

    fwrite($fh, $buffer);

    fclose($fh);
}
